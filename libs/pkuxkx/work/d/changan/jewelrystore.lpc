//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit JEWELRY_STORE;
void create()
{
        set("short", HIC"月记金店"NOR);
        set("long", @LONG
这里是月记银号的分店，专门负责黄金首饰等贵重物品方面的投
资业务。本店专门帮武林高手们将大额资金变成易于储存的金条。店
铺门口有一个告示(notice)。
LONG
        );

        set("exits", ([
               "east" : __DIR__"eastmarket-3",               
        ]));
        
        set("no_clean_up", 1);
        set("gold", 5000);
        set("golds", 500);
        
        set("item_desc", ([
        "notice": show_notice()
]));
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}
