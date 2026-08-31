#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_no_clean(1);
    set_short("SKY TEMPLE ARMOUR SUPPLY");
    set_long("This is the storage room where armour is kept.");
    set_exits((["northwest" : SKYROOM "armour_shop"]) );
    new(SKYARM "monk_robe")->move(this_object());
    new(SKYARM "pygmy_cap")->move(this_object());
    new(SKYARM "paw_warmers")->move(this_object());
}
