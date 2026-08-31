#include <std.h>
#include <castlewall.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Mystical Armour");
    set_short("%^BOLD%^%^BLACK%^My%^RESET%^%^CYAN%^sti%^BOLD%^%^BLACK%^ca%^RESET%^%^CYAN%^l A%^BOLD%^%^BLACK%^rmo%^RESET%^%^CYAN%^ur%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Swirling %^RESET%^%^RED%^ene%^ORANGE%^gie%^RED%^s%^BOLD%^%^BLACK%^ cover the dark metal of this armour. Streamers of energy reach out to any living flesh.%^RESET%^ ");
    set_id(({"armour", "mystical armour"}));
    set_ac(9);            
    set_mass(90+random(30));
    set_type("body armor");
    set_curr_value("gold", 100+random(100));  
    set_wear("%^BOLD%^%^WHITE%^Cold %^BLACK%^seeps into your skin and muscles as you wear the armour.%^RESET%^") ;
    set_remove("%^RESET%^%^RED%^Warmth slowly creeps back into your flesh as you remove the armour.%^RESET%^");
    call_out("glow",150);
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg"}));
}
 int query_auto_load() { if (this_player()->query_level() > 49) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 49) return 0;
   write("This belongs to the %^BOLD%^%^BLACK%^Dark %^WHITE%^Archers%^RESET%^!!");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}

void glow() {
   if(!this_object()->query_worn()) return 0;
   write("%^BOLD%^%^BLACK%^Dark %^RESET%^%^RED%^ene%^ORANGE%^rgie%^RED%^s%^BOLD%^%^BLACK%^ lash out from the armour.%^RESET%^");
   say("%^BOLD%^%^BLACK%^Dark %^RESET%^%^RED%^ene%^ORANGE%^rgie%^RED%^s%^BOLD%^%^BLACK%^ lash out from the armour.%^RESET%^");
   remove_call_out("glow");
   call_out("glow",150);

}
