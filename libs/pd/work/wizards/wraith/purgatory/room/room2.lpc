#include <std.h>
#include <purgatory.h>

inherit ROOM;
void init() {
    ::init();
    add_action("lift_stone", "lift");
}
void create() {
    ::create();
     add_pre_exit_function("stairs","go_stairs");
     set_name("A path to the graveyard");
     set_short("A path to the graveyard.");
     set_long("This desolate path has been worn thin by the many mourners "
"that have passed by in last few hundred years. The horrible wailing has"
"grown louder followed by the stench of death. A large building can be seen "
"looming distantly in the east.");
     set_night_long("Shadows flitter around, making it seem like "
"there are many things out in the darkness. Looming shapes stand "
"closer to the path, making it hard to concentrate. ");
     set_properties(([
        "light"       : 1,
        "night light" : 0,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["east" : ROOMS"room3", 
              "west" : ROOMS"room1"]) );


    set_items( ([
            "path" : "Hard packed clay and dirt.",
            "stones" : "Large and small stones that have been beaten into the path",
            "stone" : "One stone looks out of place."
      ]) );

}
int lift_stone(string str) {
    if(!str) {
        notify_fail("lift what?\n");
        return 0;

    }
    if(str != "stone") {
        notify_fail("You can't lift that!\n");
        return 0;
    }
    

    message("info", "The stone flips over revealing a tunnel beneath the road.", this_player());
    add_exit(ROOMS"room82", "down");
    call_out("go_hole", 9);
    return 1;
}

void go_hole() {
    message("info", "The rock gets flipped by an unseen hand.",
all_inventory(this_object()));
    remove_exit("down");
}

int go_stairs() {
  if (this_player()->query_level() < 30) return 0;
  return 1; }
