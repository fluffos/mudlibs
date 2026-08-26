
RELAY_MESSAGE(L)        LOCAL FUNCTIONS          RELAY_MESSAGE(L)

NAME
     relay_message() - handle a received message in a monster

SYNOPSIS
     void relay_message(string class, string str) ;

DESCRIPTION
     The relay_message() efun is defined  in  /std/monster.c.  It
     serves  two  purposes. First, every time the receive_message
     function is triggered in a monster object, the received mes-
     sage    is   passed   to   the   relay_message   lfun.   The
     receive_message lfun must be unshadowable and unmaskable for
     security purposes; the relay_message lfun is neither, allow-
     ing you to do customized message handling in your  monsters.
     You  may redefine the relay_message lfun and have that func-
     tion handle requests from players or quests or whatever cus-
     tom  message-handling  you  want  the monster to do. Second,
     relay_message in the default monster is the hook fro aggres-
     sive  monsters;  ie,  those  that attack when they receive a
     message  of  the  form  "Player  enters."  If  you  redefine
     relay_message  in  a monster, and you want the monster to be
     aggressive, you'll have to make a ::relay_message() call  in
     your  custom  monster  to  handle it.  There are also killer
     monsters, which  are  those  that  attack  any  player  that
     triggers  their  init()  function.  This  is  handled in the
     init() function of the  monster  (naturally)  and  are  MUCH
     harder to evade than an aggressive monster.

SEE ALSO
     init(), message(), /std/monster.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

