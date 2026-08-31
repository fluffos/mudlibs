#include <std.h>
#include <amun.h>
inherit ROOM;
int foundboom;
void init() {
    ::init();
    add_action("search_willow", "search");
}
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set("long","%^BOLD%^%^CYAN%^A %^WHITE%^s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e %^CYAN%^walkway is magically placed in the %^WHITE%^clouds %^CYAN%^offering a walking path for travelers. Standing on the side of this path is a large %^RESET%^%^GREEN%^w%^ORANGE%^ee%^GREEN%^p%^ORANGE%^i%^GREEN%^ng w%^ORANGE%^i%^GREEN%^ll%^ORANGE%^o%^GREEN%^w%^BOLD%^%^CYAN%^, with it's branches hanging down towards the ground. There is a c%^WHITE%^oo%^CYAN%^l breeze that makes the branches sway slightly and the %^WHITE%^clouds %^CYAN%^to shift. This is a very calm and serene area.%^RESET%^");
    set_items( ([ "walkway": "%^BOLD%^%^WHITE%^This s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e walkway is magically places for travelers to walk on.%^RESET%^", "willow": "%^BOLD%^%^GREEN%^This %^RESET%^%^GREEN%^w%^ORANGE%^ee%^GREEN%^p%^ORANGE%^i%^GREEN%^ng w%^ORANGE%^i%^GREEN%^ll%^ORANGE%^o%^GREEN%^w%^BOLD%^%^GREEN%^ is magically standing with it's branches drooping down to the edge of the %^WHITE%^clouds%^GREEN%^.%^RESET%^", "clouds" : "%^BOLD%^%^WHITE%^These clouds are light and fluffy. They offer a soft pillow for those that wish to venture off the path.%^RESET%^." ]) );
    set_exits( ([ "west" : SKYROOM "m2", "east" : SKYROOM "m4", "south" : SKYROOM "rs_11" ]) );
}
void reset() {
    ::reset();
    if (!present("monk", this_object()))
	new(SKYMOB "working_monk")->move(this_object());
    if (!present("priest", this_object()))
	new(SKYMOB "priest")->move(this_object());
    foundboom=0; 
}
int search_willow(string str) {
    if (!str || str != "willow") return notify_fail("search what?\n");
    if (!foundboom) {
	foundboom=1;
	write("%^RESET%^%^ORANGE%^You search the weeping willow and find a boomerang.%^RESET%^");
	new(SKYWEP "boomerang")->move(environment(this_player())); 
    } 
    else { 
	write("You search but find nothing in your search."); 
    }
    return 1;
}   
