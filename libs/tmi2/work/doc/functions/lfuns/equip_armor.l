
EQUIP_ARMOR(L)          LOCAL FUNCTIONS            EQUIP_ARMOR(L)

NAME
     equip_armor() - cause a monster to equip a piece of armor.

SYNOPSIS
     void equip_armor (object armor) ;

DESCRIPTION
     The equip_armor() lfun  is  defined  in  /std/monster.c.  It
     causes  the  monster  to  equip the piece of armor passes as
     argument. It  does  not  check  that  the  monster  actually
     possesses  the  armor - you need to check this yourself.  It
     sets the monster's appropriate armor property  and  unequips
     any  armor that the monster was previously equipping of that
     type.

SEE ALSO
     unequip(), unequip_armor(), /std/armor.c, /std/monster.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

