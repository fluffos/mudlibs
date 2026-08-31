#include <std.h>
#include <purgatory.h>

inherit ROOM;
void init() {
    ::init();
    add_action("open_door", "open");
}
void create() {
    ::create();
     set_name("guest3");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^This is the central hallway of the Guest Quarters. Down this "
"%^ORANGE%^hallway, the more prominent families call this home for the "
"%^ORANGE%^duration of their stay. A large oak door rests in the east "
"%^ORANGE%^wall. A walkway leads to the north and the south. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"guest4", 
              "south" : ROOMS"guest2"]) );

    set_items( ([
        "door" : "The door looks to be unlocked, maybe you could open it.",
        "walkway" : "%^BOLD%^%^BLACK%^Many dark stones form a walkway into the guest quarters, years of use have polished the stone to a high sheen."
      ]) );


}


int open_door(string str) {
    if(!str) {
        notify_fail("open what?\n");
        return 0;

    }
    if(str != "door") {
        notify_fail("You can't open that!\n");
        return 0;
    }
    
    message("info", (string)this_player()->query_cap_name()+" opens a door.", this_object(), ({ this_player() }));
    message("info", "You open a door.", this_player());
    add_exit(ROOMS"guest29", "enter");
    call_out("go_hole", 60);
    return 1;
}

void go_hole() {
    message("info", "The door is closed by a cold gust of wind.",
all_inventory(this_object()));
    remove_exit("enter");
}
