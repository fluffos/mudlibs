#include <std.h>
#include <ether.h>
inherit ARMOUR;

int align;

void create() {
    ::create();
    set("id", ({"holy","holy ring","holyring","ring"}) );
    set_name("Holy Ring");
    set_short("%^YELLOW%^Ho%^RESET%^%^ORANGE%^l%^RESET%^y r%^ORANGE%^i%^YELLOW%^ng%^RESET%^");
    set_long(
	"The %^YELLOW%^Ho%^RESET%^%^ORANGE%^l%^RESET%^y r%^ORANGE%^i%^YELLOW%^ng%^RESET%^"
	" was a gift from the angels.");
    set_type("ring");
    set_limbs( ({"left hand","right hand"}) );
    set_ac(1);
    set_mass(1);
    set_wear("%^BOLD%^%^WHITE%^You begin to feel more holy as you slide the ring onto your finger.%^RESET%^");
    set_remove("%^BOLD%^%^WHITE%^Your aura of holiness has left you!");
}
int query_auto_load() { 
    if(this_player()->query_level() < 36) return 0;
    return 1;
}


