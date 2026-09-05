#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(GRN"高昌葡萄酒"NOR, ({"putao jiu", "jiu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一坛碧绿的源自高昌的马奶葡萄酿造的葡萄酒。\n");
                set("unit", "坛");
                set("value", 10000);
                set("max_liquid", 10);
                        }
set("liquid", ([
                "type": "alcohol",
                "name": "女儿红",
                "remaining": 10,
                "drunk_apply": 20,
        ]));
}
