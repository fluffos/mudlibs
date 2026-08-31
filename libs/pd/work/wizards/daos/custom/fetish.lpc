#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("fetish");
    set("id", ({"fetish", "horrible fetish"}) );
    set_short("%^BOLD%^BLACK%^A Horrible Fetish");
    set_long("This Horrible Fetish is made of a simple leather cord adorned "
      "with the eyes and ears of humanoids.");
    set_type("necklace");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "furion")
	return 1;
}
