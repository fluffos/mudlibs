#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("A Mutilated Soul");
    set_short("%^BOLD%^A%^RESET%^ %^BOLD%^BLACK%^M%^RESET%^BOLD%^u%^RESET%^BOLD%^BLACK%^t"
      "%^RESET%^BOLD%^i%^RESET%^BOLD%^BLACK%^l%^RESET%^BOLD%^a%^RESET%^BOLD%^BLACK%^t"
      "%^BOLD%^e%^RESET%^BOLD%^BLACK%^d%^RESET%^ %^BOLD%^S%^RESET%^BOLD%^BLACK%^o%^RESET%^"
      "%^BOLD%^u%^RESET%^BOLD%^BLACK%^l%^RESET%^");
    set_long("%^BOLD%^BLACK%^This poor soul has been captured by the demented "
      "assassin, Wraith.  It has been forced to protect its owner at the cost of its own "
      "energies.  You can see the torment and despair surrounding the soul in "
      "the form of crackling and hateful energies.%^RESET%^");
    set_id(({"soul"}));
    set_type("leggings");
    set_curr_value("gold", 0);  
    set_wear("%^BOLD%^BLACK%^The soul screams in torment as it does your bidding.%^RESET%^");
    set_remove("%^BOLD%^WHITE%^The soul retreats back into the beyond.%^RESET%^");
    set_limbs(({ "head", "first hand", "second hand", "third hand", "fourth hand",
	"first arm", "second arm", "third arm", "fourth arm", "torso", "abdomen",
	"right foreleg", "left foreleg", "right rear leg", "left rear leg"}));
}

int query_auto_load() {
    if(this_player()->query_level() > 35) 
	return 1;
}

int slap_on_the_wrist(string str) {
    if (!str || present(str, this_player()) != this_object()) return 0;
    if (this_player()->query_name() != "Wraith") return 0;
    write("%^BOLD%^BLACK%^You can't wear that, it's a SOUL you moron!");
    say(this_player()->query_cap_name()+" sings: Im a little teapot, short and
stout!", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
