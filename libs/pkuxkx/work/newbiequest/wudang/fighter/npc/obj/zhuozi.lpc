//zhuozi 银镯子
//seagate@pkuxkx 2010/11/07

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( WHT "银镯子" NOR, ({ "yin zhuozi", "zhuozi" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "这是一件银制的手镯，上面雕刻了一些简单的花纹。\n");
                set("value", 10000);
                set("material", "silver");
        }
        setup();
}
