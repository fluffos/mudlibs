//Zine 25 Nov 2010
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "长江岸边");
        set("long", @LONG
这里是长江南岸，远远向北望去，江面被雾色笼罩。
LONG
        );
        set("exits", ([
             "northwest" : __DIR__"cjn2",
             "southwest" : "/d/suzhou/guandaond",
        ]));
        set("outdoors", "changjiang");

        setup();
}
int valid_leave(object me,string dir)
{  
	if (dir=="southwest")
    {
        if (!userp(me)&&!me->query("is_trainee")&&!me->query_temp("rider"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}
