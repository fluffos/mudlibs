#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int can_wear();
int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("thick lizard body armour");
        set_id( ({ "lizard body armour", "armour", "armor", "lizard body armor", "lizard armour", "lizard armor", "thick armor", "thick armour" }) );
        set_short("Thick lizard body armour");
        set_long("Full body armour made from lizard hide. It looks to be very tough, what a powerful creature it must have been.");
        set_ac(9);
        set_curr_value("gold", 60 + random(50));
        set_limbs( ({ "torso", "right arm", "left arm", " right leg", "left leg", "head" }) );
        set_weight(100);
        set_type("body armour");
        set_wear((:can_wear:));
}

int can_wear()
{
    if(this_player()->query_class() != "fighter")
    {
        write("This type of armour is not meant to be worn by you");
        return 0;
    }
    if(this_player()->query_skill("defense") < 130)
    {
        write("You have not the skill to wear such a thing");
        return 0;
    }
}

int query_auto_load()
{
    if (this_player()->query_level() > 26) return 1;
    return 0;
}
