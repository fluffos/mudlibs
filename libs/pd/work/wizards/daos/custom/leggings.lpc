#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("leggings");
    set("id", ({"leggings", "bone leggings"}) );
    set_short("%^BOLD%^B%^RESET%^BOLD%^BLACK%^on%^RESET%^e %^BOLD%^WHITE%^Le"
      "%^RESET%^g%^BOLD%^BLACK%^g%^RESET%^i%^BOLD%^BLACK%^n%^RESET%^g%^BOLD%^s%^"
      "%^RESET%^");
    set_long("These leggings seem to be made from old bones.  They may not give "
      "much protection, but they are still wearable none the less.  These leggings "
      "were made to be worn by Lac.");
    set_type("leggings");
    set_limbs( ({"right foreleg", "left foreleg", "right rear leg", 
	"left rear leg"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "lac")
	return 1;
}
