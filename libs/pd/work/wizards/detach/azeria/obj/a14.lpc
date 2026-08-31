#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Soul Boots");
    set_short("%^RED%^S%^WHITE%^o%^BOLD%^%^WHITE%^u%^RED%^l "
"B%^WHITE%^o%^RESET%^%^WHITE%^o%^RED%^ts%^RESET%^");
   set_long("These boots seem to have a ring of fire "
"around them. These boots were formed by a very powerfull "
"pyromancer.");
    set_id( ({"boots","soul boots" }) );
    set_ac(8);
    set_mass(20);
     set_curr_value("gold",150+random(40));
    set_type("boots");
    set_limbs( ({ "right foot","left foot"}) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
