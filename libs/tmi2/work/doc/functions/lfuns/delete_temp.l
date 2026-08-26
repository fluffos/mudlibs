
DELETE_TEMP(L)          LOCAL FUNCTIONS            DELETE_TEMP(L)

NAME
     delete_temp - delete a temporary property in an object.

SYNOPSIS
     void delete_temp (string prop) ;

DESCRIPTION
     The delete_temp lfun is defined in the standard  object.  It
     is  identical  to the delete() lfun except that it deletes a
     temporary property, which is not saved when  the  object  is
     saved.  See the man page on delete() for more information.

SEE ALSO
     delete(),     set_temp(),     add_temp(),      query_temp(),
     /std/object/prop.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

