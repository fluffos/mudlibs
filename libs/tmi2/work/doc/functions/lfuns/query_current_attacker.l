
QUERY_CURRENT_ATTACKER(L)LOCAL COMMANDS QUERY_CURRENT_ATTACKER(L)

NAME
     query_current_attacker() - return the object at the  top  of
     the attack list.

SYNOPSIS
     object query_current_attacker() ;

DESCRIPTION
     The   query_current_attacker()   lfun    is    defined    in
     /std/body/attack.c.  It  is  used  to  get  a pointer to the
     object that is at the top of the given object's attack list,
     ie  the  one  that  will be attacked in the next heart_beat.
     This object may die, move or  otherwise  vanish  before  the
     next attack is made, however.

WARNING
     There  is  a  nearly  identical  lfun(),  also  defined   in
     /std/body/attack.c,  called query_attacker. Query_attacker()
     is being retained for compatibility only, and you should use
     query_current_attacker() instead.

SEE ALSO
     query_attackers(),  cease_all_attacks(),   execute_attack(),
     /std/body/attack.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

