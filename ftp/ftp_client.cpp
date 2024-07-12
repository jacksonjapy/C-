#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void receiveFile(int serverSocket, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to create file." << std::endl;
        return;
    }

    char buffer[BUFFER_SIZE];
    int bytesRead;
    while ((bytesRead = recv(serverSocket, buffer, BUFFER_SIZE, 0)) > 0) {
        file.write(buffer, bytesRead);
    }

    file.close();
}

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
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
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ipAddress.c_str(), &serverAddr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }

    // Connect to server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }

    std::cout << "Connected to server" << std::endl;

    // Send filename to server
    std::string filename;
    std::cout << "Enter filename to request: ";
    std::getline(std::cin, filename);
    send(clientSocket, filename.c_str(), filename.size(), 0);

    // Receive file from server
    receiveFile(clientSocket, filename);

    close(clientSocket);

    return 0;
}
