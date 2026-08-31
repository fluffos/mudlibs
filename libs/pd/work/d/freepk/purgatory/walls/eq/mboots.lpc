#include <std.h>
#include <castlewall.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Mystical Boots");
    set_short("%^BOLD%^%^BLACK%^My%^RESET%^%^CYAN%^sti%^BOLD%^%^BLACK%^ca%^RESET%^%^CYAN%^l B%^BOLD%^%^BLACK%^oo%^RESET%^%^CYAN%^ts%^RESET%^");
    set_long("These boots were given to the Purgatory Watchmen by the Royal Mage, in hopes of their continued service. %^BOLD%^%^BLACK%^Dark%^RESET%^ %^RESET%^%^RED%^ene%^ORANGE%^rgie%^RED%^s%^RESET%^ swirl around the beaten leather.");
    set_id(({"boots", "mystical boots"}));
    set_ac(4);            
    set_mass(35);
    set_type("boots");
    set_curr_value("gold", 80+random(10));  
    set_wear("%^BOLD%^%^BLACK%^The dark %^RESET%^%^RED%^ene%^ORANGE%^rgie%^RED%^s%^BOLD%^%^BLACK%^ from the boots send tendrils of pain up your legs.") ;
    set_remove("%^BOLD%^%^WHITE%^You gasp as you take the boots off.%^RESET%^");
    set_limbs(({ "right foot", "left foot"}));
}
 int query_auto_load() { if (this_player()->query_level() > 49) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 50) return 0;
   write("You are too little to wear these boots!");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
