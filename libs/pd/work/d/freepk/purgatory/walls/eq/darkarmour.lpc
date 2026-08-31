//Nutcases RULE
#include <std.h>
#include <castlewall.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Dark Armour");
    set_short("%^BOLD%^%^BLACK%^Dark Armour%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This armour was provided by the Royal Magician to his leigons of archers and warriors for their service in protecting their city.%^RESET%^");
    set_id(({"armour", "dark armour"}));
    set_ac(11);            
    set_mass(55);
    set_type("body armor");
    set_curr_value("gold", 100+random(69));  
    set_wear("%^BOLD%^%^BLACK%^The magicial energies of the evil magician seep into your body as you wear the Dark Armour.") ;
    set_remove("%^BOLD%^%^WHITE%^Your body relaxes as the evil energies release their hold on your body.");
    set_limbs(({ "torso","first arm", "second arm", "third arm", "fourth arm"}));
}
 int query_auto_load() { if (this_player()->query_level() > 50) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 50) return 0;
   write("This belongs to the %^BOLD%^%^BLACK%^Dark %^WHITE%^Archers%^RESET%^!!");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
