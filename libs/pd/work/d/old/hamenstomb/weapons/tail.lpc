#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                   
void create() {
    ::create();                                                                       
    set_name("Tail");
    set("id", ({ "tail" }) );
    set("short", "%^RED%^Tail");
    set("long", "%^ORANGE%^This tail is full of poisons as it is from a %^RED%^Red Scorpion%^ORANGE%^." );
    set_type("knife");
    set_weight(10);
    set_curr_value("gold", 50);
    set_wc(7);
    set_type("knife");
    set("skill level", 116);
    add_poisoning(10);
}
int query_auto_load() {
    if (this_player()->query_level() >= 30)
	return 1;
}
