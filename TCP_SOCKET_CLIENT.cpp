// Cliente
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsaData;

    // Inicializar Winsock
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        cout << "Error al inicializar Winsock." << endl;
        return 1;
    }
    cout << "Winsock inicializado correctamente." << endl;

    // Crear socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        cout << "Error al crear el socket." << endl;
        WSACleanup();
        return 1;
    }

    // Configuración del servidor
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    result = inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
    if (result <= 0) {
        cout << "Error en inet_pton()." << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Intentar conectar al servidor
    result = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (result == SOCKET_ERROR) {
        cout << "Error al conectar al servidor." << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }
    cout << "Conectado al servidor." << endl;

    // Enviar un mensaje al servidor
    string message = "Hola desde el cliente!";
    send(clientSocket, message.c_str(), message.size(), 0);

    // Recibir la respuesta del servidor
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0) {
        cout << "Respuesta del servidor: " << string(buffer, bytesReceived) << endl;
    }

    // Limpiar y cerrar
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
