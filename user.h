/*
** user.h for  in /home/pinon_a/rendu/PSU_2013_myirc
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Fri Apr 18 13:37:02 2014 pinon
** Last update Fri Apr 18 14:21:33 2014 pinon
*/

#ifnedf USER_H_
# define USER_H_

typedef struct  user_s
{
  sockstream_t	u_socket;
  char          u_name[U_NAME_SIZE];
}               user_t;

#endif
