#include "Server.hpp"
Server::Server() 
{
}

Server::~Server(void) 
{
}

void Server::startServer()
{
	
}
void Server::initServer(int port, std::string password)
{
	_port = port;
	_password = password;
	if((_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		throw std::runtime_error ("hataaa");
	int optionValue = 1;//1 olmasının nedeniSO_REUSEADDR seçeneğini etkinleştirmek içindir ve bu, sunucunun aynı adresi hemen tekrar kullanmasına izin verir.
	if(setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &optionValue, sizeof(optionValue)) == -1)
		throw std::runtime_error("hatayım ben");

	_socketAddr.sin_family = AF_INET;
	_socketAddr.sin_port = htons(_port);
	_socketAddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(_socket,(struct sockaddr *)&_socketAddr, sizeof(_socketAddr)) == -1)
		throw std::runtime_error("benbir hatayım");
	
	if(listen(_socket, maxClient) == -1)
		throw std::runtime_error("ben listen hatasıyım");
	
	std::cout << "Server listening on port " << _port << std::endl;

	_pollFd[0].fd = _socket;
	_pollFd[0].events = POLLIN;
}