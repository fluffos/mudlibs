
QUERY_USER(L)           LOCAL FUNCTIONS             QUERY_USER(L)

NAME
     query_user() - return 1 if this object is a user body.

SYNOPSIS
     nomask int query_user() ;

DESCRIPTION
     The query_user lfun() is defined in /std/user.c. It provides
     a unique and secure method of identifying user body objects.
     Similar  functions  are  defined   in   /std/monster.c   and
     /std/ghost.c.

SEE ALSO
     query_monster(), query_ghost(), /std/user.c, /std/monster.c,
     /std/ghost.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

