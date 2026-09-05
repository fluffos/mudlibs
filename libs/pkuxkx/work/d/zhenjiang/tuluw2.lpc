// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "土路");
        set("long", @LONG
这里是镇江府城西的一段土路，再往西北就是西津渡了。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "southeast" : __DIR__"tuluw1",   
                "northwest" : "/d/changjiang/dkn1",
]));
     
       
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
	return ::valid_leave(me, dir);
}