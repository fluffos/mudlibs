#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^MAGENTA%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^l %^RESET%^%^MAGENTA%^A%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^m%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^r%^RESET%^");
    
    set_short("%^BOLD%^%^MAGENTA%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^l %^RESET%^%^MAGENTA%^A%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^m%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^r%^RESET%^");
    set_long("%^MAGENTA%^For being such a Royal pain in the neck, the citizens of purgatory made this armour for their king.%^RESET%^");
    set_id(({"armour", "royal armour"}));
    set_ac(13);            
    set_mass(254);
    set_type("body armor");
    set_curr_value("gold", 200);  
    set_wear("%^RESET%^%^MAGENTA%^The %^BOLD%^%^MAGENTA%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^l %^RESET%^%^MAGENTA%^A%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^m%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^ seems to suit you.") ;
    set_remove("");
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg"
}));
}
 int query_auto_load() { if (this_player()->query_level() > 100) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_race() == "lich") return 0;
   write("No, no, no.. you've got it all wrong. You may not wear the %^BOLD%^%^MAGENTA%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^l %^RESET%^%^MAGENTA%^A%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^m%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^r%^RESET%^");
   say(this_player()->query_cap_name()+" is an idiot for wearing something "
      "that they do not own.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
