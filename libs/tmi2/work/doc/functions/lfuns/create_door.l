
CREATE_DOOR(L)          LOCAL FUNCTIONS            CREATE_DOOR(L)

NAME
     create_door  -  sets  up  a  door  in  a  room   inheriting
     /std/doors.c

SYNOPSIS
     varargs void  create_door(string  dir,  string  linked_exit,
     string door_desc, string door_stat, string lock);

DESCRIPTION
     create_door() is defined in /std/doors.c.

     Doors can be used in a room inheriting /std/doors.c.  To set
     up  a  door,  you  would  normally call create_door() in the
     create() function of the room.  The arguments to  the  func-
     tion are as follows:
       string dir: The direction of the door - east, west, etc.
       string linked_exit: The direction of the door in the  con-
     necting           room  -  e.g.  if dir is east, linked_exit
     would usually         be west.
       string door_desc: The description of the door  -  e.g.  "A
     small         steel door with knobs on"
       string door_stat: The status of the door at initialization
     -         "open", "closed", or "locked".
       string lock: The lock variable - this can be whatever  you
     like         and is used by the key to determine whether the
     door         can be unlocked or not.  create_door() can also
     be  called by call_other(), but usually would not be used in
     this way.

EXAMPLE
     create_door("north",  "south",  "A  sliding   stone   door",
     "closed", "granite");

SEE ALSO
     set_status(l), initialize_link(l), update_link(l)

AUTHOR
     Blue@Atmos


TMI-2 Release 0.9         Last change:                   4-2-93

