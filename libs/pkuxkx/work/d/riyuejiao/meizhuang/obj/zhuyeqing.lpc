//zhuyeqing.c	竹叶青
//by bing

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name(HIG "竹叶青" NOR, ({"zhuye qing", "jiu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一坛百年以上的竹叶青。这酒碧如翡翠，盛在碗中，宛如深不见底，酒香极是醇厚，\n");
                set("unit", "坛");
                set("value", 6000);
                set("max_liquid", 10);
                        }
set("liquid", ([
                "type": "alcohol",
                "name": "竹叶青酒",
                "remaining": 10,
                "drunk_apply": 40,
        ]));
}
