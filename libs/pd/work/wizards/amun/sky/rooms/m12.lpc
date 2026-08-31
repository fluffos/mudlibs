#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set("long","%^BOLD%^%^CYAN%^The %^WHITE%^clouds %^CYAN%^along the path start to thin, becoming faint and wispy. The light all around becoming ever more intense. The cobblestone path flows seamlessly into a shiny quartz. The path begins to curve to the northeast.%^RESET%^");
    set_items( ([ "walkway": "%^BOLD%^%^WHITE%^This s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e walkway is magically places for travelers to walk on.%^RESET%^" ]) );
    set_exits( ([ "northeast" : SKYROOM "m21", "southwest" : SKYROOM "m5" ]) );
}
void reset() {
    ::reset();
    if (!present("monk", this_object()))
	new(SKYMOB "praying_monk")->move(this_object());
    if (!present("priest", this_object()))
	new(SKYMOB "priest")->move(this_object());
}
