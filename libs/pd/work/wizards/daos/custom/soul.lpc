#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("ring");
    set("id", ({"ring", "soul stone"}) );
    set_short("%^BOLD%^GREEN%^S%^RESET%^BOLD%^BLACK%^ou%^RESET%^BOLD%^GREEN%^l"
      "%^RESET%^ %^BOLD%^RED%^St%^RESET%^BOLD%^BLACK%^o%^RESET%^BOLD%^RED%^ne%^RESET%^");
    set_long("The %^BOLD%^GREEN%^s%^RESET%^BOLD%^BLACK%^ou%^RESET%^BOLD%^GREEN%^l"
      "%^RESET%^ %^BOLD%^RED%^st%^RESET%^BOLD%^BLACK%^o%^RESET%^BOLD%^RED%^ne%^RESET%^ "
      "swirls with the %^BOLD%^GREEN%^s%^RESET%^BOLD%^BLACK%^oul%^RESET%^BOLD%^GREEN%^s"
      "%^RESET%^ of slain foes, %^RED%^fu%^RESET%^ORANGE%^e%^RESET%^RED%^l%^RESET%^"
      "%^ORANGE%^i%^RESET%^RED%^ng%^RESET%^ power of the one who bears it.");
    set_type("ring");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "orcha")
	return 1;
}
