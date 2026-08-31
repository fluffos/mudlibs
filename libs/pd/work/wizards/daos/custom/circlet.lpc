#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("circlet");
    set("id", ({"circlet", "psionic circlet"}) );
    set_short("A %^BOLD%^%^BLUE%^P%^RESET%^%^BOLD%^%^BLACK%^s%^RESET%^"
      "%^BOLD%^%^BLUE%^i%^RESET%^o%^BOLD%^%^BLUE%^n%^RESET%^i%^"
      "%^BOLD%^%^BLUE%^c%^RESET%^ %^BOLD%^%^BLUE%^C%^RESET%^%^BOLD%^%^RED%^i%^RESET%^"
      "%^BOLD%^%^BLACK%^r%^RESET%^c%^%^BOLD%^BLACK%^l%^RESET%^%^BOLD%^%^RED%^e%^RESET%^"
      "%^BOLD%^%^BLUE%^t%^RESET%^");
    set_long("The %^BOLD%^%^BLUE%^c%^RESET%^%^BOLD%^%^RED%^i%^RESET%^"
      "%^BOLD%^%^BLACK%^r%^RESET%^c%^%^BOLD%^%^BLACK%^l%^RESET%^"
      "%^BOLD%^%^RED%^e%^RESET%^%^BOLD%^%^RED%^t%^RESET%^ "
      "%^BOLD%^%^YELLOW%^glows%^RESET%^ with a %^BOLD%^%^BLUE%^blue%^RESET%^ "
      "%^BOLD%^%^YELLOW%^aura,%^RESET%^ %^BOLD%^%^BLACK%^spreading%^RESET%^ "
      "its %^BOLD%^%^BLUE%^p%^RESET%^%^BOLD%^%^BLACK%^s%^RESET%^"
      "%^BOLD%^%^BLUE%^i%^RESET%^o%^%^BOLD%^%^BLUE%^n%^RESET%^i%^"
      "%^BOLD%^%^BLUE%^c%^RESET%^ waves in the %^BOLD%^%^WHITE%^air%^RESET%^. "
      "As you %^BOLD%^%^YELLOW%^look%^RESET%^ at the %^BOLD%^%^BLUE%^c%^RESET%^"
      "%^BOLD%^%^RED%^i%^RESET%^%^BOLD%^%^BLACK%^r%^RESET%^"
      "c%^%^BOLD%^%^BLACK%^l%^RESET%^%^BOLD%^%^RED%^e%^RESET%^"
      "%^BOLD%^%^BLUE%^t%^RESET%^ it %^BOLD%^%^BLACK%^draws you toward%^RESET%^ "
      "it.  It can only be %^BOLD%^%^BLACK%^worn%^RESET%^ by those with the "
      "%^BOLD%^%^RED%^greatest%^RESET%^ of %^BOLD%^%^BLUE%^p%^RESET%^"
      "%^BOLD%^%^BLACK%^s%^RESET%^%^BOLD%^%^BLUE%^i%^RESET%^ "
      "%^BOLD%^%^BLACK%^energy%^RESET%^.");
    set_type("helmet");
    set_limbs( ({"head"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "alchemon")
	return 1;
}
