#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("White Leather Boots");
    set_short("%^BOLD%^%^WHITE%^Whi%^RESET%^te "
"Lea%^BOLD%^%^WHITE%^the%^RESET%^r Bo%^BOLD%^%^WHITE%^ots%^RESET%^");
    set_long("These boots is made from a tuff white leather only "
"found in and around Azeria.");
    set_id( ({ "boots","white leather boots" }) );
    set_ac(8);
    set_mass(23);
     set_curr_value("gold",150+random(40));
    set_type("boots");
    set_limbs( ({ "right foot","left foot"}) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
