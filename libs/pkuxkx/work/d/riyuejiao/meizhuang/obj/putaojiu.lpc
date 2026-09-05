//putaojiu.c	葡萄酒
//by bing

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name(HIR "葡萄酒" NOR, ({"putao jiu", "jiu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一桶西域吐鲁番的葡萄酒，四蒸四酿，，在当世也是首屈一指的了。那木桶已然旧得发黑，
上面弯弯曲曲的写着许多西域文字，木塞上用火漆封住，火漆上盖了印，显得极为郑重。\n");
                set("unit", "木桶");
                set("value", 6000);
                set("max_liquid", 10);
                        }
set("liquid", ([
                "type": "alcohol",
                "name": "葡萄酒",
                "remaining": 10,
                "drunk_apply": 40,
        ]));
}
