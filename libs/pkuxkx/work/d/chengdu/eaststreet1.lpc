
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "东大街");
        set("long", "这里是成都的东大街，往来的人们行色匆匆。\n");
       

        set("exits", ([
               "east" : __DIR__"eastgate",
               "south" : __DIR__"jinjiang4",
               "north" : __DIR__"qianzhuang",
                "northwest" : __DIR__"eaststreet2",
                
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