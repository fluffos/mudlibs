//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "渭水河畔");
        set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。路上行人纷纷，部分
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！官道北面流淌着
汹涌的渭水，官道顺着渭水一路通向黄河南岸。
LONG
        );

        set("exits", ([
               "northeast" : "/d/huanghe/hhn6",
               "south" : __DIR__"guandaon1",
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
