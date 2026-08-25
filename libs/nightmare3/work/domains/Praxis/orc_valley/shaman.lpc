#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set_short( "The chamber of the orc shaman");
    set_long(
        "This secret room is the chamber of the orc shaman.  "
        "It is most certain that you should not be here.");
    set_items(
        (["chamber" : "It is a roundish room and dimly lit."]) );
    set_exits( 
	      (["south" : "/domains/Praxis/orc_valley/open",
		"north" : "/domains/Praxis/orc_valley/treasure"]) );
    add_exit("north", "/domains/Praxis/orc_valley/treasure", (: "go_north" :) );
}

void reset() {
    object mon, ob;

    ::reset();
    if(!present("shaman")) {
        mon = new("/domains/Praxis/obj/mon/orc_shaman");
        mon->move(this_object());
        ob = new(OBJECT);
        ob->set_name("key");
        ob->set_id( ({ "key", "stone key", "a stone key", "orc_treasure" }) );
        ob->set_short( "A stone key");
        ob->set_long( "There is nothing special about it.");
        ob->set_mass(190);
        ob->set_value(30);
        ob->move(mon);
    }
}

int go_north() {
    if(!present("shaman")) return 1;
    write("The shaman smashes you as you try to go north!");
    this_player()->add_hp(-(random(10)));
    return 0;
}

