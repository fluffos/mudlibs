#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^Le%^BOLD%^CYAN%^g%^RESET%^%^WHITE%^gi%^BOLD%^%^CYAN%^n%^BOLD%^%^BLUE%^gs%^RESET%^");
    
    set_short("%^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^Le%^BOLD%^CYAN%^g%^RESET%^%^WHITE%^gi%^BOLD%^%^CYAN%^n%^BOLD%^%^BLUE%^gs%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^These leggings were made with the help of the famed Blue Dragon."
             "%^BOLD%^%^BLUE%^ \nTwined spiderwebs and moonbeams make this peice of armour"
             "%^BOLD%^%^BLUE%^ flexible to fit almost any leg, with a bit of night spice added in for protection.");
    set_id(({"leggings"}));
    set_ac(4);            
    set_mass(48);
    set_type("leggings");
    set_curr_value("gold", 154);  
    set_wear("%^BOLD%^%^CYAN%^A slight breeze of midnight air envelops your legs.%^RESET%^") ;
    set_remove("%^BOLD%^%^BLUE%^The slight chill leaves your legs.%^RESET%^");
    set_limbs(({ "right leg", "left leg" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
