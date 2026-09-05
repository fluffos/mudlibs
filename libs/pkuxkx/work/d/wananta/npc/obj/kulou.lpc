inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW"天圣的骷髅头"NOR, ({ "tiansheng kulou", "kulou" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一颗假宝石，没想到汝阳王府也有这玩意儿。\n");
                set("unit", "颗");
                set("value", 50);
        }
        setup();
}
