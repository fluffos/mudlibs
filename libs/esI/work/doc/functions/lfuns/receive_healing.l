
RECEIVE_HEALING(L)      LOCAL FUNCTIONS        RECEIVE_HEALING(L)

NAME
     receive_healing() - heal a living object.

SYNOPSIS
     int receive_healing (int healing) ;

DESCRIPTION
     receive_damage() is defined  in  /std/body/attack.c.  It  is
     inherited  by  body.c,  and  thus  by  the  user and monster
     objects. It is used to heal a player or monster: to  do  so,
     call receive_healing in the object. It makes sure the target
     is neither dead nor link-dead and applies the healing,  mak-
     ing sure not to exceed the maximum hit points of the object.

SEE ALSO
     receive_damage(), /std/body/attack.c, /std/living/spells.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

