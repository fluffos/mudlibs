
RECEIVE_OBJECT(L)       LOCAL FUNCTIONS         RECEIVE_OBJECT(L)

NAME
     receive_object -  lets  object  decide  whether  or  not  to
     receive others.

SYNOPSIS
     int receive_object (object foo) ;

DESCRIPTION
     The receive_object() lfun is defined in the standard object,
     but  is  meant to be redefined in other objects. It takes an
     object as  argument  and  determines  whether  the  argument
     object  should  be  accepted into the inventory of the given
     object. It returns 1 if the object is accepted and 0 if not.
     The  move()  lfun calls receive_object in the destination to
     see if the move is acceptable.

     You do not need to worry about capacity  in  receive_object;
     mass and bulk checks are made seperately in move().

     The version of  receive_object()  defined  in  the  standard
     object always returns 1. You can override this to add selec-
     tion to what your rooms, or monsters, or containers are wil-
     ling to receive.

SEE ALSO
     move(), release_object(), /std/object/ob_logic.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

