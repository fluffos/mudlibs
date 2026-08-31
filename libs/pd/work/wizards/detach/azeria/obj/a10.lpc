#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Knight Armour");
    set_short("%^BOLD%^%^WHITE%^Kni%^BLACK%^gh%^RESET%^t "
"A%^BOLD%^%^WHITE%^rm%^BLACK%^our%^RESET%^");
    set_long("This armour is made for one of the holy knights "
"of the Azerian army.");
    set_id( ({ "armour" ,"knight armour" }) );
set_mass(25);
    set_ac(10);
     set_curr_value("gold",150+random(40));
    set_type("body armour");
    set_limbs( ({ "right arm","left arm","torso","head"}) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
