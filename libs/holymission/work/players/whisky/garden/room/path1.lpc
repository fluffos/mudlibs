 
inherit "room/room";
#include "../garden.h" 
 
void reset(int arg) 
{
  if (arg) return;
  set_light(1);
  short_desc = "On a little path";
  no_castle_flag = 0;

  long_desc = BS(
    "You are now leaving Chantilly's. Behind you is the garden, "
  + "and you could climb back over the fence. "
  + "A path is leading north where you can see a little dark "
  + "forest.");

  dest_dir = ({ ROOM+"/path2", "north" });
  items = ({ "fence","A big brown garden fence" });
  CO("tree");
}

init() {
  add_action("climb","climb");
  ::init();
}

int climb(string str) 
{
  if (str=="fence") 
{
     write("\nYou climb back over the garden fence.\n\n");
     this_player()->move_player("climbs back into the garden#"+ROOM+"/garden3");
     return 1;
  }
  return 0;
}
