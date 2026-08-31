#include <std.h>
inherit ROOM;
#include <arlon2.h>
void create() {
    ::create();
     set_no_clean(1);
    set_short("Arlon Supply Supply");
    set_long("This is the storage room where supplies are kept.");
    set_exits((["west" : ROOMS+"27"]) );
    new(OBJ"shoppingbag")->move(this_object());
}

