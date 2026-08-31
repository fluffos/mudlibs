#include <std.h>                                                               


inherit ARMOUR;                                                                


int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("dwarven battle armor");
        set_id( ({ "armor", "armour", "dwarven battle armor", "battle armor" }) );
        set_short("Dwarven Battle Armor");
        set_long("An old suit of dwarven battle armor.  From the knicks "
        "and dents in it, it's clearly been worn to more than a few battles. "
        );
        set_ac(5);
        set_curr_value("silver", 120 + random(5));
        set_limbs( ({ "torso", "left arm", "right arm", "left leg", "right leg" }) );
        set_weight(30);
        set_type("body armour");

}

int query_auto_load() { 
    if(this_player()->query_race()=="dwarf")
        return 1; 
}
