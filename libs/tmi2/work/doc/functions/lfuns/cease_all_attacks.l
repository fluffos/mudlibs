
CEASE_ALL_ATTACKS(L)    LOCAL FUNCTIONS      CEASE_ALL_ATTACKS(L)

NAME
     cease_all_attacks() - clear the player's attacker list.

SYNOPSIS
     void cease_all_attacks() ;

DESCRIPTION
     The    cease_all_attacks()    lfun     is     defined     in
     /std/body/attack.c.  It is used to erase the list of objects
     that the current object is attackin, and sets the any_attack
     variable  to  zero.  Calling  this lfun causes the object to
     make peace with ALL of its current foes.  called to cause an
     object to make peace with ALL of its current foes.

WARNING
     There is  a  near-identical  function,  init_attack(),  also
     defined  in  /std/body/attack.c,  which clears the attackers
     list but does NOT set the any_attack  variable.  You  should
     use  the  clear_all_attacks()  lfun  instead  of  this one -
     init_attack() is for internal use only.

SEE ALSO
     query_current_attacker(),    execute_attack(),     kill_ob()
     /std/body/attack.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

