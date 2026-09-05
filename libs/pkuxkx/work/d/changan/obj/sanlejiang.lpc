#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIR"波斯三勒浆"NOR, ({"sanle jiang", "jiu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "三勒浆是店主从波斯带过来的酿造方法，使用庵摩勒、毗梨勒、诃梨勒三种果实酿造而成。\n");
                set("unit", "坛");
                set("value", 8000);
                set("max_liquid", 10);
                        }
set("liquid", ([
                "type": "alcohol",
                "name": "女儿红",
                "remaining": 10,
                "drunk_apply": 20,
        ]));
}
