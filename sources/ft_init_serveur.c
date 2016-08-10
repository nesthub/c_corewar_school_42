#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "libft.h"
#include "serveur.h"


void	ft_init_server(t_server *server)
{
	ft_bzero(&server, sizeof(server));
}
/*
** A voir si ne pas utiliser la meme fonction que client.....
*/

int		ft_socket_serveur(int bloquant, t_server *server)
{
	int opt;

	opt = 1;

	if ((server->fd_socket = socket(PF_INET, SOCK_STREAM, 6)) == -1)
		return (-1);
	if (bloquant == 1)
	{
		if ((ioctl(server->fd_socket, FIONBIO, &opt)) == -1)
			return (-1);
	}
	return (server->fd_socket);
}

int		ft_init_serveur(char *ip, char *port, t_server *server)
{
	server->address.sin_family = AF_INET;
	server->address.sin_addr.s_addr = inet_addr(ip);
	server->address.sin_port = htons(ft_atoi(port));
	if ((bind(server->fd_socket, (struct sockaddr *) &server->address,
					sizeof(server->address))) == -1)
			return (-1);
	if ((listen(server->fd_socket, MAX_CONNECT)) == -1)
		return (-1);
	return (1);

}

int		ft_accept_connection(t_server *server)
{
	unsigned int len;
	int			socket;

	len = sizeof(server->address);
	if ((socket = accept(server->fd_socket, (struct sockaddr *) &server->address,
				&len))  == -1)
		return (-1);
	server->clients[server->nbr_clients] = socket;
	server->nbr_clients++;
	return (1);
}
