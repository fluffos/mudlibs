#include <weapon.h>
inherit HAND;

void create()
{
set_name("金刚拳套", ({"jingang quantao","quantao","hand"}));
set_weight(5000);
if( clonep() )
        set_default_object(__FILE__);
else    {
        set("long", "一对特制的拳套，上面嵌满了金刚石．\n");
        set("unit", "双");
        set("value", 100000);
        set("material", "gold");
        }
init_hand(250);
setup();
}
