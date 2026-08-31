#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("White Leather Cloak");
    set_short("%^BOLD%^%^WHITE%^Whi%^RESET%^te "
"Lea%^BOLD%^%^WHITE%^the%^RESET%^r Cl%^BOLD%^%^WHITE%^oak%^RESET%^");
    set_long("This cloak is made from a tuff white leather only "
"found in and around Azeria.");
    set_id( ({ "cloak","white leather cloak" }) );
    set_ac(8);
    set_mass(23);
     set_curr_value("gold",150+random(40));
    set_type("cloak");
    set_limbs( ({ "right arm","left arm","torso","head"}) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
