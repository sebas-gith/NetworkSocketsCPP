# NetworkSocketsCPP
Pequeño proyecto de comunicación cliente-servidor usando Winsock en C++.

## 📄 Descripción
Este proyecto es una implementación básica de un **servidor y cliente TCP** utilizando **sockets en C++** con la librería **Winsock** (Windows Sockets API).  
El objetivo principal es establecer una conexión entre dos aplicaciones, permitir el envío de mensajes del cliente al servidor, y que el servidor pueda responder de vuelta.

Este proyecto sirve como práctica inicial para comprender cómo funcionan las comunicaciones en red a nivel de programación.

---

## 🎯 Objetivo
- 📚 **Aprender** los fundamentos de la programación de redes con sockets en C++.
- 🛠️ **Implementar** un servidor TCP que escuche conexiones entrantes en un puerto específico.
- 🤝 **Crear** un cliente TCP que se conecte al servidor utilizando su dirección IP y puerto.
- ✉️ **Enviar y recibir datos** entre el servidor y el cliente.
- 🧠 **Practicar** el uso de funciones como `socket()`, `bind()`, `listen()`, `accept()`, `connect()`, `send()`, y `recv()` usando Winsock en Windows.

---

## ⚙️ ¿Qué hace el proyecto?

- El **servidor**:
  - 🖥️ Inicializa Winsock.
  - 🛠️ Crea un socket TCP/IP.
  - 🔗 Se vincula a un puerto (`8080`).
  - 👂 Escucha conexiones entrantes.
  - ✅ Acepta la conexión de un cliente.
  - 📥 Recibe un mensaje del cliente.
  - 📤 Responde con un mensaje de bienvenida.

- El **cliente**:
  - 🖥️ Inicializa Winsock.
  - 🛠️ Crea un socket TCP/IP.
  - 🔗 Se conecta al servidor (`127.0.0.1:8080`).
  - 📤 Envía un mensaje inicial al servidor.
  - 📥 Espera y muestra la respuesta del servidor.

---

## 🧰 Requisitos
- 🖥️ Sistema operativo **Windows**.
- 🛠️ Compilador compatible con C++ (por ejemplo, Visual Studio).
- 📚 Tener instalada la librería **Winsock** (ya viene incluida en Windows).

---

## 🏃‍♂️ Cómo ejecutar

1. ⚡ Compilar y ejecutar primero el **servidor**.
2. ⚡ Luego, compilar y ejecutar el **cliente**.
3. 🎉 Verás que se establece la conexión y ambos programas intercambian mensajes.

---

## 📌 Nota
Recuerda ejecutar el servidor **antes** que el cliente, ya que el cliente necesita que el servidor esté disponible para conectarse.

---
