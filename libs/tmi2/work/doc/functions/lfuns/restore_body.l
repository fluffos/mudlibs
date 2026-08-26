
RESTORE_BODY(L)         LOCAL FUNCTIONS           RESTORE_BODY(L)

NAME
     restore_body() - load a body's saved data.

SYNOPSIS
     nomask int restore_body() ;

DESCRIPTION
     The restore_body() lfun is defined in  /std/user/save.c.  It
     can  only  be  called from the connection object, as this is
     one of the most sensitive areas of the  lib.  It  calls  the
     restore_object()  efun, with the user_data_dir path, to load
     a body's saved data.  This is a very bad  place  to  have  a
     bug. Make changes with extreme caution.

SEE ALSO
     save_data(),       restore_object(),        user_data_dir(),
     /std/living/save.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

