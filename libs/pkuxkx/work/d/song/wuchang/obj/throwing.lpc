#include <weapon.h>
inherit THROWING;

void create()
{
        set_name("钢针", ({"needle"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一柄"+query("name")+"，大宋的制式武器。\n");
                set("unit", "把");
                set("base_unit", "根");
                set("value", 0);
                set("base_weight", 10);
        }
        set_amount(1);
        init_throwing(100);
        setup();
}
