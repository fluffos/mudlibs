//晋阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "官道");
        set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。路上行人纷纷，部分
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！北面就是著名的
雁门关了。
LONG
        );

        set("exits", ([
               "southdown" : __DIR__"guandaon1",
               "northup" : __DIR__"yanmenguan",

        ]));

        set("outdoors", "jinyang");
        setup();
        
}
