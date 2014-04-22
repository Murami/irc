
/*
** servermsg.h for  in /home/guerot_a/rendu/PSU_2013_myirc/server
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Tue Apr 22 12:02:56 2014 guerot_a
** Last update Tue Apr 22 17:05:48 2014 pinon
*/

#ifndef SERVERMSG_H
# define SERVERMSG_H

# define ERR_NEEDMOREPARAM	461

/* MSG */

# define RPL_MSGSENDER		381
# define RPL_MSG		382
# define ERR_NOSUCHUSER		471

/* NICK */

# define ERR_NICKNAMEINUSE	433


/* JOIN */

# define ERR_NOSUCHCHANNEL	403
# define RPL_JOINOK		361
# define RPL_NEWJOIN		362

/* PART */

# define ERR_NOTONCHANNEL	442
# define RPL_PARTOK		371
# define RPL_NEWPART		372

/* LIST */

# define RPL_LISTSTART		321
# define RPL_LIST		322
# define RPL_LISTEND		323

/* USERS */

# define RPL_USERSSTART		351
# define RPL_USERS		352
# define RPL_USERSEND		353

#endif /* SERVERMSG_H */
