#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set("long","%^BOLD%^%^CYAN%^The path changes from a %^RESET%^slate gray %^BOLD%^%^CYAN%^to a %^RESET%^%^RED%^reddish tan cobblestone%^BOLD%^%^CYAN%^. The clouds appear slightly thicker here although testing that theory might not prove wise. The soothing sound of a w%^BLUE%^a%^CYAN%^t%^BLUE%^e%^CYAN%^r can be heard in the area. The path begins to curve in multiple directions.%^RESET%^");
    set_items( ([ "walkway": "%^BOLD%^%^WHITE%^This s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e walkway is magically places for travelers to walk on.%^RESET%^", "clouds": "%^BOLD%^%^WHITE%^The clouds appear slightly thicker here.%^RESET%^" ]) );
    set_exits( ([ "west" : SKYROOM "m4", "northeast" : SKYROOM "m12", "northwest" : SKYROOM "m10" ]) );
}
void reset() {
    ::reset();
    if (!present("cleric", this_object()))
	new(SKYMOB "repenting_cleric")->move(this_object());
    if (!present("monk", this_object()))
	new(SKYMOB "missionary_monk")->move(this_object());
}
