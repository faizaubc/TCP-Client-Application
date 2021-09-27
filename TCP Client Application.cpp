// TCP Client Application.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 
	//IP Address of the server
	string ipAddress = "127.0.0.1"; 

	//Listening port # on the server
	int port = 22;

	//Initialize Winsock 
	WSADATA data;
	WORD ver = MAKEWORD(2, 2);//grab the version number of the winsock
	int wsResult = WSAStartup(ver, &data);//then start the winsock 
	if (wsResult != 0)
	{
		cerr << "Can't start winsock, Err # " << wsResult << endl;
		return;
	}

	//Winsock is a programming interface and the supporting program that handles 
	//input/output requests for Internet applications in a Windows operating system.
	//create a sockeet 
	//send data out to the server
	//AF_INET == internet style address family
	//type of socket is sock_stream
	//protocol is zero
	//endpoint for sending and receiving data across the network is socket 
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	//check if socket is valid
	if (sock == INVALID_SOCKET)
	{
		cerr << "Can't create socket, Err # " << WSAGetLastError() << endl;
	}
	
	//Fill in a hint structure
	//hint structure will tell the 
	//will tell win sock what server and what port to connect to
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port); //htons host to network short makes it portable
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);//
	//Connect to server

	//Do -while loop to send and receive data

	//gracefully close down everything 




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
