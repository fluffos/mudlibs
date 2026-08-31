#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("sash");
    set("id", ({"sash", "sash of flame"}) );
    set_short("%^BOLD%^%^YELLOW%^S%^RED%^a%^RESET%^%^ORANGE%^s%^RED%^h %^YELLOW%^o%^BOLD%^%^RED%^f %^BOLD%^YELLOW%^F%^RESET%^BOLD%^RED%^l%^RESET%^"
      "%^ORANGE%^a%^RESET%^RED%^m%^RESET%^BOLD%^YELLOW%^e%^RESET%^");
    set_long("The sash flickers with an eternal flame never burning the "
      "wearer.  Faces of doomed souls try to reach out and call for help only "
      "to be consumed by the flames once again.");
    set_type("sash");
    set_limbs( ({"torso"}) );
    set_wear("The flames adjust to fit your body.");
    set_remove("The soul's constant screaming drives you insane.");
}

int drop() {
    write("The flames refuse to leave your presence.\n");
    return 1;
}

int give() {
    write("The flames refuse to leave your presence.\n");
    return 1;
}

int sell() {
    write("The flames refuse to leave your presence.\n");
    return 1;
}

int query_auto_load() {
    if(this_player()->query_name() == "crem")
	return 1;
}
