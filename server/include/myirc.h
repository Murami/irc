/*
** myirc.h for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Fri Apr 18 13:52:04 2014 pinon
** Last update Tue Apr 22 17:51:19 2014 guerot_a
** Last update Tue Apr 22 11:51:01 2014 pinon
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
# include "servermsg.h"

int		str_match(char *str, char *name);
int		available_name(server_t* server, char* name);
void		name_user(channel_t* channel, char* name);
user_t*		find_user(server_t* server, const char* name);
channel_t*	find_channel(server_t* server, /*const*/ char* name);
void		parse_args(char** arg1, char** arg2, char *str);
int		parse_request(server_t*, user_t* user, request_t* request);
void		manage_server_datas(server_t* server);
void		accept_client(server_t* server);

/* IRC COMMANDS */

void		manage_request_user(request_t* request, int inchannel);
void		manage_nickname(request_t* request);
void		manage_list(request_t* request);
void		manage_join(request_t* request);
void		manage_part(request_t* request);
void		manage_users(request_t* request);
void		manage_msg(request_t* request);
void		manage_msg_all(request_t* request);
void		manage_send_file(request_t* request);
void		manage_accept_file(request_t* request);
void		manage_invalidcmd(request_t* request);

/* MANAGE IO */

void		recv_sockstream(sockstream_t* sstream);
/* void		send_sockstream(sockstream_t* sstream); */
void		refresh_sets(server_t* server, socketset_t* sets);
void		manage_io_user(server_t* server, socketset_t* sets);
void		manage_io_userchan(server_t* server, socketset_t* sets);
void		manage_io_listen(server_t* server, socketset_t* sets);
void		manage_io(server_t* server, socketset_t* sets);

/* NEW */

user_t* 	new_user(int socket);
sockstream_t*	new_sockstream(int socket);
channel_t*	new_channel(const char* channel_name);

/* ADD */

void		add_channel(server_t* server, const char* channel_name);
void		add_user(server_t* server, int socket);

/* INIT */

void		init_user_list(server_t* server);
void		init_channel_list(server_t* server);
void		init_server(server_t* server, short port);

/* */

#endif		/* MYIRC_H */
