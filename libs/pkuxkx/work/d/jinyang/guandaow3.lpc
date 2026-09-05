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
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！南面隔着黄河就
是洛阳城了。
LONG
        );

        set("exits", ([
               "south" : "/d/huanghenorth/dkb2",
               "northeast" : __DIR__"guandaow2",

        ]));

        set("outdoors", "jinyang");
        setup();
        
}

int valid_leave(object me,string dir)
{  
	if (dir=="south")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}