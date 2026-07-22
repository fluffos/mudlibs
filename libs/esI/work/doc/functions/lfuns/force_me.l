
FORCE_ME()        MISC. REFERENCE MANUAL PAGES         FORCE_ME()

NAME
     force_me() - force a living object to execute a command.

SYNOPSIS
     int force_me(string cmd) {

DESCRIPTION
     The force_me() lfun is defined in /std/body.c.  It  takes  a
     string  as an argument and forces the object to execute that
     command as if the user in control of the body (if  any)  had
     typed  it. Players, inhabited monsters, and uninhabited mon-
     sters may all be forced to execute commands.

     First, the  force_me()  lfun  makes  security  checks;  only
     ROOT_UID  and  the  object's own EUID may use the force_me()
     lfun. Next, it calls process input in the  object  to  apply
     any  relevant  processing such as aliases and nicknames, and
     then calls the command() efun to force the user  to  execute
     that  command. See the command() man page for details on how
     this is done.

SEE ALSO
     command(), /std/body.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

