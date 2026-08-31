# include <std.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("gauntlets");
    
    set_short("%^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^Ga%^BOLD%^%^CYAN%^un%^RESET%^%^WHITE%^t%^BOLD%^%^CYAN%^le%^BOLD%^%^BLUE%^ts%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^These gauntlets were made with the help of the famed Blue Dragon."
             "%^BOLD%^%^BLUE%^ \nTwined spiderwebs and moonbeams make up the fingertips and ready shape"
             "%^BOLD%^%^BLUE%^ of the hands, with a bit of night spice added in for protection.");
    set_id(({"gloves", "gauntlets"}));
    set_ac(7);            
    set_mass(55);
    set_type("gloves");
    set_curr_value("gold", 156);  
    set_wear("%^BOLD%^%^CYAN%^It feels as if midnight air has enveloped your hands.") ;
    set_remove("%^BOLD%^%^BLUE%^The warmth and comfort of a mid-summer's night leaves you.");
    set_limbs(({ "right hand", "left hand" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
