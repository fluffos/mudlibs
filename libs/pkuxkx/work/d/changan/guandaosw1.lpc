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
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！北面就是长安城
了。西南面通过杜陵穿过秦岭达到汉中，是著名的子午道。
LONG
        );

        set("exits", ([
               "northeast" : __DIR__"guandaos2",               
               "southwest" : __DIR__"guandaosw2",
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
