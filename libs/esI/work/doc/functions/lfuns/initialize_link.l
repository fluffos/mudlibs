
INITIALIZE_LINK(L)      LOCAL FUNCTIONS        INITIALIZE_LINK(L)

NAME
     initialize_link - sets the status of a door to  match  that
     of the linked door

SYNOPSIS
     void initialize_link(string dir);

DESCRIPTION
     initialize_link() is defined in /std/doors.c.

     Doors can be used in a  room  inheriting  /std/doors.c.   To
     ensure  that the status of a door in this room is consistent
     with  the  status  of   the   corresponding   linked   door,
     initialize_link() is called with the following arguments:
       string dir: The direction of the door - east,  west,  etc.
     Ordinarily,  initialize_link() should not need to be called,
     as update_link() should be called in the  linked  room  when
     the  door's  status is changed.  However, it is available as
     an extra security measure.

EXAMPLE
     initialize_link("north");

SEE ALSO
     create_door(l), set_status(l), update_link(l), /std/doors.c

AUTHOR
     Blue@Atmos


TMI-2 Release 0.9         Last change:                   4-2-93

