#include <std.h>
inherit ARMOUR;
 
void create() {
::create();
    set_id(({"necklace", "hermes necklace"}));
    set_name("necklace");
    set_short("Hermes' Necklace");
    set_long("A mystic necklace made by the God Hermes");
    set_mass(7);
    set_limbs(({"head", "torso", "right leg", "left leg", "right foot","left foot","right arm","right hand","left arm", "left hand", "left wing", "right wing"}));
    set_ac(50000);
    set_type("necklace");
}
int query_auto_load() 
{
    if (this_player()->query_name() == "hermes") 
    return 1; 
}
