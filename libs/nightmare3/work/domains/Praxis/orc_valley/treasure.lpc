#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set_smell_string("default", "It smells very musty in here.");
    set_short( "Treasury of the Valley Orcs");
    set_long(
        "This small vault where the orc of the valley keep their "
        "treasure is poorly lit and littered with dust, making you well "
        "aware that the orcs willingly allow anyone in here.");
    set_items(
        (["vault" : "It is very, very dimly lit."]) );
    set_exits( (["south" : "/domains/Praxis/orc_valley/shaman"]) );
    set_no_clean(1);
    set_property("no teleport", 1);
}

void reset() {
    ::reset();
      if(!present("chest")) 
	new("/domains/Praxis/obj/misc/chest")->move(this_object());
    present("chest", this_object())->set_closed(0);
      if(!present("orcslayer", present("chest")))
        new("/domains/Praxis/obj/weapon/orc_slayer")->move(present("chest"));
      present("chest")->set_closed(1);
}
