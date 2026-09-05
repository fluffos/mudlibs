
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "太液池畔");
        set("long", @LONG
这是风景优美的太液池，四周回廊蜿蜒，杨柳成荫，绿水弥漫，
水中莲花盛开，远处水中蓬莱山隐约可见，东面有渠水从东内苑的
龙首池流入太液池中。
LONG        );
        
        set("exits", ([
                "southwest" : __DIR__"taiye-1",
                "northwest" : __DIR__"taiye-4",
                "east" : __DIR__"liyuan"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        set("outdoors", "changan");
        setup();
}