
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "东大街");
        set("long", "这里是福州的东大街，往来的人们懒懒散散的。\n");
       
	
        set("exits", ([
               "east" : __DIR__"port2",
               "north" : __DIR__"biaoju",
                "west" : __DIR__"zhongxin",
                "south" : __DIR__"port1",
                
        ]));
        
        set("outdoors", "fuzhou");
        setup();
   
}

int valid_leave(object me,string dir)
{  
	if (dir=="north")
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}