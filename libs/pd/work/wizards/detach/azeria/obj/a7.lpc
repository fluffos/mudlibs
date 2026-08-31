#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Light Gloves");
    set_short("%^YELLOW%^lig%^BOLD%^%^WHITE%^h%^RESET%^t "
"Gl%^BOLD%^%^WHITE%^ov%^YELLOW%^es%^RESET%^");
    set_long("These Gloves where given to a Holy priest that "
"lived through the battle of The Hellion..");
    set_id( ({ "gloves" , "light gloves" }) );
    set_ac(6);
    set_mass(10);
     set_curr_value("gold",150+random(40));
    set_type("gloves");
    if (member_array("left hand", this_player()->query_limbs()) != -1)
        set_limbs(({ "right hand", "left hand"}));
    else
        set_limbs (({ "first hand", "second hand", "third hand", "fourth hand" }));
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
