// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "小池镇");
        set("long", "这里名唤小池镇，南面通向长江北岸渡口，西北面是信阳城。\n");
        
        set("exits", ([
               
               "northwest" : __DIR__"shanjiao",
               "south" : "/d/changjiangnorth/dkb3",
               //"north" : "/d/jiangzhou/guandaos4",
               
                
        ]));
        
   
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