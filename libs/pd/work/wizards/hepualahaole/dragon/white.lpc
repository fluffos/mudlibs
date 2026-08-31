//Dragon quest area
//Nightshade

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Realm of the White Dragon");
    set_properties( (["light" : 2, "night light" : 2]) );
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_listen("default", "A peaceful silence fills the air.");
    set_long("%^RESET%^%^BOLD%^The realm of the white dragon is one of peace and kindness.  %^RESET%^%^BOLD%^They are the ones who help others, having utmost faith in %^RESET%^%^BOLD%^their god.  You have been deemed worthy to join the ranks of %^RESET%^%^BOLD%^the white dragon.  Proceed, child.");
    set_exits( (["enter" : "/d/tirun/dragon_hall"]) );
    add_pre_exit_function("enter", "create_dragon");
    set_items( ([ "entrance" : "The entrance is a swirling vortex."]) );
}

int create_dragon() {
    write("%^RESET%^%^BOLD%^You begin to morph and change, taking the form of a white dragon!");
    this_player()->revive();
    this_player()->set_race("dragon");
    this_player()->set_class("dragon");
    this_player()->set_subclass("white");
    this_player()->init_skills();
    this_player()->fix_skills();
    this_player()->new_body();
    call_out("reroll",1,this_player());
    return 1;
}

void reroll(object tp) {
    tp->force_me("roll stats");
}
