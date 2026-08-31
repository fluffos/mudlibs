#include <std.h>
inherit ROOM;
#include <arlon2.h>
void create() {
    ::create();
     set_no_clean(1);
    set_short("Arlon Armour Supply");
    set_long("This is the storage room where armour is kept.");
    set_exits((["west" : ROOMS+"20"]) );
    new(ARM"chainmailvest")->move(this_object());
}

