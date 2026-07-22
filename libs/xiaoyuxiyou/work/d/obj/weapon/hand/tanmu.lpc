#include <weapon.h>
inherit HAND;

void create()
{
set_name("檀木拳套", ({"tanmu quantao","quantao","hand"}));
set_weight(2000);
if( clonep() )
        set_default_object(__FILE__);
else    {
        set("long", "一对檀木制成的拳套．\n");
        set("unit", "双");
        set("value", 150);
        set("material", "wood");
        }
init_hand(40);
setup();
}
