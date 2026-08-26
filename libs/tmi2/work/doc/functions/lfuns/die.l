
DIE(L)                  LOCAL FUNCTIONS                    DIE(L)

NAME
     die() - produce death in a living body object.

SYNOPSIS
     static void die() ;

DESCRIPTION
     The die() lfun is defined in all living body objects. When a
     living  object notices that its hit points have fallen below
     0, or for some other reason decides to shuffle off this mor-
     tal coil, it call die() in itself. The die() lfun takes care
     of all the accounting and bookkeeping  associated  with  the
     death  of  a living thing. The exact tasks vary from body to
     body, but common to all are  announcing  its  death  to  the
     world,  cloning  a  corpse object and transferring items and
     wealth to it, switching the connection (if any) into a ghost
     body,  and destructing itself.  It is usually unwise to call
     die() in an object directly, although there are occasions to
     do  it. Usually, however, it is best to set the object's hit
     points below zero, or induce some  other  mortal  condition,
     and  let the object notice its death in the next heart_beat.
     That way, all  proper  death  effects  are  handled  in  the
     correct  order.   Objects  which cannot die, such as ghosts,
     need not define this lfun.

SEE ALSO
     continue_attack(), /std/user.c, /std/monster.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

