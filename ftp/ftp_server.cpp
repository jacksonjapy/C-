#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void sendFile(int clientSocket, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: File not found." << std::endl;
        send(clientSocket, "File not found", 14, 0);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (!file.eof()) {
        file.read(buffer, BUFFER_SIZE);
        send(clientSocket, buffer, file.gcount(), 0);
    }

    file.close();
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE] = {0};

    std::string ipAddress;
    int port;

    std::cout << "Enter server IP address: ";
    std::cin >> ipAddress;

    // Check if IP address is valid
    if (inet_pton(AF_INET, ipAddress.c_str(), &serverAddr.sin_addr) <= 0) {
        std::cerr << "Invalid IP address" << std::endl;
        return -1;
    }

    std::cout << "Enter server port number: ";
    std::cin >> port;

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ipAddress.c_str());
    serverAddr.sin_port = htons(port);

    // Bind socket to port
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return -1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return -1;
    }

    std::cout << "Server listening on " << ipAddress << ":" << port << std::endl;

    // Accept incoming connection
    if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrLen)) < 0) {
        std::cerr << "Accept failed" << std::endl;
        return -1;
    }

    std::cout << "Connection accepted from " << inet_ntoa(clientAddr.sin_addr) << ":" << ntohs(clientAddr.sin_port) << std::endl;

    // Receive filename from client
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    std::string filename(buffer);

    // Send file to client
    sendFile(clientSocket, filename);

    close(clientSocket);
    close(serverSocket);

    return 0;
}
