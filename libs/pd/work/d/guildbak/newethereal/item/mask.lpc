#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("aurorean mask");
    set("id", ({ "mask" }) );
    set("short", "%^RED%^A%^BOLD%^u%^RESET%^%^ORANGE%^r%^YELLOW%^o%^RESET%^%^GREEN%^r%^BOLD%^e%^CYAN%^a%^BLUE%^n%^RESET%^ %^BLUE%^M%^MAGENTA%^a%^BOLD%^s%^RESET%^%^RED%^k%^RESET%^");
    set("long", "%^MAGENTA%^This mask was created by %^RED%^A%^BOLD%^u%^YELLOW%^r%^GREEN%^o%^CYAN%^r%^BLUE%^a%^RESET%^%^MAGENTA%^, the Goddess of dawn for the Ethereal. It emits beautiful arches of light which protect its wearer well.%^RESET%^");
    set_ac(4);
    set_limbs( ({ "head" }) );
    set_weight(1);
    set_curr_value("gold", 2);
    set_type("mask");
}

int query_auto_load() {
    if(this_player()->query_guild() == "ethereal") {
	return 1;
    }
}

