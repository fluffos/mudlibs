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
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！南面山势连绵，
正是西岳——华山，东面是赫赫有名的潼关。
LONG
        );

        set("exits", ([
               "west" : __DIR__"guandaoe5",
               "southeast" : __DIR__"tongguan",
               "south" : __DIR__"guandaoe2",
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
