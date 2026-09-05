//晋阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
#include "/d/parties/public/entry.h"
void create()
{
        set("short", "官道");
        set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。路上行人纷纷，部分
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！东北面就是晋阳
城了。
LONG
        );

        set("exits", ([
               "southwest" : __DIR__"guandaow2",
               "northeast" : __DIR__"jinsumen",

        ]));
        set("self_build_entry",1);
        set("outdoors", "jinyang");
        setup();
        
}
