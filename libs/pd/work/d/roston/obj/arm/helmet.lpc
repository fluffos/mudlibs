#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Holy helm");
    set_short("Holy helm");
    set_long("This helm looks as if it was made by a great "
	"god. It looks very useful.");
    set_id( ({ "helm" , "holy helm" }) );
    set_ac(3);
    set_mass(11);
    set_curr_value("gold", 40);
    set_type("helmet");
    set_limbs( ({ "head" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 if(this_player()->query_level() < 6) return 0;
 return 1;
}
