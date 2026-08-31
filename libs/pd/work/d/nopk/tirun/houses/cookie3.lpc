#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() {
  ::create();
  set_properties(([ "light" : 2,
                  "indoors" : 1
                 ]));
  set_short("Living Room");
  set_long("As you venture into this wing of the house, you notice a well kept living room "
           "with all your usual trimmings. A black-leather armchair, matching full couch, a "
           "small end table with an un-opened deck of cards, and an area rug potraying a "
           "large, well known group of cookie making elves.");
  set_smell("default","Leather. A Hint of Oak wafts in from the next room.");
  set_exits((["west" : ROOMS"houses/cookie1"]));
  set_items((["chair" : "An over-stuffed, black leather chair.",
              "couch" : "A Full-sized, black leather couch.",
              "endtable" : "Small, dark, wooden table with pull out drawer." ]));
}

void init() {
  ::init();
  add_action("open", "open");
}

int open(string str) {
  if(!str) return 0;
  if(str != "drawer") return 0;
  write("You see a note that's been taped inside. It reads \"Joyful Moo\".");
  say(this_player()->query_cap_name()+" opens a drawer and looks inside.");
  return 1;
}
