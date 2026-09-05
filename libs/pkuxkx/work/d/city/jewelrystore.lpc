#include <ansi.h>
inherit JEWELRY_STORE;
void create()
{
        set("short", HIC"扬州金店"NOR);
        set("long", @LONG
这里是扬州钱庄的分店，专门负责黄金首饰等贵重物品方面的投
资业务。本店专门帮武林高手们将大额资金变成易于储存的金条。店
铺门口有一个告示(notice)。
LONG
        );

        set("exits", ([
               "north" : __DIR__"qianzhuang",               
        ]));
        
        set("no_clean_up", 1);
        set("gold", 5000);
        set("golds", 500);
        
        set("item_desc", ([
        "notice": show_notice()
]));

        setup();
}
