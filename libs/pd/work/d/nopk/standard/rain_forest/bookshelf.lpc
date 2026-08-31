#include <rain.h>
#include <std.h>

inherit ROOM;
create() {
   ::create();
   set_name("secret");
    set_properties( ([ "light" : 2, "night light" : 2]) );
   set_short("Behind the bookcase");
   set_long("A secret room behind the bookcase. Not much to the room, just a small cubby.");
   set_exits((["out" : ROOMS"house1"]));
}

void reset() {
    object money;

    ::reset();
    if(!present("money")) {
        money = new("/std/obj/coins");
        money->set_money("platinum", random(15));
        money->set_money("gold", random(150));
        money->set_money("electrum", random(300));
        money->move(this_object());
    }
}
