/* $Header: /mud/tkv/bin/player/RCS/_su.c,v 1.1 1995/07/09 19:20:00 mudriver Exp $

 * $Log: _su.c,v $

 * Revision 1.1  1995/07/09  19:20:00  mudriver

 * Initial revision

 *

 * /bin/player/_su.c

 * created by ??? (origional header missing)

 * REcreated by Zortek

 */

#include <std.h>

#include <security.h>

#include <daemons.h>



inherit DAEMON;



int cmd_su(string arg)

{

    seteuid(UID_SU);

    return SU_D->cmd_su(arg);

}



int 

help()

{

    write(@HELP

Syntax:  su [player]



The su command allows you to morph into another character, or a fresh

version of your own character.  It is equivalent to logging out and

logging back in, but quicker.  The most important thing that happens when

you su is that a new copy of the player object is cloned.  This is useful

if you have just modified the player object and need to test the changes.



With an argument, su prompts you for the password of the player named

<player> and polymorphs you into that player.  If you pass your own name

as argument, su does not ask for the password and you appear as yourself

in a new clone of the player object.



See also:  chfn, describe, passwd, sites.

HELP

);

    return 1;

}

