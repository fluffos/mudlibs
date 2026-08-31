#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^Fluffy %^BOLD%^%^MAGENTA%^Bunny %^BOLD%^%^WHITE%^Slippers%^RESET%^"); 
    set_short("%^BOLD%^%^WHITE%^Fluffy %^BOLD%^%^MAGENTA%^Bunny %^BOLD%^%^WHITE%^Slippers%^RESET%^");
    set_long("%^BOLD%^%^MAGENTA%^Just a pair of regular ole fluffy bunny slippers.%^RESET%^");
    set_id(({"slippers"}));
    set_ac(2);            
    set_mass(5);
    set_type("boots");
    set_curr_value("gold", 1);  
    set_wear("%^BOLD%^%^MAGENTA%^Your feet feel really comfortable.%^RESET%^") ;
    set_remove("Awwww you watch the slippers hop off into the distance.");
    set_limbs(({ "right foot", "left foot" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
