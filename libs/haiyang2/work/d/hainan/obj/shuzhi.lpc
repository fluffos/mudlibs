#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("树枝", ({"shuzhi"}));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("material", "wood");
        }
        init_sword(10);
        setup();
}

