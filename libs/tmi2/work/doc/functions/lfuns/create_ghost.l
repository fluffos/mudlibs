
CREATE_GHOST(L)         LOCAL FUNCTIONS           CREATE_GHOST(L)

NAME
     create_ghost() - create a ghost object  and  swap  the  user
     into it.

SYNOPSIS
     static object create_ghost() ;

DESCRIPTION
     The create_ghost() lfun is defined in  /std/body.c.  When  a
     user  or interactive monster dies, we need to create a ghost
     body and swap the user's connection into that body. This  is
     done by calling the create_ghost() lfun.

     First create_ghost() clones  a  new  ghost  body.  Next,  it
     attempts  to transfer the connection from the dead body into
     the ghost, reporting an error if the swap fails. If the swap
     succeeds,  then  the new ghost body is initialized properly,
     and swapped to the cemetery if possible, to the location  of
     the  corpse if not possible. (Unless GHOST_START_LOCATION is
     not defined, in which case it always moves to the corpse.)

SEE ALSO
     /std/body.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

