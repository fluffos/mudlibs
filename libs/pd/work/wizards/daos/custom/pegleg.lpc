#include <std.h>

inherit ARMOUR;

void create() {    
    ::create();
    set_properties( (["no steal" : 1 ]) );
    set_name("pegleg");
    set("id", ({"pegleg", "pirate's pegleg and a black boot"}) );
    set_short("%^BOLD%^%^BLACK%^a p%^RESET%^i%^BOLD%^ra%^BLACK%^t%^RESET%^e%^BOLD%^'"
      "%^BLACK%^s p%^RESET%^e%^BOLD%^g-%^BLACK%^l%^RESET%^%^BOLD%^e%^RESET%^g wi"
      "%^BLACK%^%^BOLD%^t%^RESET%^%^BOLD%^h a %^BLACK%^b%^RESET%^l%^BOLD%^%^BLACK%^a"
      "%^RESET%^c%^BOLD%^%^BLACK%^k b%^RESET%^%^BOLD%^o%^RESET%^o%^BOLD%^%^BLACK%^t"
      "%^RESET%^");
    set_long("Well, look at this here item! Argh, it looks to be a wooden peg leg, "
      "and a black boot to go with it!  What a scurvy mate must be enjoying this "
      "treasure!  Yo ho, me hardies, yo ho!");
    set_type("boots");
    set_limbs( ({"right leg", "right foot"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "ruthless")
	return 1;
}
