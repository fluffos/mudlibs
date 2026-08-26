
UNEQUIP_ARMOR(L)        LOCAL FUNCTIONS          UNEQUIP_ARMOR(L)

NAME
     unequip_armor() - Cause a monster to stop equipping armor.

SYNOPSIS
     void unequip_armor (object armor) ;

DESCRIPTION
     The unequip_armor() lfun is defined  in  /std/monster.c.  It
     causes a monster to stop equipping the passed armor. It does
     not check to make sure that the  passed  armor  is  actually
     equipped  - you must do this yourself. It sets the appropri-
     ate armor property to 0, and calls  unequip  in  the  passed
     armor.

SEE ALSO
     unequip(), wield_armor()

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

