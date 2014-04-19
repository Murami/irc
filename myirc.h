/*
** myirc.h for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Fri Apr 18 13:52:04 2014 pinon
** Last update Sat Apr 19 10:07:50 2014 pinon
*/

#ifndef		MYIRC_H
# define	MYIRC_H

# include		<stdio.h>
# include		<string.h>

# include		"channel.h"

# define		U_NAME_SIZE 128
# define		C_NAME_SIZE 128

/* COMMANDE */

void		cmd_list(char *str, channel_t *channels, int nbr_channel);
void		cmd_users(user_t *users, int nbr_user);

/* UTILS */

int		find_empty_unregistered(server_t* server);
int             str_match(char *str, char *name);

/* INIT	*/

sockstream_t*     creat_sockstream(int socket);

#endif		/* MYIRC_H */
