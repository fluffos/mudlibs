#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("ring");
    set("id", ({ "ring" }) );
    set("short", "%^BLUE%^Et%^BOLD%^he%^CYAN%^r%^WHITE%^ea%^CYAN%^l%^BOLD%^%^BLUE%^ Ri%^RESET%^%^BLUE%^ng%^RESET%^");
    set("long", "%^CYAN%^This ring was created by the Ethereal's Leader, Kumi, as an identifying marker for all of Ethereal. Wearing one without being Ethereal could bring death upon you.%^RESET%^");
    set_ac(2);
    set_limbs( ({ "left hand", "right hand" }) );
    set_weight(1);
    set_curr_value("gold", 10);
    set_type("ring");
}

int query_auto_load() {
    if(this_player()->query_guild() == "ethereal") {
	return 1;
    }
}

