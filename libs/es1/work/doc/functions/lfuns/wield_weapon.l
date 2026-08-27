
WIELD_WEAPON(L)         LOCAL FUNCTIONS           WIELD_WEAPON(L)

NAME
     wield_weapon() - cause a monster to wield a weapon.

SYNOPSIS
     void wield_weapon (object weapon) ;

DESCRIPTION
     The wield_weapon() lfun is  defined  in  /std/monster.c.  It
     causes  the  monster to wield the weapon passed as argument.
     It  does  not  check  to  make  sure  the  monster  actually
     possesses  the weapon - you must take care of this yourself.
     It sets the monster's "weapon" property to point to the sup-
     plied weapon, and unsets any previously wielded weapon using
     the unwield() lfun defined in the weapon object.

KNOWN_BUGS
     If a wizard inhabiting a monster  uses  the  wield  command,
     then  it is possible for the monster to acquired two wielded
     weapons, though the second one will have no effect  on  com-
     bat.

SEE ALSO
     unwield(), unwield_weapon(), /std/weapon.c, /std/monster.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

