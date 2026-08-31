//Dragon quest area
//Nightshade

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Realm of the Red Dragon");
    set_properties( (["light" : 2, "night light" : 2]) );
    set_property("indoors", 1);
    set_property("no gate", 1);
    set_listen("default", "Fire can be heard crackling all around.");
    set_long("%^RESET%^%^RED%^The realm of the red dragon is one of combat and of honor.  %^RED%^They are the ones who hold true only to themselves, keeping %^RED%^themselves as the highest of fighters.  You have been deemed %^RED%^worthy to join the ranks of the red dragon.  Proceed, child.");
    set_exits( (["enter" : "/d/tirun/dragon_hall"]) );
    add_pre_exit_function("enter", "create_dragon");
    set_items( ([ "entrance" : "The entrance is a swirling vortex."]) );
}

int create_dragon() {
    write("%^RESET%^%^BOLD%^You begin to morph and change, taking the form of a red dragon!");
    this_player()->revive();
    this_player()->set_race("dragon");
    this_player()->set_class("dragon");
    this_player()->set_subclass("red");
    this_player()->init_skills();
    this_player()->fix_skills();
    this_player()->new_body();
    call_out("reroll",1,this_player());
    return 1;
}

void reroll(object tp) {
    tp->force_me("roll stats");
}
