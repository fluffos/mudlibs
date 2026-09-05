//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小道");
        set("long", @LONG
这是长安城西北面城墙下的小道，小道沿着城墙一直往北延伸。
LONG
        );

        set("exits", ([
               "south" : "/d/xingxiu/xxroad1",
               "north" : __DIR__"xiaodaonw2",
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
