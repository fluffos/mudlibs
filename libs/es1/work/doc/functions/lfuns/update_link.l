
UPDATE_LINK(L)          LOCAL FUNCTIONS            UPDATE_LINK(L)

NAME
     update_link - updates the status of a door linked to one in
     this  room,  and  sends an appropriate message to the linked
     room

SYNOPSIS
     void update_link(string dir);

DESCRIPTION
     update_link() is defined in /std/doors.c.

     Doors can be used in a room inheriting /std/doors.c.  If you
     change  the  status  of  an  existing  door, you should call
     update_link() with the following arguments:
       string dir: The direction of the door - east,  west,  etc.
     update_link()  will  send an appropriate message to the room
     containing the linked door - e.g.  "The  south  door  swings
     open."

EXAMPLE
     update_link("north");

SEE ALSO
     create_door(l), set_status(l), initialize_link(l)

AUTHOR
     Blue@Atmos


TMI-2 Release 0.9         Last change:                   4-2-93

