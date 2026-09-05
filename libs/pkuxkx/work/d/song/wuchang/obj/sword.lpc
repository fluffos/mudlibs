#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("钢剑", ({"sword"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一柄"+query("name")+"，大宋的制式武器。\n");
                set("unit", "柄");
                set("value", 0);
        }
        init_sword(100);
        setup();
}
