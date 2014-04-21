/*
** myirc.h for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Fri Apr 18 13:52:04 2014 pinon
** Last update Mon Apr 21 23:35:01 2014 guerot_a
*/

#ifndef		MYIRC_H
# define	MYIRC_H

# include "dependencies.h"
# include "constants.h"
# include "list.h"
# include "request.h"
# include "server.h"
# include "channel.h"
# include "socketset.h"
# include "sockstream.h"
# include "utils.h"
# include "user.h"

int		str_match(char *str, char *name);
int		find_empty_unregistered(server_t* server);
sockstream_t*	new_sockstream(int socket);
void		parse_args(char **tab, char *str);
int		parse_request(sockstream_t* stream, request_t* request);
int		available_name(channel_t* channel, char* name);
void		manage_server_datas(server_t* server);
sockstream_t*	create_sockstream(int socket);
void		recv_sockstream(sockstream_t* sstream);
void		send_sockstream(sockstream_t* sstream);
void		manage_nickname_unregistered(request_t* request);
void		manage_list_unregistered(request_t* request);
void		manage_join_unregistered(request_t* request);
void		manage_part_unregistered(request_t* request);
void		manage_users_unregistered(request_t* request);
void		manage_msg_unregistered(request_t* request);
void		manage_msg_all_unregistered(request_t* request);
void		manage_send_file_unregistered(request_t* request);
void		manage_accept_file_unregistered(request_t* request);
void		manage_request_unregistered(request_t* request);
channel_t*	new_channel(char* channel_name);
void		user_join_channel(server_t* server,
				  channel_t* channel,
				  list_elm_t* e_user);
void		add_channel(server_t* server, char* channel_name);
list_t*		new_list();
void		list_push_back(list_t* list, void* data);
void		list_push_front(list_t* list, void* data);
void		list_pop_back(list_t* list);
void		list_pop_front(list_t* list);
void		list_erase(list_t* list, list_elm_t* elm);
void		refresh_socket_sets(server_t* server,
				    socketset_t* sets);
void		manage_io_sockets_unregistered(server_t* server,
					       socketset_t* sets);
void		manage_io_sockets_listen(server_t* server,
					 socketset_t* sets);
void		manage_io_sockets(server_t* server,
				  socketset_t* sets);
void		init_user_list(server_t* server);
void		init_channel_list(server_t* server);
void		init_server(server_t* server, short port);
void		accept_client(server_t* server);
void		name_user(channel_t* channel, char* name);
user_t* 	new_user(int socket);
void		add_user(server_t* server, int socket);

#endif		/* MYIRC_H */