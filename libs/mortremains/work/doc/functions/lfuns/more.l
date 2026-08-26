
MORE(L)                 LOCAL FUNCTIONS                   MORE(L)

NAME
     more() - display a file to the user, one screen at a time.

SYNOPSIS
     varargs int  more (mixed str, int flag, int mask) ;

DESCRIPTION
     The more() lfun is defined in /std/body/more.c. It is  simi-
     lar to the UNIX more command; it displays a file to the user
     screen by screen, pausing for a key stroke between screens.

     The str arg is the name or names of files to be mored to the
     user. The flag argument is set to 1 if this is not the first
     file in the sequence to be mored: it supresses checking  the
     list for legibility. The mask argument supresses printing of
     the header.

     The length of the screen in lines is controlled by the LINES
     environment variable. The default value is 23.

     The more command is a front-end for the more() lfun.

SEE ALSO
     /cmds/file/_more.c, /std/body/more.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

