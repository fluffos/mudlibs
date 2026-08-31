#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 3, "night light" : 1]) );
    set_property("no castle", 0);
    set("short", "Home of the taskmaster");
    set("long",
        "The taskmaster's hut is small and unkept. Several weapons "
        "of torture lie scatered about. The taskmaster also serves "
        "as the law in the orc fortress, torturing any who don't "
        "obey.");
    set_exits( 
                (["east" : ROOMS"south_orcs/path2"]) );
}

void reset() {
  ::reset();
    if(!present("gorilla"))
      new(MOB"gorilla")->move(this_object());
      present("gorilla")->force_me("wield spear");
}
