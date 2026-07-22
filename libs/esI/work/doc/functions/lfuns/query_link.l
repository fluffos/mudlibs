
QUERY_LINK(L)           LOCAL FUNCTIONS             QUERY_LINK(L)

NAME
     query_link() - return a pointer to  the  connection  of  the
     current body.

SYNOPSIS
     object query_link() ;

DESCRIPTION
     The query_link() lfun is defined in  body.c.  In  the  TMI-2
     mudlib,  each  user is first given a connection object which
     handles his name, password, and other data relevant  to  the
     user.  When  he  logs  in, he is connected to a body object,
     which contains data related to the character he  plays.  The
     query_link()  function  returns  a pointer to the connection
     object which is associated with  the  given  body,  if  any.
     Player  bodies  and ghosts will always have a linked connec-
     tion object, but monster bodies may or  many  not  have  one
     depending  on  whether the monster is controlled by a wizard
     at the time or not.

SEE ALSO
     set_link(), /std/body.c, /std/connection.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

