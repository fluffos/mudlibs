//Zine 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "宝船厂大门");
        set("long", @LONG
这里是地处龙江的宝船厂，朝廷用来建造战船的所在。
LONG
        );

        set("exits", ([
               "southeast" : __DIR__"tulun3",
               "northwest" : "/d/changjiang/dkn2a",
			   "enter" : __DIR__"baochuan_1",

        ]));

        set("outdoors", "yingtianfu");
        setup();
        
}

int valid_leave(object me,string dir)
{  
	if (dir=="northwest")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	if (dir=="enter"&&!me->query("mingpin"))
	{
		return notify_fail("非大明官员禁止擅入宝船厂。\n");
	}
	return ::valid_leave(me, dir);
}