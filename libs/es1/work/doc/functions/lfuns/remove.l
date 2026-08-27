
REMOVE(L)               LOCAL FUNCTIONS                 REMOVE(L)

NAME
     remove - remove an object from the game.

SYNPOSIS
     int remove() ;

DESCRIPTION
     The remove() lfun is defined in the standard object.  It  is
     used  to destruct an object. You should always call remove()
     to destroy an object; do  not  use  destruct  directly.  The
     remove()  lfun  moves  the object's contents, if any, to the
     environment of the object, updates volume  and  capacity  in
     the  appropriate way, and then destructs the object. Calling
     destruct() will cause encumbrance to become  incorrect,  and
     may  cause  the  object's  contents to vanish.  The remove()
     lfun always returns 1, unless an internal error occurs  dur-
     ing the removal.

SEE ALSO
     clean_up(), move(), /std/object/ob_logic.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

