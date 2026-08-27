
DESTROY_AUTOLOAD_OBJ(L) LOCAL FUNCTIONS   DESTROY_AUTOLOAD_OBJ(L)

NAME
     destroy_autoload_obj()  -  destroy  the  user's  autoloading
     objects

SYNOPSIS
     void destroy_autoload_obj() ;

DESCRIPTION
     The    destroy_autoload_obj()    lfun    is    defined    in
     /std/user/autoload.c.  Any  object  can declare itself to be
     autoloading by defining the query_auto_load() lfun to return
     something  non-zero.  Autoloading objects are destroyed when
     the user quits and are re-loaded the next time the user logs
     in,  in  his  inventory.  The destroy_autoload_obj() lfun is
     used to destroy the user's autoloading objects at quit time.

KNOWN BUGS
     Autoload objects are destroyed  after  the  player  data  is
     saved.  This  requires  the encumbrance of those items to be
     subtracted from the  player's  limit  before  the  save.  It
     works,  but  it's  a  little  dodgy. A future version of the
     mudlib may handle this task in a more streamlined fashion.

SEE ALSO
     query_auto_load(),                      load_autoload_obj(),
     compute_autoload_array(), /std/user/autoload.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

