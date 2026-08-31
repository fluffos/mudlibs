
 
inherit "room/room";
#include "../garden.h" 
 
void reset(int arg) 
{
   if (filter_live(TO) < 4)
   {
    CM("sheep");
    CM("sheep");
   }
   if (arg) return; 
   set_light(1);
   short_desc = "In a beautiful garden";
   no_castle_flag = 0;
   long_desc = BS(
        "This is the northeast corner of Chantilly's garden. "
      + "A place where the grass is fresh and tasty, just as sheep "
      + "and adventurers like it. "
      + "There is a brown garden fence to the north and west and "
      + "a small path leading to the south.");

    items = ({ "fence","You see a big brown garden fence" });
    dest_dir = ({ ROOM+"/garden1","south", ROOM+"/garden5", "west" });
   dest_dir = dest_dir + ({ ROOM+"/dragon_room","down" });
}
init() {
  ::init();
  add_action("climb","climb");
  }

int climb(string str) 
{
  if (str=="fence") {
  write(
  "On this place the fence is much too high, you stumble and fall down.\n");
  say(this_player()->query_name()+
  " tries to climb up the fence, but stumbles and falls down.\n");
  return 1;
 }
  return 0;
}

