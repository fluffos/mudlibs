#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("armour");
    set("id", ({"armour", "death armour"}) );
    set_short("%^BOLD%^BLACK%^D%^RESET%^BOLD%^e%^RESET%^BOLD%^GREEN%^at%^RESET%^"
      "%^BOLD%^h%^RESET%^ %^BOLD%^BLACK%^Ar%^RESET%^BOLD%^GREEN%^mo%^RESET%^"
      "%^BOLD%^BLACK%^u%^RESET%^BOLD%^r%^RESET%^");
    set_long("The Death Armour is made from human bones and is held into place "
      "by long strips of human flesh.  The armour was crafted by the powerful "
      "Necromancer Galdur.");
    set_type("body armour");
    set_limbs( ({"horns", "tail"}) );
}

int drop() {
    write("%^BOLD%^BLACK%^The Death Armour will not leave its Creator.\n");
    return 1;
}

int give() {
    write("%^BOLD%^BLACK%^The Death Armour will not leave its Creator.\n");
    return 1;
}

int sell() {
    write("%^BOLD%^BLACK%^The Death Armour will not leave its Creator.\n");
    return 1;
}

int query_auto_load() {
    if(this_player()->query_name() == "galdur")
	return 1;
}
