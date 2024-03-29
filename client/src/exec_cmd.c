/*
** exec_cmd.c for  in /home/pinon_a/rendu/PSU_2013_myirc/client
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Tue Apr 22 16:29:21 2014 pinon
** Last update Tue Apr 22 18:21:36 2014 pinon
*/

#include "servermsg.h"
#include "client.h"
#include "rpl.h"

error_t	errors[] =
  {
    {ERR_NEEDMOREPARAM, "Error: too few parameters"},
    {ERR_NOSUCHUSER, "Error: no such user"},
    {ERR_NICKNAMEINUSE, "Error: nickname already use"},
    {ERR_NOSUCHCHANNEL, "Error: no such  channel"},
    {ERR_NOTONCHANNEL, "Error: user not in a channel"}
  };

cmd_t	cmds[] =
  {
    {RPL_MSGSENDER, rpl_msgsender},
    {RPL_MSG, rpl_msg},
    {RPL_JOINOK, rpl_joinok},
    {RPL_NEWJOIN, rpl_newjoin},
    {RPL_PARTOK, rpl_partok},
    {RPL_NEWPART, rpl_newpart},
    {RPL_LISTSTART, rpl_liststart},
    {RPL_LIST, rpl_list},
    {RPL_LISTEND, rpl_listend},
    {RPL_USERSSTART, rpl_usersstart},
    {RPL_USERS, rpl_users},
    {RPL_USERSEND, rpl_usersend}
  };

