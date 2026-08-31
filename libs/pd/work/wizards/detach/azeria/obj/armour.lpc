#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Warlord Armour");
    set_short("%^BOLD%^%^BLACK%^War%^RESET%^l%^BOLD%^%^BLACK%^ord Arm%^RESET%^o%^BOLD%^%^BLACK%^ur");
    set_long("%^BOLD%^%^BLACK%^Warlord armour shines with a sliver tint, its formed from the skins of Arch-Angels..");
    set_id( ({ "warlord armour" , "armour" }) );
    set_ac(14);
    set_mass(60);
     set_curr_value("gold",150+random(40));
    set_type("body armour");
    set_limbs( ({ "head","torso" }) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
