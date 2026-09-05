//Zine 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "官道");
        set("long", @LONG
这是一条土路，往南是应天府。往北远远可以望见长江。东面是一座大湖。
LONG
        );

        set("exits", ([
               "southeast" : __DIR__"tulun2",
               "northeast" : "/d/changjiang/dkn2",
               "northwest" : __DIR__"chuanchang",

        ]));

        set("outdoors", "yingtianfu");
        setup();
        
}

int valid_leave(object me,string dir)
{  
	if (dir=="northeast")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}