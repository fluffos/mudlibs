#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("necklace");
    set("id", ({"necklace", "pendant", "heart of time"}) );
    set_short("%^RED%^H%^RESET%^BOLD%^RED%^ear%^RESET%^RED%^t%^RESET%^ "
      "%^BOLD%^YELLOW%^of%^RESET%^ %^BOLD%^BLACK%^T%^RESET%^BOLD%^im%^RESET%^"
      "%^BOLD%^BLACK%^e%^RESET%^");
    set_long("This pendant is completely made out of diamond links, leading "
      "down to the small hourglass which sand moves swiftly through, representing "
      "the flow of time.  The hourglass is made out of a rare %^BOLD%^BLUE%^blue%^"
      "%^RESET%^ diamond, the %^RED%^red%^RESET%^ sand inside lets off an aura of "
      "power.  Magical words seem to %^BOLD%^YELLOW%^glow%^RESET%^ on one of the "
      "diamond links, the words read, %^BOLD%^'%^RESET%^Hail Tarent, who stole "
      "Time%^BOLD%^'%^RESET%^.");
    set_type("necklace");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "tarent")
	return 1;
}
