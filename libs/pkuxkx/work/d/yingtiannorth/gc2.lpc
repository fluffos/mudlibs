//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "北广场");
        set("long", 
"这里是建康府的北广场，人来人往，热闹非常。\n"

        );
        set("exits", ([
                
                
                
                "west" : __DIR__"gc1",
                "east" : __DIR__"gc3",
                "south" : __DIR__"gc5",
                "north" : __DIR__"beimenqiao",
                
                
        ]));
        
        set("outdoors", "yingtianfu");
        setup();
   
}

int valid_leave(object me,string dir)
{  
	if (dir=="north")
    {
        if (me->query("sinan")=="yes")
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
    return ::valid_leave(me, dir);
}