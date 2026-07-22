
LOAD_AUTOLOAD_OBJ(L)    LOCAL FUNCTIONS      LOAD_AUTOLOAD_OBJ(L)

NAME
     load_autoload_obj - load a user's autoloading objects.

SYNOPSIS
     void load_autoload_obj() ;

DESCRIPTION
     The    load_autoload_obj()    lfun     is     defined     in
     /std/user/autoload.c.  Any  object  may declare itself to be
     autoloading by defining the query_auto_load() lfun to return
     something  non-zero. When the player quits, his inventory is
     checked for autoloading objects, and those  that  are  auto-
     loading  are  saved to file. When the user logs back in, the
     load_autoload_obj() lfun is called to recreate  those  items
     in  the  user's inventory. Thus, objects may be carried over
     from one login to the next this way.

SEE_ALSO
     compute_autoload_array(),           destroy_auto_load_obj(),
     query_auto_load(), /std/user/autoload.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

