
GET_RANDOM_ATTACKER(L)      LOCAL FUNCTIONS        GET_RANDOM_ATTACKER(L)

NAME
  get_random_attacker() - returns a random attacker from the 
  object's attackers array.

SYNOPSIS
     object get_random_attacker() ;

DESCRIPTION
     the get_random_attacker() lfun is defined in /std/body/attack.c.
     It returns a random object that the given object is currently
     in combat with, ie will attack given  the  chance,  and  the
     fact that it can only attack them one at a time. 

SEE ALSO
     query_current_attacker(),               cease_all_attacks(),
     query_attackers()
     /std/body/attack.c

AUTHOR
     Cyanide@Mortal Remains


Vertigo v1.0beta          Last change:             8 June 2000

