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
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！南面通往河北地
域，西北就是蒙古草原了，几个官兵在盘查个过往行人。
LONG
        );

        set("exits", ([
               "northwest" : "/d/menggu/entry_1",
               "south" : __DIR__"dajingmen",
        ]));

        set("outdoors", "saiwai");
        setup();
        
}

int valid_leave(object me,string dir)
{  
	object record;
	if (!userp(me)&&dir=="northwest")
	{
		return notify_fail("\n");
	}
	else if (userp(me)&&dir=="northwest")
	{
		record=load_object("/d/menggu/xiboliya");
		record->restore();
		record->add("guest_in",1);
		record->save();
		return ::valid_leave(me,dir);
	}
	else
	{
		return ::valid_leave(me,dir);
	}
}
