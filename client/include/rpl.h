/*
** rpl.h for  in /home/pinon_a/rendu/PSU_2013_myirc/client/include
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Tue Apr 22 17:06:06 2014 pinon
** Last update Tue Apr 22 17:13:07 2014 pinon
*/

#ifndef		RPL_H
# define	RPL_H

/* MSG */
void	rpl_msgsender(char* data);
void	rpl_msg(char* data);

/* JOIN */
void	rpl_joinok(char* data);
void	rpl_newjoin(char* data);

/* PART */
void	rpl_partok(char* data);
void	rpl_newpart(char* data);

/* LIST */
void	rpl_liststart(char* data);
void	rpl_list(char* data);
void	rpl_listend(char* data);

/* USER */
void	rpl_usersstart(char* data);
void	rpl_users(char* data);
void	rpl_usersend(char* data);

#endif		/* RPL */
