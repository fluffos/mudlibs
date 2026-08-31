#include <std.h>
#include <roston.h>

inherit ROOM;

void init() {
    ::init();

add_action("enter_hole" , "enter");
}
void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "boulder" : "A huge boulder blocking the path to the north there seems to be a giant hole in it maybe you can enter it",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("There are tons of rocks, and dirt all over the "
            "path. A giant boulder blocks the path to the north.");
set_exits( (["south" : ROOMS"roston34"]));                  

}

int enter_hole(string what) {
  if (what != "hole") return 0;
this_player()->move_player(DROWROOM"path1", "into the huge boulder and vanishes without a trace.");
    return 1;
}

