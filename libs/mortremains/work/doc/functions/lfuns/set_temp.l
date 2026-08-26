
SET_TEMP(L)             LOCAL FUNCTIONS               SET_TEMP(L)

NAME
     set_temp - set a temporary property in an object.

SYNOPSIS
     varargs void set_temp (string prop, mixed  data,  int  secu-
     rity) ;

DESCRIPTION
     The set_temp lfun is defined in the standard object.  It  is
     the  same  as  the  set() lfun except that it sets temporary
     properties, which are not saved when the  object  is  saved.
     See the man page on set() for more information.

SEE ALSO
     set(),     query_temp(),     add_temp(),      delete_temp(),
     /std/object/prop.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

