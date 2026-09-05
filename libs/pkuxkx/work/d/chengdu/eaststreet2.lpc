
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "东大街");
        set("long", "这里是成都的东大街，西北面就是总督府了。\n");
       

        set("exits", ([
               "northwest" : __DIR__"zongdufu",
               "north" : __DIR__"dangpu",
               "south" : __DIR__"jinjiang3",
               "west" : __DIR__"southstreet2",
                "southeast" : __DIR__"eaststreet1",
                
        ]));
        
        set("outdoors", "chengdu");
        setup();
   
}

int valid_leave(object me,string dir)
{  
	if (dir=="south")
    {
           return notify_fail("锦江看看就好了，难道你真要投河自尽吗？\n");
        
    }
	return ::valid_leave(me, dir);
}