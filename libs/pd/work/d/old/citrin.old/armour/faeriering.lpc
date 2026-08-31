// Coded by Whit
// Coded for Primal Darkness

#include <std.h>
inherit ARMOUR;
int query_auto_load() {

if(this_player()->query_level() < 15) return 0;
return 1;
}
void create() {
::create();
    set_name("ring");
    set_short("a crystal ring");
    set_long("There is a encrsted gem in the middle of this ring.  The gem "
	     "sparkles with many colors.");
    set_id(({"ring", "faerie ring"}));
    set_ac(3);
    set_mass(8);
    set_value(300);
    set_type("ring");
    set_limbs(({"left hand"}));
}
