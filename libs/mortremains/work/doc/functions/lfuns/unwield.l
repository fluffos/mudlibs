
UNWIELD(L)              LOCAL FUNCTIONS                UNWIELD(L)

NAME
     unwield() - unwields (removes) weapon from a player's hands

SYNOPSIS
     void unwield();

DESCRIPTION
     This lfun is defined in the standard weapon object,  and  is
     used  when  the  player stops using the weapon as one of his
     combat weapons.

     The unwield() function marks the armor as unwielded, removes
     it  from  the player's list of weapons, displays appropriate
     messages to the player and anyone else in the same room, and
     recalculates  the player's weapon class.  Many commands call
     this function, which is why it is defined in weapon.c rather
     than in a command daemon.

SEE ALSO
     /std/object/ob_logic.c, /std/weapon.c

AUTHOR
     Ichabod@TMI (based on Mobydick's comments in weapon.c)


TMI-2 Release 0.9         Last change:                   4-2-93

