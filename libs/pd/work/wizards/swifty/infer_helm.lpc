#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("helmet");
    set_short("The %^%^RED%^%^Inferno %^%^Helmet");
    set_long("This helmet was forged with the very fires"
        "of hell.");
    set_id( ({ "helm" , "inferno helm" }) );
    set_ac(11);
    set_mass(11);
    set_value(150);
    set_type("helmet");
    set_limbs( ({ "head" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 0;
}
