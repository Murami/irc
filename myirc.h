/*
** myirc.h for  in /home/pinon_a/rendu/PSU_2013_myirc
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Fri Apr 18 13:52:04 2014 pinon
** Last update Fri Apr 18 14:08:00 2014 pinon
*/

#ifndef MYIRC_H_
# define MYIRC_H_

#include	<stdio.h>
#include	<string.h>

#include	"channel.h"
#include	"user.h"

#define		U_NAME_SIZE 128
#define		C_NAME_SIZE 128

int		str_match(char *str, char *name);

void		cmd_list(char *str, channel_t *channels, int nbr_channel);
void		cmd_users(user_t *users, int nbr_user);

#endif
