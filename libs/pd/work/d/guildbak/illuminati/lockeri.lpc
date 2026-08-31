#include <std.h>

inherit LOCKER;

void create() {
    set_path("/adm/save/votes/illuminatistorage");
    ::create();
    set_properties( ([ "light" : 2, "no teleport":1, "indoors":1]) );
    set("short", "Illuminati Storage Room");
    set("long",
        "%^RESET%^%^ORANGE%^The Illuminati storage room. Lockers cover 32 of "
"the 4 walls and each is labeled with a name. Members may %^BOLD%^%^WHITE%^<store [item]>%^RESET%^%^ORANGE%^ and "
"%^BOLD%^%^WHITE%^<reclaim>%^RESET%^%^ORANGE%^ it later.%^RESET%^");
    set_items( ([ "crate" : "Large wooden boxes with locked doors." ]) );
    set_exits(([
      "northeast" : "/d/guilds/illuminati/new/floor3"
    ]));
}
