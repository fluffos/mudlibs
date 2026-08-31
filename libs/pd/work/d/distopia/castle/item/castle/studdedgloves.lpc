#include <std.h>
inherit ARMOUR;
void create() {
::create();
set_name("studdedgloves");
set_short("Studded Leather Gloves");
set_long("The second piece of leather armor.  The gloves are stiff and take some
streches before they soften.");
set_id(({"gloves", "studded leather gloves", "leather gloves", "studded
gloves"}));
set_ac(5);
set_weight(10);
set_curr_value("gold",65);
set_type("gloves");
set_limbs(({"left hand", "right hand"}));
}
int query_auto_load() 
{
if (this_player()->query_level() >= 20)
return 1; 
}
