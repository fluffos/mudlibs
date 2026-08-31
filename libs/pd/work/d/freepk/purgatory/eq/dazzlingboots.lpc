#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^o%^RESET%^%^WHITE%^o%^BOLD%^%^CYAN%^t%^BOLD%^%^BLUE%^s%^RESET%^");
    
    set_short("%^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^o%^RESET%^%^WHITE%^o%^BOLD%^%^CYAN%^t%^BOLD%^%^BLUE%^s%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^These boots were made with the help of the famed Blue Dragon."
             "%^BOLD%^%^BLUE%^  \nTwined spiderwebs and moonbeams make this peice of armour"
             "%^BOLD%^%^BLUE%^ flexible to fit almost any pair of feet, with a bit of night spice added in for protection.");
    set_id(({"boots"}));
    set_ac(5);            
    set_mass(28);
    set_type("boots");
    set_curr_value("gold", 132);  
    set_wear("%^BOLD%^%^CYAN%^The night air covers your feet.%^RESET%^") ;
    set_remove("%^BOLD%^%^BLUE%^The slight chill leaves your feet.%^RESET%^");
    set_limbs(({ "right foot", "left foot" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
