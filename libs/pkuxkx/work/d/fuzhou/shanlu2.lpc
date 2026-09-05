
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "山路");
        set("long", "这里是一条弯弯曲曲的山路，南面通行福州。\n");
        set("exits", ([
               
               "southdown" : __DIR__"shanlu1",
               "northwest" : __DIR__"shanlu3",
                
        ]));
        set("outdoors", "fuzhou");
        setup();
   
}

int valid_leave(object me,string dir)
{  
	if (dir=="southdown")
    {
        if (me->query("sinan")=="yes")
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}