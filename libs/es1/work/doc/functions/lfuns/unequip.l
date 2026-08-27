
UNEQUIP(L)              LOCAL FUNCTIONS                UNEQUIP(L)

NAME
     unequip - unequips (removes) armor from player

SYNOPSIS
     void unequip();

DESCRIPTION
     This lfun is defined in the standard armor  object,  and  is
     used when the player takes the armor off.

     The  unequip()  function  marks  the  armor  as  unequipped,
     removes  it  from  the player's list of worn armor, displays
     appropriate messages to the player and anyone  else  in  the
     same  room, and recalculates the player's armor class.  Many
     commands call this function, which is why it is  defined  in
     armor.c rather than in a command daemon.

SEE ALSO
     /std/object/ob_logic.c, /std/armor.c

AUTHOR
     Ichabod@TMI (based on Mobydick's comments in armor.c)


TMI-2 Release 0.9         Last change:                   4-2-93

