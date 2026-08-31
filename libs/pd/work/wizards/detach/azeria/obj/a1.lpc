#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Gold Platemail");
    set_short("%^YELLOW%^Go%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^d %^YELLOW%^Plat%^BOLD%^%^WHITE%^ema%^RESET%^il");
    set_long("This platemail was formed and forged in the greatest "
"blacksmith's shop in all the lands.");
    set_id( ({ "platemail" , "gold platemail" }) );
    set_ac(9);
    set_mass(10);
     set_curr_value("gold",150+random(40));
    set_type("body armour");
    set_limbs( ({ "head","torso" }) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
