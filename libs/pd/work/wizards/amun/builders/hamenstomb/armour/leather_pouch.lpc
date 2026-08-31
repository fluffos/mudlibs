#include <std.h>
#include <amun.h>
inherit PACK;                                                                    	
void create() {
    ::create();                                                                        

    set_name("Black Leather Pouch");
    set("id", ({"pouch"}) );
    set("short", "%^BOLD%^%^BLACK%^Black Leather Pouch");
    set("long", "%^BOLD%^%^BLACK%^This pouch is pure black and is normally used for arrows, but can fit other things." );
    set_weight(2);
    set_curr_value("gold", 22);
    set_max_internal_encumbrance(500);
}
int query_auto_load() {
    if (this_player()->query_level() >= 26)
	return 1;
}
