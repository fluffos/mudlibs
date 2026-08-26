
SET_STATUS(L)           LOCAL FUNCTIONS             SET_STATUS(L)

NAME
     set_status - sets the status (open, closed,  locked)  of  a
     door in a room inheriting /std/doors.c

SYNOPSIS
     void set_status(string dir, string value);

DESCRIPTION
     set_status() is defined in /std/doors.c.

     Doors can be used in a room inheriting /std/doors.c.  To set
     the  status of an existing door, you would call set_status()
     with the following arguments:
       string dir: The direction of the door - east, west, etc.
       string value: The status the door is  to  have  -  usually
     open,          closed or locked, although you might conceiv-
     ably           think  of  something  else.   After   calling
     set_status()  in  a room, you should also call update_link()
     so that the corresponding door in the linked  room  will  be
     set to the same status as this one.  update_link() will take
     care of messages to the linked room, but the object  calling
     set_status()  (usually a key or some such) must generate the
     messages for the room it is acting on.

EXAMPLE
       set_status("north", "open");
       update_link("north");

SEE ALSO
     create_door(l), initialize_link(l), update_link(l)

AUTHOR
     Blue@Atmos


TMI-2 Release 0.9         Last change:                   4-2-93

