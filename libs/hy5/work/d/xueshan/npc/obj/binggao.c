// binggao.c 

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name( "冰镐", ({ "bing gao", "binggao","gao"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "攀登用的工具，尤其适用于冰雪地形。\n");
                set("value", 100);
                set("material", "steel");
        }
        init_staff(10);
        setup();
}
