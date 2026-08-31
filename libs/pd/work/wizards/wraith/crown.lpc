#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^YELLOW%^J%^BOLD%^%^RED%^e%^BOLD%^%^CYAN%^w%^BOLD%^%^GREEN%^e%^BOLD%^%^MAGENTA%^l %^BOLD%^%^WHITE%^Encrusted%^RESET%^%^BOLD%^%^YELLOW%^ Coronet%^RESET%^");
    
    set_short("%^BOLD%^%^YELLOW%^J%^BOLD%^%^RED%^e%^BOLD%^%^CYAN%^w%^BOLD%^%^GREEN%^e%^BOLD%^%^MAGENTA%^l %^BOLD%^%^WHITE%^Encrusted%^RESET%^%^BOLD%^%^YELLOW%^ Coronet%^RESET%^");
    set_long("%^BOLD%^%^RED%^Rubies, %^BOLD%^%^GREEN%^emeralds,%^RESET%^ and %^BOLD%^%^CYAN%^sapphires%^RESET%^ are set in %^BOLD%^%^YELLOW%^gold%^RESET%^ around crest of this coronet.");
    set_id(({"coronet"}));
    set_ac(1);            
    set_mass(4);
    set_type("crown");
    set_curr_value("gold", 200);  
    set_limbs(({ "head" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_name() == "wraith") return 0;
   write("How dare you try to assume the throne of Purgatory!!!");
   say(this_player()->query_cap_name()+" is an idiot for wearing something "
      "that they pulled off a corpse.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}

