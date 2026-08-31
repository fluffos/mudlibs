#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("gold necklace");
set_short("%^ORANGE%^Gold Necklace");
set_long("%^ORANGE%^It's a pretty gold necklace in the shape of a heart");
set_id(({"necklace", "gold necklace"}));
set_ac(1);
set_weight(5);
set_curr_value("gold",100);
set_type("necklace");
set_limbs(({"head"}));
}
int query_auto_load() 
{
if (this_player()->query_level() >= 20)
return 1; 
}

