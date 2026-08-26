
SAVE_DATA(L)            LOCAL FUNCTIONS              SAVE_DATA(L)

NAME
     save_data() - save a user's body data to file.

SYNOPSIS
     nomask void save_data() ;

DESCRIPTION
     The save_data() lfun  is  defined  in  /std/user/save.c.  It
     writes  the  user's  body save file, using the save_object()
     efun. It may only be called by ROOT UID or  Logon  UID,  for
     security.

SEE ALSO
     restore_body(), save_object(), /std/user/save.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

