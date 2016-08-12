#include "server.h"
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include "libft.h"

static int	ft_server_check_read_clients(t_server *server, int clients,
		fd_set *fdset)
{
	if (FD_ISSET(server->clients[clients], fdset))
	{
		if ((ft_server_receive_message(server, server->clients[clients]))
				== -1)
		{
			ft_server_disconnect_client(server, server->clients[clients],
					clients);
		}
	}
	return (1);
}

int			ft_server_check_read_sockets(t_server *server)
{
	int				ret;
	int				clients;
	fd_set			fdset;

	clients = 0;
	FD_ZERO(&fdset);
	FD_SET(server->fd_socket, &fdset);
	while (clients < server->nbr_clients)
		FD_SET(server->clients[clients++], &fdset);
	if ((ret = select(server->max + 1, &fdset, 0, 0, &server->timeout)) == -1)
	{
		ft_putendl("erreur");
		return (ret);
	}
	if (FD_ISSET(server->fd_socket, &fdset))
	{
		if ((ret = ft_accept_connection(server)) != -1)
			FD_SET(ret, &fdset);
	}
	clients = 0;
	while (clients < server->nbr_clients)
		ft_server_check_read_clients(server, clients++, &fdset);
	return (1);
}
