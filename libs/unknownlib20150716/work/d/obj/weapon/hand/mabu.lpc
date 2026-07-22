#include <weapon.h>
inherit HAND;

void create()
{
set_name("麻布拳套", ({"mabu quantao","quantao","hand"}));
set_weight(2000);
if( clonep() )
        set_default_object(__FILE__);
else    {
        set("long", "一对麻布制成的拳套．\n");
        set("unit", "双");
        set("value", 50);
        set("material", "cloth");
        }
init_hand(20);
setup();
}
