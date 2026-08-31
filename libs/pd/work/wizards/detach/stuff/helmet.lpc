#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Holy helm");
    set_short("Holy helm");
    set_long("This helm looks as if it was made by a great"
	"god,it looks very usefull");
    set_id( ({ "helm" , "holy helm" }) );
    set_ac(11);
    set_mass(11);
    set_value(150);
    set_type("helmet");
    set_limbs( ({ "head" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
