//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河拐弯处"NOR);
        set("long", @LONG
这里是黄河急拐弯处，水流陡然变急许多。
LONG
        );
        set("exits", ([
             "southwest" : __DIR__"hhb14",
             "southeast" : __DIR__"hhb13",
        ]));
       

        

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );
        set("no_task",1);
        set("no_reset",1);
		set("no_clean_up", 1);
        set("outdoors", "huanghe");
		set("no_robber",1);
        setup();
}

int valid_leave(object me,string dir)
{
	object record;
    if (dir=="north"&&!userp(me))
    {
        return notify_fail("\n");
    }
	if (dir=="north"&&userp(me))
	{
		record=load_object("/d/menggu/xiboliya");
		record->restore();
		record->add("guest_in",1);
		record->save();
		return ::valid_leave(me,dir);
	}
    
    return ::valid_leave(me,dir);
}



