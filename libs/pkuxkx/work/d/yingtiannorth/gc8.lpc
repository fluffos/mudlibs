//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "南广场");
        set("long", 
"这里是建康府的南广场，人来人往，热闹非常。\n"

        );
        set("exits", ([
                
                
                "east" : __DIR__"gc9",
                "west" : __DIR__"gc7",
                "north" : __DIR__"gc5",
                "south" : __DIR__"zhongcheng",
                
                
        ]));
        
        set("outdoors", "yingtianfu");
        setup();
   
}

int valid_leave(object me,string dir)
{  
	if (dir=="south")
    {
        if (me->query("sinan")=="yes")
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
    return ::valid_leave(me, dir);
}