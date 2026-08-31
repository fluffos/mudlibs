#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^RED%^Ga%^RESET%^%^RED%^rn%^BOLD%^%^RED%^et %^RESET%^%^GREEN%^S%^BOLD%^%^GREEN%^as%^RESET%^%^GREEN%^h%^RESET%^");
    
    set_short("%^BOLD%^%^RED%^Ga%^RESET%^%^RED%^rn%^BOLD%^%^RED%^et %^RESET%^%^GREEN%^S%^BOLD%^%^GREEN%^as%^RESET%^%^GREEN%^h%^RESET%^");
    set_long("This is a green silk sash with garnets sewn in intricate patterns all the way around. It could be worth alot.");
    set_id(({"sash"}));
    set_ac(1);            
    set_mass(3);
    set_type("belt");
    set_curr_value("gold", 200);  
    set_limbs(({ "torso" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_race() == "archangel") return 0;
   write("That is just not right, trying to wear a dead womans sash!");
   say(this_player()->query_cap_name()+" is an idiot for wearing something "
      "that they pulled off a corpse.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
