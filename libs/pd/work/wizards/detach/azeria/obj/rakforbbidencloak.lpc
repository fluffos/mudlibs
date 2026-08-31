#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Forbidden Cloak");
    set_short("%^BOLD%^%^BLUE%^For%^RESET%^%^BLUE%^bid%^RESET%^den C%^BLUE%^lo%^BOLD%^%^BLUE%^ak%^RESET%^");
    set_long("This cloak seems as if it is formed from water. "
"A deep blue mist surrounds the cloak.");
    set_id( ({ "cloak" , "forbiden cloak" }) );
set_ac(7);
    set_mass(13);
     set_curr_value("gold",150+random(40));
    set_type("cloak");
set_limbs( ({ "first arm","second arm","third arm","fourth arm","torso","abdomen"}) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
