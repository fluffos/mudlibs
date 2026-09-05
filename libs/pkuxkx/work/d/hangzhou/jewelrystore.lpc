#include <ansi.h>
inherit JEWELRY_STORE;
void create()
{
        set("short", HIC"江南金店"NOR);
        set("long", @LONG
这里是江南钱庄的分店，专门负责黄金首饰等贵重物品方面的投资业务。本
店专门帮武林高手们将大额资金变成易于储存的金条。店铺门口放置着一个告示
(notice)。
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
