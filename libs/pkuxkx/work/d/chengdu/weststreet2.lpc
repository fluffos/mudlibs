
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "西大街");
        set("long", "这里是成都的西大街，东南面就是总督府了。\n");
       

        set("exits", ([
               "northwest" : __DIR__"weststreet1",
               "east" : __DIR__"northstreet2",
               "south" : __DIR__"jinjiang2",
               "north" : __DIR__"chaguan",
                "southeast" : __DIR__"zongdufu",
                
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