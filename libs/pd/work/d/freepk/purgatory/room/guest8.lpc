#include <std.h>
#include <purgatory.h>

inherit ROOM;
void init() {
    ::init();
    add_action("move_hanging", "move");
    add_action("rub_leaf", "rub");
}
void create() {
    ::create();
     set_name("guest8");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^A large angled wall forms a point at the end of the hallway. "
"%^ORANGE%^Potted plants and light wall hangings decorate the otherwise "
"%^ORANGE%^bare room. The walkway leads back to the south.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
     set_listen("default", "Voices can be heard nearby."),
 set_exits( (["south" : ROOMS"guest7"]) );

    set_items( ([
        "plants" : "%^GREEN%^Large plants are gathered in one corner, one of them looks strangely out of place.",
        "plant" : "%^GREEN%^The leaves of this plant are wierdly shiny, as if someone had been rubbing them smooth.",
        "hangings" : "The wall hangings look loosly attached to the wall and flap in the small breeze.",
        "walkway" : "%^BOLD%^%^BLACK%^Many dark stones form a walkway into the guest quarters, years of use have polished the stone to a high sheen."
      ]) );


}
int move_hanging(string str) {
    if(!str) {
        notify_fail("Move what?\n");
        return 0;

    }
    if(str != "hanging") {
        notify_fail("You can't Move that!\n");
        return 0;
    }
    
    message("info", (string)this_player()->query_cap_name()+" moves a hanging aside.", this_object(), ({ this_player() }));
    message("info", "The hanging moves aside.", this_player());
    add_exit(ROOMS"guest33", "northeast");
    call_out("go_hole", 10);
    return 1;
}

void go_hole() {
    message("info", "The hanging flops back against the wall",
all_inventory(this_object()));
    remove_exit("northeast");
}

int rub_leaf(string str) {
    if(!str) {
        notify_fail("Rub what?\n");
        return 0;

    }
    if(str != "leaf") {
        notify_fail("You can't rub that!\n");
        return 0;
    }
    
    message("info", (string)this_player()->query_cap_name()+" plays with a plant", this_object(), ({ this_player() }));
    message("info", "A small doorway opens up next to the plant.", this_player());
    add_exit(ROOMS"guest42", "doorway");
    call_out("go_doorway", 10);
    return 1;
}

void go_doorway() {
    message("info", "The doorway closes quickly.",
all_inventory(this_object()));
    remove_exit("doorway");
}
