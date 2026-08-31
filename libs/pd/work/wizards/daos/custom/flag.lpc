#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("flag");
    set_short("%^BOLD%^RED%^A%^RESET%^BOLD%^m%^RESET%^BOLD%^BLUE%^e%^RESET%^BOLD%^RED%^r%^RESET%^BOLD%^i%^RESET%^BOLD%^BLUE%^c%^RESET%^BOLD%^RED%^a%^RESET%^BOLD%^n%^RESET%^ %^BOLD%^BLUE%^F%^RESET%^BOLD%^RED%^l%^RESET%^BOLD%^a%^RESET%^BOLD%^BLUE%^g%^RESET%^");
    set_long("%^BOLD%^RED%^O%^RESET%^BOLD%^l%^RESET%^BOLD%^BLUE%^d%^RESET%^ %^BOLD%^RED%^G%^RESET%^BOLD%^l%^RESET%^BOLD%^BLUE%^o%^RESET%^BOLD%^RED%^r%^RESET%^BOLD%^y%^RESET%^");
    set_id(({"flag"}));
    set_type("robes");
    set_limbs(({"torso"}));
}
int query_auto_load() { 
    if(this_player()->query_level() > 1 && this_player()->query_race() ==
      "demon" && this_player()->query_guild() == "AoD")
	return 1;
}

