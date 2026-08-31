#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_no_clean(1);
    set_short("HAMENS WEAPON SUPPLY");
    set_long("This is the storage room where armour is kept.");
    set_exits((["west" : ROOMS "hamen_weapon"]) );
    new(WEP "jagged_rock")->move(this_object());
}
