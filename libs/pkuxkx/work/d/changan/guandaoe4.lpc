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
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！此地西南面山势
连绵，正是西岳——华山，地处潼关和函谷关之间，南来北往的行商很多。
LONG
        );

        set("exits", ([
               "west" : __DIR__"tongguan",
               "east" : "/d/luoyang/hanguguan",
               //"south" : __DIR__"",

        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
