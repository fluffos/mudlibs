#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Spider Leggings");
    set_short("%^BOLD%^%^RED%^S%^BLACK%^p%^RED%^i%^BLACK%^d%^RED%^e%^BLACK%^r%^WHITE%^ Leggings%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These are dark steel leggings that have had a giant spider engraved upon them.%^RESET%^");
    set_id(({"leggings", "spider leggings"}));
    set_ac(4);            
    set_mass(35);
    set_type("leggings");
    set_curr_value("gold", 80+random(60));  
    set_wear("%^RESET%^%^RED%^The spider bites your leg as you wear the leggings%^RESET%^") ;
    set_remove("%^BOLD%^%^WHITE%^The spider releases your legs.");
    set_limbs(({ "right rear leg", "left rear leg", "right foreleg", "left foreleg"}));
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
