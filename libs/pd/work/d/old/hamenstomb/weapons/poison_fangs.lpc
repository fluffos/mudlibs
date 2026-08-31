#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                   
void create() {
    ::create();                                                                       
    set_name("Poison Fangs");
    set("id", ({ "fang","knife", "fangs" }) );
    set("short", "%^BOLD%^%^WHITE%^P%^BLACK%^oi%^WHITE%^s%^BLACK%^o%^WHITE%^n F%^BLACK%^a%^WHITE%^ngs");
    set("long", "%^ORANGE%^These are the fangs of a rattlesnake." );
    set_type("knife");
    set_weight(10);
    set_curr_value("gold", 50);
    set_wc(7);
    set_type("knife");
    set("skill level", 134);
    add_poisoning(10);
}
int query_auto_load() {
    if (this_player()->query_level() >= 28)
	return 1;
}
