#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set("long","%^BOLD%^%^CYAN%^The w%^BLUE%^a%^CYAN%^ter ripples softly with the wind, which causes the fish to rise and fall with the small waves. Being clear as day, it is obvious that this pool has no bottom, instead it opens up into clear blue sky. %^YELLOW%^R%^WHITE%^a%^YELLOW%^ys of l%^WHITE%^i%^YELLOW%^ght %^CYAN%^pour through from not only the top of the pool, but also the bottom. Some fish swim wildly around a patch of vegetation under the water.%^RESET%^");
    set_items( ([ "water": "%^BOLD%^%^CYAN%^The refreshing water ripples softly with the wind.%^RESET%^", "fish": "%^BOLD%^%^GREEN%^Some of the fish are floating in and out of the ripples in the waves, the others are swimming around the vegetation under the water.%^RESET^", "sky" : "%^BOLD%^%^CYAN%^The sky can be seen above and below the pool of water, it is a brilliant blue.%^RESET%^", "vegetation" : "%^BOLD%^%^GREEN%^The plants grow frantically under the water.%^RESET%^", ]) );
    set_exits( ([ "north" : SKYROOM "m27", "east" : SKYROOM "m20", "south" : SKYROOM "m11" ]) );
}
