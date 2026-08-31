#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^A %^BOLD%^%^YELLOW%^Go%^BOLD%^%^WHITE%^ld%^BOLD%^%^YELLOW%^en %^BOLD%^%^WHITE%^Dress%^RESET%^");
    
    set_short("%^BOLD%^%^WHITE%^Sh%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^m%^RESET%^%^ORANGE%^m%^BOLD%^%^WHITE%^ers%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^l%^RESET%^%^ORANGE%^k %^BOLD%^%^WHITE%^Dress%^RESET%^");
    set_long("Made for the Queen by a Master Weaver, this dress incorporates tiny golden threads that seem to shimmer in the silk.");
    set_id(({"dress"}));
    set_ac(10);            
    set_mass(98);
    set_type("dress");
    set_curr_value("gold", 1);  
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 100) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_race() == "archangel") return 0;
   write("That is just not right, trying to wear a dead womans dress!");
   say(this_player()->query_cap_name()+" is an idiot for wearing something "
      "that they pulled off a corpse.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
