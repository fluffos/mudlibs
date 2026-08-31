#include <std.h>
#include <purgatory.h>

inherit ROOM;
void init() {
    ::init();
    add_action("move_picture", "move");
}
void create() {
    ::create();
     set_name("An underground tunnel.");
     set_short("An underground tunnel.");
     set_long("It looks like a nest of some unfriendly people have "
"made a tunnel into the castle. This part of the tunnel seems to bore "
"straight through hard stone. A light can be seen coming through what "
"looks to be the back of a picture!");
     set_night_long("It is far too dark to see anything at night in the tunnel.");
     set_properties(([
        "light"       : 1,
        "night light" : -2,
        "no bump"     : 1,
        "underground"       : 1,
        "no steal"    : 1,
]));
 set_exits( ([
              "east" : ROOMS"room84",
]) );
 set_listen("default", "Deathly silence blankets this place.");
 set_smell("default", "An rocky smell hangs around.");

    set_items( ([
            "picture" : "Not much can be seen from teh back of a picture.",
            "wall" : "A rough type of stone with gouges in it.",
      ]) );

}
int move_picture(string str) {
    if(!str) {
        notify_fail("Move what?\n");
        return 0;

    }
    if(str != "picture") {
        notify_fail("You can't lift that!\n");
        return 0;
    }
    

    message("info", "The picture moves to the side, revealing a way out.", this_player());
    add_exit(ROOMS"castle12", "out");
    call_out("go_hole", 9);
    return 1;
}

void go_hole() {
    message("info", "The picture swings back in place",
all_inventory(this_object()));
    remove_exit("out");
}

