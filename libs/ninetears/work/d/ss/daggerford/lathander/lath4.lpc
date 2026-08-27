#include "path.h"
inherit "std/room";
int gotrobe;

void reset() { gotrobe = 0; }
setup()
{
set_light(90);
set_short("cleric chambers");
set_long("You are in a small room which appears to be used by the Clerics "+
        "of Lathander in preparation for daily services.  Along the north "+
        "wall are a variety of robes.  A bookcase stands against the "+
        "eastern wall.  Two doors lead from the room, one to the west "+
        "and one to the southeast.\n");
add_exit("west", ROOM+"lath3", "door");
add_exit("southeast", ROOM+"lath12", "door");
modify_exit("southeast", ({"function", "go_se"}) );

add_alias("robe", "robes");
add_item("robes", "They are bright, long-sleeved robes of yellow, red, and "+
        "pink.  They are probably worn by the temple clerics "+
        "when conducting various ceremonies.\n");

add_item("bookcase", "The bookcase contains many items which are used "+
        "during services.\n");

set_zone("lathander");
}

init()
{
  add_action("get_robe", "get");
  ::init();
}

int get_robe(string str)
{
  object robe;
   if(gotrobe) return 1;
  if(str == "robe")
  {
      gotrobe = 1;
    robe = clone_object(ITEMS+"lrobe");
    robe->move(this_player());
    write("You get a robe of Lathander.\n");
    say(this_player()->query_cap_name()+" gets a robe of Lathander.\n");
    return 1;
  }
}

int go_se()
{
   if((string)this_player()->query_level()>=5)
      return 1;
   tell_room(environment(this_player()),
      this_player()->query_cap_name()+" tried to go south east, but "+
      "was stopped by and invisible force from Lathander.\n");
   notify_fail("The voice of Lathander fills your head:  \"You must "+
      "have more faith in me before you may enter this room.\"  You "+
      "are stopped from going south east.\n");
   return 0;
} 
