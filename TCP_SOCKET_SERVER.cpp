// Servidor
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
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        cout << "Error al crear el socket." << endl;
        WSACleanup();
        return 1;
    }

    // Configurar la dirección del servidor
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Vincular el socket a la dirección del servidor
    result = bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if (result == SOCKET_ERROR) {
        cout << "Error al vincular el socket." << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Escuchar conexiones entrantes
    result = listen(serverSocket, SOMAXCONN);
    if (result == SOCKET_ERROR) {
        cout << "Error al escuchar." << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Servidor escuchando en puerto 8080..." << endl;

    // Aceptar la conexión de un cliente
    SOCKET clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) {
        cout << "Error al aceptar la conexión." << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    cout << "Cliente conectado." << endl;

    // Recibir datos del cliente
    char buffer[1024];
    int bytesReceived;
    while ((bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
        // Imprimir los datos recibidos
        cout << "Datos recibidos: " << string(buffer, bytesReceived) << endl;

        // Responder al cliente
        string message = "Hola desde el servidor!";
        send(clientSocket, message.c_str(), message.size(), 0);
    }

    // Cerrar sockets
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    system("pause");
    return 0;
}
