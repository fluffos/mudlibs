#include <std.h>
inherit ARMOUR;
void create() {
::create();
set_name("tinhelmet");
set_short("Tin Helmet");
set_long("This cheap helmet was banged out of a piece of tin.  It gives crude protection.");
set_id(({"helmet", "tin", "tin helmet"}));
set_ac(3);
set_weight(8);
set_curr_value("gold",25);
set_type("helmet");
set_limbs(({"head"}));
}
int query_auto_load() 
{
if (this_player()->query_level() >= 20)
return 1; 
}
