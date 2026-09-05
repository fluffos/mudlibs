//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小道");
        set("long", @LONG
这是长安城北面宫墙下的小道，小道随着大明宫的宫墙角
往南通向通化门。
LONG
        );

        set("exits", ([
               "south" : __DIR__"xiaodaone1",
               "west" : __DIR__"xiaodaon5",
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
