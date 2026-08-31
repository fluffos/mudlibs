#include <std.h>
#include <castlewall.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Mystical Armour");
    set_short("%^BOLD%^%^BLACK%^My%^RESET%^%^CYAN%^sti%^BOLD%^%^BLACK%^ca%^RESET%^%^CYAN%^l A%^BOLD%^%^BLACK%^rmo%^RESET%^%^CYAN%^ur%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Swirling %^RESET%^%^RED%^ene%^ORANGE%^gie%^RED%^s%^BOLD%^%^BLACK%^ cover the dark metal of this armour. Streamers of energy reach out to any living flesh.%^RESET%^ ");
    set_id(({"armour", "mystical armour"}));
    set_ac(12);            
    set_mass(125+random(30));
    set_type("body armor");
    set_curr_value("gold", 100+random(100));  
    set_wear("%^BOLD%^%^WHITE%^Cold %^BLACK%^seeps into your skin and muscles as you wear the armour.%^RESET%^") ;
    set_remove("%^RESET%^%^RED%^Warmth slowly creeps back into your flesh as you remove the armour.%^RESET%^");
    call_out("glow",150);
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg"}));
}
 int query_auto_load() { if (this_player()->query_level() > 49) return 1; }



void glow() {
   if(!this_object()->query_worn()) return 0;
   write("%^BOLD%^%^BLACK%^Dark %^RESET%^%^RED%^ene%^ORANGE%^rgie%^RED%^s%^BOLD%^%^BLACK%^ lash out from the armour.%^RESET%^");
   say("%^BOLD%^%^BLACK%^Dark %^RESET%^%^RED%^ene%^ORANGE%^rgie%^RED%^s%^BOLD%^%^BLACK%^ lash out from the armour.%^RESET%^");
   remove_call_out("glow");
   call_out("glow",150);

}
