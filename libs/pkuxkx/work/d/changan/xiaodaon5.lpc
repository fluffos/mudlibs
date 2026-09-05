//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小道");
        set("long", @LONG
这是长安城北面宫墙下的小道，小道西面就是大明宫
玄武门前的宽阔大道，小道沿着宫墙一路往东。
LONG
        );

        set("exits", ([
               "east" : __DIR__"xiaodaon6",
               "west" : __DIR__"xiaodaon4",
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
