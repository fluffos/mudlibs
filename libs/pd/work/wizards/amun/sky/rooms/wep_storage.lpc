#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_no_clean(1);
    set_short("SKY TEMPLE'S WEAPON SUPPLY");
    set_long("This is the storage room where weapons are kept.");
    set_exits((["northeast" : SKYROOM "weapon_shop"]) );
    new(SKYWEP "ivory_scepter")->move(this_object());
    new(SKYWEP "mahogany_staff")->move(this_object());
    new(SKYWEP "ribbed_bow")->move(this_object());
}
