
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", YEL"石桥"NOR);
        set("long", "这里是一座跨过锦江的石桥，北面就是总督府了。看着桥边的锦江，不禁有\n些神往。\n");
       

        set("exits", ([
               "north" : __DIR__"zongdufu",
               "east" : __DIR__"eaststreet2",
               "southeast" : __DIR__"jinjiang3",
               "northwest" : __DIR__"jinjiang2",
               //"west" : __DIR__"chaguan",
                "south" : __DIR__"southstreet1",
                
        ]));
        
        set("outdoors", "chengdu");
        setup();
   
}

int valid_leave(object me,string dir)
{  
	if (dir=="southeast"||dir=="northwest")
    {
           return notify_fail("锦江看看就好了，难道你真要投河自尽吗？\n");
        
    }
	return ::valid_leave(me, dir);
}