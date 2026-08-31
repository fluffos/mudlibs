#include <std.h>
inherit ROOM;
#include <cp.h>

void create() {
    ::create();
    set_no_clean(1);
    set_short("Grogg Stonebeard's Storage Room");
    set_long("This is the storage room for Grogg Stonebeard.");
    set_exits((["shop" : ROOMS"bsmith"]) );
    new(WEAP"uses_runes/sword")->move(this_object());
    new(WEAP"uses_runes/bow")->move(this_object());
    new(WEAP"uses_runes/knife")->move(this_object());
    new(WEAP"uses_runes/staff")->move(this_object());
}
