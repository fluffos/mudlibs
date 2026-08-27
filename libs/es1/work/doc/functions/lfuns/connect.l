
CONNECT(L)              LOCAL FUNCTIONS                CONNECT(L)

NAME
     connect() - receive a connection and swap it into the user's
     body

SYNOPSIS
     int connect() ;

DESCRIPTION
     The connect() lfun is defined in /std/connection.c. Whenever
     a  user  logs  in  or  reconnects,  his connection object is
     created and connect() is called in it. If  the  function  is
     not  called  by ROOT_UID, or if the connection object has no
     body associated with it, or is not interactive, nothing hap-
     pens.  Then  the connection object sets the last_on time and
     tries to exec into the body object. If it fails, it notifies
     the  user and destructs both itself and the body. Otherwise,
     it forces the body to set link to itself and  things  go  on
     naturally.   The  connect() lfun need not be declared nomask
     because the connection object itself may not be shadowed: it
     defines query_prevent_shadow() to return 1;

SEE ALSO
     exec(),        switch_body(),         /adm/daemons/logind.c,
     /std/connection.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

