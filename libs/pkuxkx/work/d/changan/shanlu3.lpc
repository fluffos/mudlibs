//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
山路陡峭，林中郁郁葱葱。南面山势连绵起伏，正是西岳——华山。
LONG
        );

        set("exits", ([
               "northdown" : __DIR__"shanlu2",
//               "east" : __DIR__"guandaoe3",
               "south" : "/d/huashan/canglong",

        ]));

        set("outdoors", "huashan");
        setup();
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
}
