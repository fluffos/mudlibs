#include <std.h>
inherit ARMOUR;
int extra_worn();

void create() {
    ::create();
    set_name("hood");
    set("id", ({ "hood" }) );
    set("short", "%^BLUE%^an executioner's %^RESET%^%^BOLD%^%^BLUE%^hood%^RESET%^");
    set("long", "A long silk hood. Two eye slits have been cut out.");
    set_weight(3);
    set("value", 95);
    set_type("helmet");
    set_limbs( ({ "head" }) );
    set_ac(3);
    set_wear( (: extra_worn :) );
}

int extra_worn() {
    if((int)this_player()->query_alignment() > 0) {
	write("You soul is not evil enough for this hood!");
	say(this_player()->query_cap_name()+" cannot seem to put on the hood.");
	return 0;
    }
    write("Pure evil flows through you body.");
    say(this_player()->query_cap_name() + " dons the executioner's hood.");
    return 1;
}
