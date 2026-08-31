#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("ring");
    set("id", ({"ring", "drakules ring"}) );
    set_short("%^BOLD%^BLACK%^Dr%^RESET%^RED%^ak%^RESET%^BOLD%^RED%^ul%^RESET%^e"
      "%^BOLD%^RED%^'s%^RESET%^ %^RED%^Ri%^RESET%^BOLD%^BLACK%^ng%^RESET%^");
    set_long("%^BOLD%^BLACK%^This is a%^RESET%^ %^BOLD%^RED%^fl%^RESET%^BOLD"
      "%^YELLOW%^a%^RESET%^BOLD%^m%^RESET%^BOLD%^YELLOW%^i%^RESET%^BOLD%^RED%^ng"
      "%^RESET%^ ring of the dragon Drakule.  %^BOLD%^BLACK%^The words SAOTBCIMC are "
      "blazed in%^RESET%^ %^BOLD%^RED%^red%^RESET%^ across it.");
    set_type("ring");
    set_limbs( ({"right hand", "left hand"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "drakule")
	return 1;
}
