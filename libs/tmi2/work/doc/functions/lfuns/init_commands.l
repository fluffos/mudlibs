
INIT_COMMANDS(L)        LOCAL FUNCTIONS          INIT_COMMANDS(L)

NAME
     init_commands() - add the command hook add  action  and  set
     the path.

SYNOPSIS
     static void init_commands() ;

DESCRIPTION
     The init_commands() lfun is defined in all of the bodies. It
     handles  two  tasks. First, it adds the cmd_hook add_action,
     with the string "" and with the match-beginning option used.
     Thus,  anything the user types that is not handled by a pre-
     vious add_action, will be passed to the cmd_hook function in
     the  body.  The second thing the init_commands function does
     is set the user's PATH property. The exact PATH set  depends
     on  the  body,  but  in  all  cases  the  PATH  is set to be
     MASTER_ONLY secure.  This  prevents  people  from  attacking
     other  user's paths in an attempt to write traps.  If you do
     a lot of path-switching, for guilds or other  reasons,  then
     you  may  need  to  relax  this  security  in  your own body
     objects.

SEE_ALSO
     basic_commands(), cmd_hook(),  /std/user.c,  /std/monster.c,
     /std/ghost.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

