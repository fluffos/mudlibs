//Dragon quest area
//Nightshade

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Realm of the Blue Dragon");
    set_properties( (["light" : 2, "night light" : 2]) );
    set_property("indoors", 1);
    set_property("no gate", 1);
    set_listen("default", "The sound of merryment fills the room.");
    set_long("%^BOLD%^%^BLUE%^The realm of the blue dragon is one of mirth and happiness.  %^BOLD%^%^BLUE%^They live their lives to the fullest.  The blue dragons are %^BOLD%^%^BLUE%^rare, yet are the most loved because of their joyful lives.  %^BOLD%^%^BLUE%^You have been deemed worthy to join the ranks of the blue %^BOLD%^%^BLUE%^dragon.  Proceed, child.");
    set_exits( (["enter" : "/d/tirun/dragon_hall"]) );
    add_pre_exit_function("enter", "create_dragon");
    set_items( ([ "entrance" : "The entrance is a swirling vortex."]) );
}

int create_dragon() {
    write("%^RESET%^%^BOLD%^You begin to morph and change, taking the form of a blue dragon!");
    this_player()->revive();
    this_player()->set_race("dragon");
    this_player()->set_class("dragon");
    this_player()->set_subclass("blue");
    this_player()->init_skills();
    this_player()->fix_skills();
    this_player()->new_body();
    call_out("reroll",1,this_player());
    return 1;
}

void reroll(object tp) {
    tp->force_me("roll stats");
}
