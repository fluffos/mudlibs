#include <std.h>                                                               


inherit ARMOUR;                                                                


int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("dwarven battle tunic");
        set_id( ({ "tunic", "shirt", "dwarven tunic", "battle tunic" }) );
        set_short("Dwarven Battle Tunic");
        set_long("An old dwarven battle tunic.  From the number of cuts and "
        "tears and patches this tunic has, it has certainly seen some use "
        "in its days.  Dwarven miners prefer used gear like this since it "
        "flexes a little more, giving them more mobility to mine in.");
        set_ac(3);
        set_curr_value("silver", 80 + random(5));
        set_limbs( ({ "torso", "left arm", "right arm" }) );
        set_weight(12);
        set_type("tunic");

}

int query_auto_load() { 
    if(this_player()->query_race()=="dwarf")
        return 1; 
}
