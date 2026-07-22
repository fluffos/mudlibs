
UNWIELD_WEAPON(L)       LOCAL FUNCTIONS         UNWIELD_WEAPON(L)

NAME
     unwield_weapon() -  Cause  a  monster  to  stop  wielding  a
     weapon.

SYNOPSIS
     void unwield_weapon (object weapon) ;

DESCRIPTION
     The unwield_weapon() lfun is defined in  /std/monster.c.  It
     causes a monster to stop wielding the passed weapon. It does
     not check to make sure that the passed  weapon  is  actually
     wielded  -  you must do this yourself. It sets the monster's
     weapon1 property to 0,  and  calls  unwield  in  the  passed
     weapon.

SEE ALSO
     unwield(), wield_weapon()

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

