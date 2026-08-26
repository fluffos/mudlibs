
QUERY_TEMP(L)           LOCAL FUNCTIONS             QUERY_TEMP(L)

NAME
     query_temp - query a temporary property in an object.

SYNOPSIS
     mixed query (string prop) ;

DESCRIPTION
     The query_temp lfun is defined in the standard object. It is
     the same as the query() lfun except that it quries temporary
     properties, which are not saved when the  object  is  saved.
     See the man page on query() for more information.

SEE_ALSO
     query(),     set_temp(),     add_temp(),      delete_temp(),
     /std/object/prop.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

