#include <std.h>
#include <purgatory.h>

inherit ROOM;
void init() {
    ::init();
    add_action("move_body", "move");
}
void create() {
    ::create();
     set_name("guest42");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^The corpses of the most recent battle have been strewn into "
"%^ORANGE%^this room by careless warriors. Lifeless bodies lay about the "
"%^ORANGE%^floor and one has been hung up on the wall. Flies make a "
"%^ORANGE%^thick carpet over most of the room.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
     set_smell("default", "The stench of rotting flesh permeates the air.");
 set_exits( (["west" : ROOMS"guest25"]) );

    set_items( ([
            "bodies" : "These bodies look to have rotted as far as they can and have started to mummify the rest of the way.",
            "body" : "This one body has been hung up on the wall as if to cover up something."
      ]) );


}
int move_body(string str) {
    if(!str) {
        notify_fail("Move what?\n");
        return 0;

    }
    if(str != "body") {
        notify_fail("You can't move that!\n");
        return 0;
    }
    
    message("info", (string)this_player()->query_cap_name()+" moves a body to the side.", this_object(), ({ this_player() }));
    message("info", "A bit of flesh sticks to your hand as you move the body aside.", this_player());
    add_exit(ROOMS"guest8", "hole");
    call_out("go_hole", 10);
    return 1;
}

void go_hole() {
    message("info", "The body slides back in place with a sickening sound.",
all_inventory(this_object()));
    remove_exit("hole");
}
