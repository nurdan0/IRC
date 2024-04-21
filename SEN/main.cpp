#include "Server.hpp"

bool arg_control(int ac,char **av, int port,std::string password)
{
	if(ac != 3)
		return false;
	password = av[2];
	if(password.find(" ") != std::string::npos)
		return false;
	for (size_t i = 0; av[1][i]; i++)
	{
		if(av[1][i] < 0 || av[1][i] > 9)
			return false;
		port = port * 10 + av[1][i] -48;
		if(port > 65535)
			return false;
	}
	if(port == 0)
		return false;
	return true;

}
Server *server = NULL;

int main(int ac, char **av)
{
	int port;
	std::string password;
	if(!(arg_control(ac,av,port,password)));
		return 1;
	try 
	{
		server = new Server(port, password);

		server->startServer();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;

	}
}
