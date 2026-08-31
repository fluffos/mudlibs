#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("gold helm");
set_short("%^ORANGE%^Gold Helm");
set_long("%^ORANGE%^Why people continue to think gold makes any sort of good protection is beyond you.");
set_id(({"helmet", "gold", "gold helmet", "helm", "gold helm"}));
set_ac(3);
set_weight(20);
set_curr_value("gold",150);
set_type("helmet");
set_limbs(({"head"}));
}
int query_auto_load() 
{
if (this_player()->query_level() >= 20)
return 1; 
}


