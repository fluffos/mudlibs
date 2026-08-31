#include <std.h>
#include <castlewall.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Possessed Light");
    set_short("%^BOLD%^%^RED%^Po%^BLACK%^sse%^RED%^sse%^BLACK%^d %^BOLD%^%^YELLOW%^L%^WHITE%^i%^YELLOW%^g%^WHITE%^h%^YELLOW%^t%^RESET%^");
    set_long("%^BOLD%^%^YELLOW%^A large orb of light contained by %^BLACK%^darkness%^YELLOW%^.");
    set_id(({"light"}));
    set_ac(8);            
    set_mass(0);
    set_type("helmet");
    set_curr_value("gold", 0);  
    set_wear("%^BOLD%^%^YELLOW%^L%^WHITE%^i%^YELLOW%^g%^WHITE%^h%^YELLOW%^t envelps your head, blinding you for a moment.%^RESET%^");
    set_remove("%^BOLD%^%^BLACK%^The world darkens for a while as the light leaves you.%^RESET%^");
    set_limbs(({ "head"}));
}
 int query_auto_load() { if (this_player()->query_level() > 89) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 89) return 0;
   write("This belongs to the %^BOLD%^%^BLACK%^Dark %^WHITE%^Archers%^RESET%^!!");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
