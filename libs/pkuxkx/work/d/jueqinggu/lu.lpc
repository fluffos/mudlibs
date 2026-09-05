//绝情谷
// By Zine 

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "石子路");
        set("long", 
"这里是一条小石子铺成的道路，南面是一片大草地。\n"

        );
        
        set("exits", ([
               // "northwest" : __DIR__"xiaolu2",
               // "southwest" : __DIR__"xiaolu2",
                "south" : __DIR__"caodi",
                "north" : __DIR__"lu2",
                //"east" : __DIR__"shuitan",
                //"northeast" : "xiaolu2",
                
        ]));
        set("objects", ([
        
        __DIR__"npc/diji-dizi" : 2,
        ]));
        set("outdoors", "jueqinggu");
        setup();
   
}


int valid_leave(object me,string dir)
{  
	if (dir=="south")
    {
        if (!userp(me)&&me->query("扫地"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
    }
	return ::valid_leave(me, dir);
}