#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^R%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^y%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^l G%^RESET%^%^ORANGE%^l%^BOLD%^%^ORANGE%^ov%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^s%^RESET%^");
    
    set_short("%^BOLD%^%^WHITE%^R%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^y%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^l G%^RESET%^%^ORANGE%^l%^BOLD%^%^ORANGE%^ov%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^s%^RESET%^");
    set_long("%^ORANGE%^Covered in gilt, it looks like these gloves would break on a whim.");
    set_id(({"gloves"}));
    set_ac(5);            
    set_mass(27);
    set_type("gloves");
    set_curr_value("gold", 1);  
    set_wear("Well, what can you say, it fits like a glove!") ;
    set_remove("Maybe they dont fit too well as they fall off your hands.");
    set_limbs(({ "right hand", "left hand" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 100) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_race() == "lich") return 0;
   write("No, no, no.. you've got it all wrong. You may not wear the %^BOLD%^%^WHITE%^R%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^y%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^l G%^RESET%^%^ORANGE%^l%^BOLD%^%^ORANGE%^ov%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^s%^RESET%^");
   say(this_player()->query_cap_name()+" is an idiot for wearing something "
      "that they do not own.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
