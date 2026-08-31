#include <std.h>
#include <castlewall.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Mystical Gloves");
    set_short("%^BOLD%^%^BLACK%^My%^RESET%^%^CYAN%^sti%^BOLD%^%^BLACK%^ca%^RESET%^%^CYAN%^l G%^RESET%^%^CYAN%^lov%^BOLD%^%^BLACK%^es%^RESET%^");
    set_long("Hardened and bound by %^BOLD%^%^BLACK%^dark %^RESET%^%^RED%^ener%^ORANGE%^gie%^RED%^s%^RESET%^, these gloves should provide considerable armour.");
    set_id(({"gloves", "mystical gloves"}));
    set_ac(3);            
    set_mass(35);
    set_type("gloves");
    set_curr_value("gold", 1);  
    set_wear("%^BOLD%^%^BLACK%^The %^BOLD%^%^BLACK%^dark %^RESET%^%^RED%^ener%^ORANGE%^gie%^RED%^s%^RESET%^%^BOLD%^%^BLACK%^ of the gloves send tendrils of pain up your arms as you wear them.%^RESET%^") ;
    set_remove("%^BOLD%^%^WHITE%^You sigh in relief as you remove the gloves.");
    set_limbs(({ "right hand", "left hand"}));
}
 int query_auto_load() { if (this_player()->query_level() > 49) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 50) return 0;
   write("You are too little to wear these gloves!!!");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
