# include <std.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^RED%^Bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^dy %^BOLD%^%^WHITE%^le%^RESET%^%^WHITE%^ath%^BOLD%^%^WHITE%^er %^RESET%^ORANGE%^boots");
    
    set_short("%^RED%^Bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^dy %^BOLD%^%^WHITE%^le%^RESET%^%^WHITE%^ath%^BOLD%^%^WHITE%^er %^RESET%^ORANGE%^boots");
    set_long("%^BOLD%^%^WHITE%^Freshly made leather boots that look like they were just ripped out of an animal.%^RESET%^ ");
    set_id(({"boots", "armour"}));
    set_ac(5);            
    set_mass(85);
    set_type("boots");
    set_curr_value("gold", 1);  
    set_wear("%^BOLD%^%^WHITE%^Your feet squish into the boots, %^RED%^Bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d%^BOLD%^%^WHITE%^ starts to seep between your toes.") ;
    set_remove("%^BOLD%^%^WHITE%^The %^RED%^Bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d%^BOLD%^%^WHITE%^ on your feet begins to dry as you remove the boots.");
    set_limbs(({ "right foot", "left foot" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 0; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
 if (this_player()->query_level() > 35) return 0;
   write("You are too little for these boots");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}

