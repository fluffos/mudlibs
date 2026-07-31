#include <weapon.h>
inherit HAND;

void create()
{
set_name("铁拳套", ({"tie quantao","quantao","hand"}));
set_weight(2000);
if( clonep() )
        set_default_object(__FILE__);
else    {
        set("long", "一对铁制的拳套．\n");
        set("unit", "双");
        set("value", 1500);
        set("material", "iron");
        }
init_hand(100);
setup();
}
