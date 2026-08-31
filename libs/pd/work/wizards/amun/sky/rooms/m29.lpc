#include <std.h>
#include <amun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("enter_pool", "enter");
}
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set("long","%^BOLD%^%^CYAN%^The path changes from a %^RESET%^slate gray %^BOLD%^%^CYAN%^to a %^RESET%^%^RED%^reddish tan cobblestone%^BOLD%^%^CYAN%^. There is an opening at the edge of the path that leads to the pond. The path begins to curve in multiple directions. The soothing sound of a w%^BLUE%^a%^CYAN%^t%^BLUE%^e%^CYAN%^r can be heard in the area.%^RESET%^");
    set_items( ([ "walkway": "%^BOLD%^%^WHITE%^This s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e walkway is magically places for travelers to walk on.%^RESET%^", "opening": "%^BOLD%^%^WHITE%^The opening looks big enough for anyone to enter.%^RESET%^" ]) );
    set_exits( ([ "southwest" : SKYROOM "m22", "east" : SKYROOM "m30" ]) );
}
int enter_pool(string str) {
    if (!str || str != "pool") return notify_fail("enter what?\n");
    write("%^BOLD%^%^CYAN%^You feel the warm water rush over you as you enter the pool.%^RESET%^");
    this_player()->move_player(SKYROOM "m24");
    return 1;
}
void reset() {
    ::reset();
    if (!present("praying monk", this_object()))
	new(SKYMOB "praying_monk")->move(this_object());
    if (!present("priest", this_object()))
	new(SKYMOB "priest")->move(this_object());
}
