#include <weapon.h>
inherit HAND;

void create()
{
set_name("精钢拳套", ({"gang quantao","quantao","hand"}));
set_weight(5000);
if( clonep() )
        set_default_object(__FILE__);
else    {
        set("long", "一对钢制的拳套．\n");
        set("unit", "双");
        set("value", 8000);
        set("material", "iron");
        }
init_hand(150);
setup();
}
