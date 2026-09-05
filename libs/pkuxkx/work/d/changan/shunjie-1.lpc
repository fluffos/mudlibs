//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "顺街");
        set("long", @LONG
这是长安城坊间的小道，北面就是热闹的东市，西面出去
就是宽阔的朱雀大街，东南面坐落着大慈恩寺。
LONG
        );

        set("exits", ([
               "north" : __DIR__"eastmarket-3",
               "southeast" : __DIR__"daciensi",
               "west" : __DIR__"southstreet",

        ]));

        set("outdoors", "huashan");
        setup();
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
}
