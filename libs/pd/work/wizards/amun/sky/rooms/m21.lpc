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
    set("long","%^BOLD%^%^CYAN%^As the path continues, the walkway shifts to a %^RESET%^grayish hue %^BOLD%^%^CYAN%^similar to chalcedony. Off in the distance, a massive structure of %^WHITE%^cloud %^CYAN%^shaped like a volcano can be seen. A benign fluffy trail floats off the top of it. There is an opening at the edge of the path that leads to the pond.%^RESET%^");
    set_items( ([ "walkway": "%^BOLD%^%^WHITE%^This s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e walkway is magically places for travelers to walk on.%^RESET%^", "structure": "%^BOLD%^%^WHITE%^Off in the distance, a massive structure of %^WHITE%^cloud %^CYAN%^shaped like a volcano can be seen.%^RESET%^", "opening" : "%^BOLD%^%^WHITE%^The opening looks big enough for anyone to enter.%^RESET%^" ]) );
    set_exits( ([ "northwest" : SKYROOM "m28", "southwest" : SKYROOM "m12" ]) );
}
int enter_pool(string str) {
    if (!str || str != "pool") return notify_fail("enter what?\n");
    write("%^BOLD%^%^CYAN%^You feel the warm water rush over you as you enter the pool.%^RESET%^");
    this_player()->move_player(SKYROOM "m20");
    return 1;
}
