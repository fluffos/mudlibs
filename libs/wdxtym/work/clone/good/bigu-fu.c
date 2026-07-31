// 辟谷符

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "辟谷符" NOR, ({ "bigu fu", "fu" }) );
        set_weight(30);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "携带后自动进入辟谷状态, 日常不消耗食物饮水。\n" NOR);
                set("value", 1);
                set("no_sell", 1);
                set("unit", "张");
        }
        set("auto_load", 1);

        setup();
}
