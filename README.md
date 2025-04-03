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
2. Navigate to the project directory:
   ```bash
   cd minitalk42
   ```
3. Compile the project using the Makefile:
   ```bash
   make
   ```

## 🖥️ Usage

### 1. Run the Server
First, you need to start the server. Open a terminal window and run the server:
```bash
./server
```
The server will listen for incoming signals from the client.

### 2. Run the Client
In another terminal window, run the client and pass the server's process ID (PID) and the message you want to send:

```bash
./client <server_pid> "Hello, World!"
```
The client will send the message bit-by-bit to the server using signals. The server will decode the message and display it.

## 🔧 How It Works
The client sends each character in the message as a series of bits, with each bit sent via a signal (SIGUSR1 for 0 and SIGUSR2 for 1).

The server decodes the incoming signals and reconstructs the original message.

The client and server communicate through signals in a loop, with each signal representing one bit of a character.

## ❓ How to Contribute
If you'd like to contribute to the project:

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature-name
   ```
   
## ❓ How to Contribute
If you'd like to contribute to the project:

1. Fork the repository.

2. Create a new branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -am 'Add new feature'
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Open a pull request.

## 💡 Future Improvements
- Add error handling for invalid PID inputs.
- Enhance the server's ability to handle multiple clients.

## 👨‍💻 Author
Kharbachzoubair  
42 School



