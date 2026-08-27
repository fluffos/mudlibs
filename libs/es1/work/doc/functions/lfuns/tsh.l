
TSH(L)                  LOCAL FUNCTIONS                    TSH(L)

NAME
     tsh() - force the user to execute a script of commands

SYNOPSIS
     int tsh(string file) ;

DESCRIPTION
     The tsh() lfun is defined in /std/user/tsh.c. It  takes  the
     name  of  a  file as an argument, and reads each line of the
     file and forces the user to execute that line as if  he  had
     typed  it. The tsh command is a front-end to this lfun.  The
     tsh() lfun can be used to execute scripts  of  LPC  command,
     not  unlike  the similar feature of UNIX.  For security rea-
     sons, only admins, ROOT_UID, and the object's EUID may  call
     tsh()  in  an  object - otherwise one could implement forces
     this way.

SEE ALSO
     /std/user/tsh.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

