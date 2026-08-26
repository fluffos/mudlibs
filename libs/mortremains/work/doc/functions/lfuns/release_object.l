
RELEASE_OBJECT(L)       LOCAL FUNCTIONS         RELEASE_OBJECT(L)

NAME
     release_object() - determine whether an object will let  its
     contents go.

SYNOPSIS
     int release_object (object foo) ;

DESCRIPTION
     The release_object() lfun is defined in the standard object,
     but  is  meant to be redefined in other objects. It takes an
     object as an argument, and determines whether  the  argument
     object  should  be allowed to be taken from the inventory of
     the given object. It returns 1 if the object is  allowed  to
     be   taken   and   0   if   not.   The   move()  lfun  calls
     release_object() in an object's  environment  before  moving
     it.

     The version of  release_object()  defined  in  the  standard
     object  always  returns 1. You can override this function to
     make it impossible to move particular objects from  a  given
     object.

SEE ALSO
     move(), receive_object(), /std/object/ob_logic.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

