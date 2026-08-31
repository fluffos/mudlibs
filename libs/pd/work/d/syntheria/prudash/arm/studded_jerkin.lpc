#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("studded jerkin");
        set_id( ({ "studded jerkin", "jerkin", "armour", "armor", "vest" }) );
        set_short("Studded jerkin");
        set_long("A jerkin made from hard leather, reinforced with metal studs.");
        set_ac(2);
        set_curr_value("copper", 20 + random(6));
        set_limbs( ({ "torso" }) );
        set_weight(8 + random(8));
        set_type("vest");

}



int query_auto_load() { return 1; }
