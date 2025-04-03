# Minitalk42

## 📌 Overview
Minitalk42 is a project from 42 School that focuses on implementing a simple communication protocol between a client and a server using signals in C. The goal of the project is to send a message from the client to the server using the Unix signal system, providing an efficient way of communication between processes.

## ✨ Features
- Client and server communication via Unix signals.
- Messages are transmitted as a series of bits, encoded in ASCII.
- The client sends characters bit-by-bit to the server, and the server decodes and displays the message.
- The client and server are written in C, using signal-based communication.
- The project is designed to understand inter-process communication and signals in Unix-based systems.

## 📂 File Structure

The project is organized into the following files:

### 🏗 Core Files  
- **`Makefile`** - The Makefile to compile the project  
- **`client`** - Executable for the client program  
- **`client.c`** - Client source code  
- **`server`** - Executable for the server program  
- **`server.c`** - Server source code  

### 🛠 Configuration & Miscellaneous  
- **`.vscode`** - Visual Studio Code configuration folder  
- **`.DS_Store`** - MacOS system file (can be ignored)  

### 🔧 Custom Implementations  
- **`ft_printf`** - Custom printf implementation (if used)

## 🛠️ Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/Kharbachzoubair/minitalk42.git
   ```

   
