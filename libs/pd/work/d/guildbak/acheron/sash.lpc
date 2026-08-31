#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("sash of acheron");
    
    set_short("%^RESET%^%^WHITE%^S%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^s%^BOLD%^%^WHITE%^h %^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^f %^BOLD%^%^CYAN%^A%^BOLD%^%^BLACK%^ch%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^ro%^BOLD%^%^CYAN%^n%^RESET%^%^%^BOLD%^%^BLUE%^%^RESET%^");
    set_long("Made by a hidden seamstress for the Acheron guild, this sash symbolizes that whoever wears it is an honored member of the guild.");
    set_id(({"sash"}));
    set_ac(1);            
    set_mass(5);
    set_type("sash");
    set_curr_value("gold", 150+random(30));  
    set_limbs(({ "torso" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 1) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_guild() == "acheron") return 0;
   write("Only Acheron guild members may wear this.");
   say(this_player()->query_cap_name()+" thinks all of you are fools.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
