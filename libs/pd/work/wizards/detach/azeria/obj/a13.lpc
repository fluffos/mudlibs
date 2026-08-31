#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Cloak Of Incinerate");
    set_short("%^BOLD%^%^RED%^Clo%^RESET%^%^RED%^ak "
"O%^BOLD%^%^RED%^f Incin%^RESET%^%^RED%^erate%^RESET%^");
    set_long("This cloak is made of fire. It seems as if "
"flames are beening held into a cloak shape, it looks to be "
"very good armour.");
    set_id( ({"cloak","cloak of incinerate" }) );
    set_ac(9);
    set_mass(20);
     set_curr_value("gold",150+random(40));
    set_type("cloak");
    set_limbs( ({ "right arm","left arm","torso","head"}) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
