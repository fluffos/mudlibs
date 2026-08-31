#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set("long","%^BOLD%^%^CYAN%^As the path continues, the walkway shifts to a %^RESET%^grayish hue %^BOLD%^%^CYAN%^similar to chalcedony. Off in the distance, a massive structure of %^WHITE%^cloud %^CYAN%^shaped like a volcano can be seen. A benign fluffy trail floats off the top of it. A gentle breeze swirls playfully through the room.%^RESET%^");
    set_items( ([ "walkway": "%^BOLD%^%^WHITE%^This s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e walkway is magically places for travelers to walk on.%^RESET%^", "structure": "%^BOLD%^%^WHITE%^Off in the distance, a massive structure of %^WHITE%^cloud %^CYAN%^shaped like a volcano can be seen.%^RESET%^" ]) );
    set_exits( ([ "east" : SKYROOM "m32", "west" : SKYROOM "m30" ]) );
}
void reset() {
    ::reset();
    if (!present("missionary monk", this_object()))
	new(SKYMOB "missionary_monk")->move(this_object());
    if (!present("penguin", this_object()))
	new(SKYMOB "penguin_2")->move(this_object());
}
