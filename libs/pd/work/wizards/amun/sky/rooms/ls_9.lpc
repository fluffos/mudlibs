#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^This room has large %^GREEN%^t%^RESET%^%^ORANGE%^r%^BOLD%^%^GREEN%^ees %^WHITE%^placed around a bench, allowing shade to encompass the area. A cool breeze ruffles the leaves and make the area pleasant and peaceful. The bench looks comfortable, with its soft %^MAGENTA%^cusion %^WHITE%^and its %^CYAN%^pillows%^WHITE%^. The bench seems to have a slight %^YELLOW%^glow %^WHITE%^to it.%^RESET%^");
    set_items( ([ "trees": "%^BOLD%^%^WHITE%^The large %^GREEN%^t%^RESET%^%^ORANGE%^r%^BOLD%^%^GREEN%^ees %^WHITE%^are placed around a bench, allowing shade to encompass the area.%^RESET%^" ]) );
    set_exits( ([ "north" : SKYROOM "ls_8" ]) );
    new(SKYOBJ "bench")->move(this_object());
}
