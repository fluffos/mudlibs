
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "/d/parties/public/entry.h"
void create()
{
        set("short", HIM+"百"+HIC+"花"+HIW+"潭"+NOR);
        set("long", "这里百花潭，位于浣花溪南岸，与青羊宫为邻。\n");
       

        set("exits", ([
               
               "southeast" : __DIR__"wuhouci",
               "north" : __DIR__"jinjiang1",
                
                
        ]));
        set("objects", ([
		
        __DIR__"npcs/girl" : 1,
        ]));
        set("couldfish",1);
        set("outdoors", "chengdu");
        setup();
   
}

int valid_leave(object me,string dir)
{  
	if (dir=="north")
    {
           return notify_fail("锦江看看就好了，难道你真要投河自尽吗？\n");
        
    }
	return ::valid_leave(me, dir);
}