
BASIC_COMMANDS(L)       LOCAL FUNCTIONS         BASIC_COMMANDS(L)

NAME
     basic_commands() - do any add_actions for commands coded  in
     the body

SYNOPSIS
     void basic_commands() ;

DESCRIPTION
     The basic_commands() lfun is defined in all of  the  bodies.
     It makes the add_action calls for any user commands that are
     defined in the specific body, rather than in  command  bins.
     Generaly speaking it is wasteful of memory and CPU to define
     a command in the user's body. The only reason to do it is to
     permit a user to take some action in the event that the com-
     mand bin system has errors. The only command so  defined  in
     the mudlib is the "quit" command.

SEE_ALSO
     init_commands(),  cmd_hook(),  /std/user.c,  /std/monster.c,
     /std/ghost.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

