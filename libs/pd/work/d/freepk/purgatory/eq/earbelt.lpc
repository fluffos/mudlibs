#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^RED%^A Blo%^RESET%^%^RED%^od%^BOLD%^%^RED%^y tr%^RESET%^%^RED%^ophy %^BOLD%^%^RED%^bel%^RESET%^%^RED%^t%^RESET%^");
    
    set_short("%^BOLD%^%^RED%^A Blo%^RESET%^%^RED%^od%^BOLD%^%^RED%^y tr%^RESET%^%^RED%^ophy %^BOLD%^%^RED%^bel%^RESET%^%^RED%^t%^RESET%^");
    set_long("%^BOLD%^%^RED%^The severed ears from the defeated opponents of the Purgatory Shadow Guards are sewn together to form a belt! How morbid can you get?%^RESET%^");
    set_id(({"belt"}));
    set_ac(0);            
    set_mass(3);
    set_type("belt");
    set_curr_value("gold", 1);  
    set_wear("%^ORANGE%^You feel a strange type of leather rub against your waist.%^RESET%^") ;
    set_remove("%^BOLD%^%^RED%^You look down and you see you are wearing EARS!!! You drop the belt as fast as you can.%^RESET%^");
    set_limbs(({ "torso" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
