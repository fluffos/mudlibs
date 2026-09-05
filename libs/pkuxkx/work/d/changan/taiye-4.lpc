
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "太液池畔");
        set("long", @LONG
这是风景优美的太液池，四周回廊蜿蜒，杨柳成荫，绿水弥漫，
水中莲花盛开，远处水中蓬莱山隐约可见，北面就是大明宫的北大
门玄武门。
LONG        );
        
        set("exits", ([
                "southeast" : __DIR__"taiye-2",
                "southwest" : __DIR__"taiye-3",
                "north" : __DIR__"xuanwudian"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        set("outdoors", "changan");
        setup();
}