
COMPUTE_AUTOLOAD_ARRAY(L)LOCAL COMMANDS COMPUTE_AUTOLOAD_ARRAY(L)

NAME
     compute_autoload_array() - compute a list of objects to save
     for later

SYNOPSIS
     void compute_autoload_array() ;

DESCRIPTION
     The   compute_autoload_array()   lfun    is    defined    in
     /std/user/autoload.c.  Any  object  may declare itself to be
     autoloading by defining the query_auto_load() lfun to return
     something  non-zero.  When the user saves, all his inventory
     objects are checked to see if they are autoloading,  and  if
     so,  an  array with their names and data is saved as part of
     the  player  .o  file.  This  is   done   by   calling   the
     compute_autoload_array() lfun in the player object.

SEE ALSO
     query_auto_load(),                      load_autoload_obj(),
     destroy_autoload_obj(), /std/user/autoload.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

