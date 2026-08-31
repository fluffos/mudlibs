#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Plated Leggings");
    set_short("Plated Leggings");
    set_long("Layered steel plates riveted to hardened leather provide good protection for the wearer.");
    set_id( ({ "plated leggings" , "plate" , "leggings" }) );
    set_ac(3);
    set_mass(45);
     set_curr_value("gold",30+random(40));
    set_type("leggings");
    set_limbs( ({  "right leg", "left leg" }) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 if(this_player()->query_level() > 22)
 return 1;
}
