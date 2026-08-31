#include <std.h>
inherit ARMOUR;
 
void create() {
::create();
    set_id(({"necklace", "shinkoro necklace"}));
    set_name("necklace");
    set_short("%^BOLD%^%^WHITE%^Shimmering %^GREEN%^Jade%^RESET%^ Necklace");
    set_long("A shimmering Jade necklace crafted by the God Shinkoro");
    set_mass(7);
    set_limbs(({"head", "abdomen", "left rear leg", "third arm", "second hand", "right foreleg", "second arm", "third hand", "left foreleg", "first arm", "fourth arm", "right rear leg", "fourth hand", "torso", "first hand"
}));
    set_ac(50000);
    set_type("quiver");
}
int query_auto_load() 
{
    if (this_player()->query_name() == "shinkoro") 
    return 1; 
}
