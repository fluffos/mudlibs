#include "path.h"
inherit "std/room";

void setup()
{
set_short("Lathander entryway");
set_long("You are in the entryway of Lathander's temple.  The room is "+
        "brightly lit and decorated in shades of red and gold.  A sign hangs "+
        "on the eastern wall, alongside a large archway which leads into "+
        "the temple.  A small hallway leaves the room to the north.  "+
        "Duke's Way is through the door to the west.\n");
set_light(90);
add_sign("A large golden sign.\n",
        "Services are at dawn every morning.\n"+
        "All are welcome to attend.\n"+
        "Praise to Lathander Morninglord.\n");
add_item("archway", "The archway is a heavy stone construction.\n");
add_item("wall", "The wall is made from stone.\n");
add_item("hallway", "It's quite narrow.\n");

add_exit("east", ROOM+"lath6", "corridor");
add_exit("north", ROOM+"lath2", "corridor");
add_exit("west", "d/ss/daggerford/duke5", "door");
modify_exit("north",({"function","go_north"}));
set_zone("lathander");
}
int go_north()
{
   if((string)this_player()->query_guild_name()=="lathander")
      return 1;
   tell_room(environment(this_player()),
      this_player()->query_cap_name()+" tried to go north, but was "+
      "stopped by and unseen force from Lathander.\n",
      this_player());
   notify_fail("The voice of Lathander fills your head: \"You are "+
      "not a member of my clergy.  You may not go in there.\"  "+
      "You are stopped from going north.\n");
   return 0;
}
