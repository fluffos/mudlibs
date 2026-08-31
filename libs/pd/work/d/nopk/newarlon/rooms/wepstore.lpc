#include <std.h>
inherit ROOM;
#include <arlon2.h>
void create() {
    ::create();
     set_no_clean(1);
    set_short("Arlon Weapon Supply");
    set_long("This is the storage room where weapons are kept.");
    set_exits((["west" : ROOMS+"26"]) );
    new(WEP"sharpsword")->move(this_object());
}

