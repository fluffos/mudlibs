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
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！东南面就是北京
城了。
LONG
        );

        set("exits", ([
               "northwest" : __DIR__"guandaoe2",
               "southeast" : "/d/beijing/deshengmen",
               "west" : __DIR__"guandaos2"
        ]));

        set("outdoors", "saiwai");
        setup();
        
}

int valid_leave(object me,string dir)
{  
	if (dir=="northwest" || dir=="west")
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}