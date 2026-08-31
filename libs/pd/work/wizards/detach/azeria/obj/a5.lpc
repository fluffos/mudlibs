#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Bronze leggings");
    set_short("%^ORANGE%^Br%^BOLD%^%^WHITE%^on%^RESET%^ze " 
"%^ORANGE%^Legg%^BOLD%^%^WHITE%^in%^RESET%^gs");
    set_long("These leggings are made from a strong bronze. They "
"seem to be long enough to protect anyones legs.");
    set_id( ({ "leggings" , "bronze leggings" }) );
    set_ac(8);
    set_mass(20);
    set_curr_value("gold",150+random(40));
    set_type("leggings");
    if (member_array("left leg", this_player()->query_limbs()) != -1)
        set_limbs(({ "right leg", "left leg" }));
    else
        set_limbs (({ "right foreleg", "right rear leg", "left foreleg", "left rear leg" }));
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
