#include <std.h>
#include <kabaal.h>
inherit ROOM;

void create()
{
 ::create();
set_short("lost in the rain forest");
   set_long("Animals are everywhere. The lush green leaves "
           "sparkle in the faint sunlight. The moist ground can "
           "hardly be seen from here, but climbing back "
           "down is impossible from here.");
set_items( 
          ([ "vines" : "The vines go from tree to tree.",
             "trees" : "A hidden path can be seen through the trees.",
             "ground": "You can hardly see it from here.",
             "path": "A hidden path leaves east. To follow it, you'd have to %^BOLD%^%^WHITE%^enter the forest%^RESET%^.",
             "monkeys" : "They seem to be moving quickly." ]) );
set_property("light", 2);
set_property("night light", 1);
set_smell("default", "The humid air stifils your senses.");
set_listen("default", "You hear animals squeeking.");
set_exits( (["north" :ROOMS "4",
              "south" : ROOMS "6"]) );
}void init() {
  ::init();
  add_action("enter_it","enter");
}

int enter_it(string str) {
  if(!str) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "forest") {
    notify_fail("You can't enter that!\n");
    return 0;
  }
  else {
this_player()->move_player(ROOMS "e1", "disappears into the forest.");
    return 1;
  }
}
