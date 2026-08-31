#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("bracer");
set_short("%^ORANGE%^Gold Bracer%^RESET%^");
set_long("%^ORANGE%^Will the rich never cease in their quest for protection that looks good? This bracer features a set of serpants interlocked with a gold leaf in the middle.%^RESET%^");
set_wear("You feel rich... famous");
set_remove("You're poor again");
set_id(({"bracer", "gold bracer"}));
set_ac(2);
set_weight(12);
set_curr_value("gold",75);
set_type("bracers");
set_limbs(({"right arm"}));
}
int query_auto_load() 
{
if (this_player()->query_level() > 30)
return 1; 
else
return 0;
}


