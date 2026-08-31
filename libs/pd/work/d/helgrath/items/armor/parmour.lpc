#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Plated Armour");
    set_short("Plated Armour");
    set_long("Layered steel plates riveted to hardened leather provide good protection for the wearer.");
    set_id( ({ "plate" , "plated armour" , "armour" }) );
    set_ac(7);
    set_mass(65);
     set_curr_value("gold",50+random(40));
    set_type("armour");
    set_limbs( ({ "torso", "right arm", "left arm" }) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
