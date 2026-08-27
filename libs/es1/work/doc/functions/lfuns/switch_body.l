
SWITCH_BODY(L)          LOCAL FUNCTIONS            SWITCH_BODY(L)

NAME
     switch_body() - change the connection from one body  to  the
     next

SYNOPSIS
     int switch_body() ;

DESCRIPTION
     The switch_body() lfun is defined in  /std/connection.c.  It
     is used to switch a user's connection from the old body to a
     new one. Before the switch takes place, you must  first  set
     the  new  body  variable in the connection object by setting
     its "tmp_body" property. Then, when  the  connection  object
     has  a  pointer  to  both the old body and the new, you call
     switch_body(). It checks permissions; only ROOT_UID and  the
     old body may call the switch_body() lfun. If the call is OK,
     then switch_body() calls the exec() efun to swap the connec-
     tion  into the new body.  The switch_body() efun need not be
     declared nomask because the connection object itself is  not
     shadowable, since it defines query_no_shadow() to return 1.

SEE ALSO
     set(), exec(), /std/connection.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

