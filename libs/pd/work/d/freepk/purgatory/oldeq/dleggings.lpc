# include <std.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^BLACK%^Dark %^BOLD%^%^WHITE%^Steel%^BOLD%^%^BLACK%^ Leggings%^RESET%^ ");
    
    set_short("%^BOLD%^%^BLACK%^Dark %^BOLD%^%^WHITE%^Steel%^BOLD%^%^BLACK%^ Leggings%^RESET%^ ");
    set_long("%^BOLD%^%^BLACK%^Made in the forges of an evil Necromancer, these leggings " 
             "%^BOLD%^%^BLACK%^ have the fine detail you would expect from a master."
             "%^BOLD%^%^BLACK%^ The visage of Death has been carved deep into the steel.");
    set_id(({"leggings", "armour"}));
    set_ac(5);            
    set_mass(35);
set_type("leggings");
    set_wear("%^BOLD%^%^BLACK%^You scream out in pain as a cold fire leaps out from the leggings and surrounds your legs.") ;
    set_remove("%^BOLD%^%^BLACK%^Your flesh is ripped from your legs as you pry the leggings off.");
    set_limbs(({ "right leg", "left leg" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 65) return 1; }
int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 65) return 0;
   write("You are too little to wear these");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
