//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "杜陵");
        set("long", @LONG
位于长安南郊的杜陵原，僪、浐两河流经此地，是汉宣帝刘询的
陵墓所在地。
LONG
        );

        set("exits", ([
               "northeast" : __DIR__"guandaosw1",
               "southwest" : __DIR__"guandaosw3",
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
