
ADD_TEMP(L)             LOCAL FUNCTIONS               ADD_TEMP(L)

NAME
     add_temp - add to a temporary property.

SYNOPSIS
     void add (string prop, mixed data) ;

DESCRIPTION
     The add_temp lfun is defined in the standard object.  It  is
     identical to the add() lfun except that it adds to temporary
     properties, which are not saved when the  object  is  saved.
     See the man page on add() for more information.

SEE ALSO
     add(),     set_temp(),     query_temp(),      delete_temp(),
     /std/object/prop.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

