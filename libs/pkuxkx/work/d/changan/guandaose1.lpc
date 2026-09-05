//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "官道");
        set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。路上行人纷纷，部分
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！南面山势连绵起
伏，正是西岳——华山。
LONG
        );

        set("exits", ([
               "north" : __DIR__"guandaoe2",
//               "east" : __DIR__"guandaoe3",
               "southup" : __DIR__"guandaose2",

        ]));

        set("outdoors", "huashan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
