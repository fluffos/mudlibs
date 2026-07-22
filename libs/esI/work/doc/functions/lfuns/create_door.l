
CREATE_DOOR(L)          LOCAL FUNCTIONS            CREATE_DOOR(L)

NAME
     create_door  -  sets  up  a  door  in  a  room   inheriting
     /std/doors.c

SYNOPSIS
     varargs void  create_door(string  dir,  string  linked_exit,
     mapping door_info );

DESCRIPTION
     create_door() is defined in /std/doors.c.

     Doors can be used in a room inheriting /std/doors.c.  To set
     up  a  door,  you  would  normally call create_door() in the
     create() function of the room.  The arguments to  the  func-
     tion are as follows:
       string dir: The direction of the door - east, west, etc.
       string linked_exit: The direction of the door in the  con-
               necting room  -  e.g.  if dir is east, linked_exit
               would usually be west.
       mapping door_info: The mapping contains informations about
               the door, you need to contain the following entries:
               "keyword" : an array of the ids of the door.
               "name" and "c_name" : Name (English and Chinese) of
               			the door.
               "desc" and "c_desc" : Description of the door.
               "status" : Status of the door, can be "open", "closed",
               			"locked".

EXAMPLE
     create_door("north",  "south", ([
     	"keyword"	: ({ "big door", "door" }),
     	"name"		: "big door",
     	"c_name"	: "大门",
     	"desc"		: "A huge and massive door blocks your way to north",
     	"c_desc"	: "一扇巨大笨重的门挡住了你往北的去路",
     	"status"	: "closed"
     ]) );

SEE ALSO
     set_status(l), initialize_link(l), update_link(l)

AUTHOR
     Blue@Atmos
     Annihilator@Eastern.Stories


TMI-2 Release 0.9         Last change:                   11-7-93

