#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_property("no auction", 1);
    set_name("wings");
    set("id", ({"death wings", "wings"}) );
    set_short("%^BOLD%^BLACK%^D%^RESET%^BOLD%^e%^RESET%^a%^BOLD%^t%^RESET%^"
      "%^BOLD%^BLACK%^h%^RESET%^ %^BOLD%^BLACK%^W%^RESET%^i%^BOLD%^n%^RESET%^"
      "%^BOLD%^BLACK%^g%^RESET%^BOLD%^s%^");
    set_long("%^BOLD%^BLACK%^These are the wings of death that carry the "
      "great lord of the shadows, %^BOLD%^RED%^Endbringer%^RESET%^ "
      "%^BOLD%^BLACK%^across the lands.");
    set_type("wing armour");
    set_limbs( ({"left wing", "right wing"}) );
}

int drop() {
    write("%^BOLD%^BLACK%^You cannot remove a part of yourself!%^RESET%^");
    return 1;
}

int sell() {
    write("%^BOLD%^BLACK%^You cannot sell yourself!%^RESET%^");
    return 1;
}

int put() {
    write("%^BOLD%^BLACK%^You cannot store yourself in this!%^RESET%^");
    return 1;
}

int bury() {
    write("%^BOLD%^BLACK%^You cannot bury yourself!%^RESET%^");
    return 1;
}

int query_auto_load() {
    if (this_player()->query_name() == "endbringer")
    {
	return 1;
    }
}
