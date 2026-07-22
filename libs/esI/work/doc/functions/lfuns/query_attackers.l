
QUERY_ATTACKERS(L)      LOCAL FUNCTIONS        QUERY_ATTACKERS(L)

NAME
     query_attackers() - return the list of the object's  attack-
     ers.

SYNOPSIS
     object *query_attackers() ;

DESCRIPTION
     The query_attackers() lfun is defined in /std/body/attack.c.
     It  returns the list of all objects that the given object is
     in combat with, ie will attack given  the  chance,  and  the
     fact that it can only attack them one at a time.

SEE ALSO
     query_current_attacker(),               cease_all_attacks(),
     /std/body/attack.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

