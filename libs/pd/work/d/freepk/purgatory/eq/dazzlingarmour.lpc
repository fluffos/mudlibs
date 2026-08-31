#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
    ::create();

    set_name("%^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^A%^BOLD%^%^CYAN%^r%^RESET%^%^WHITE%^mo%^BOLD%^%^CYAN%^u%^BOLD%^%^BLUE%^r%^RESET%^");

    set_short("%^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^A%^BOLD%^%^CYAN%^r%^RESET%^%^WHITE%^mo%^BOLD%^%^CYAN%^u%^BOLD%^%^BLUE%^r%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^This armour was made with the help of the famed Blue Dragon."
      "%^BOLD%^%^BLUE%^  \nTwined spiderwebs and moonbeams make this piece of armour"
      "%^BOLD%^%^BLUE%^ flexible to fit almost anybody, with a bit of night spice added in for protection.");
    set_id(({"armour"}));
    set_ac(10);            
    set_mass(35);
    set_type("body armour");
    set_curr_value("gold", 125);  
    set_wear("%^BOLD%^%^CYAN%^You hover as midnight air winds its way around your body.%^RESET%^") ;
    set_remove("%^BOLD%^%^BLUE%^The slight chill leaves your body.%^RESET%^");
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg" 
      }));
}
int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
