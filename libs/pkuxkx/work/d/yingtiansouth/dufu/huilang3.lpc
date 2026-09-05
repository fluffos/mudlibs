inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "回廊");
        set("long", 
"这里是一条回廊，向北是一处水池。\n"

        );
        set("exits", ([
                
                "north" : __DIR__"shuichi",
                "east" : __DIR__"dongmen",
                "west" : __DIR__"dating",
                "south" : __DIR__"shiwei2",
                
        ]));
        set("objects", ([
		//"/d/yingtiannorth/npc/wujiang" : 1,
        //"/d/city/npc/bing" : 1,
        
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}
int valid_leave(object me,string dir)
{
	if (dir=="north")
	return notify_fail("你要在都统制府投水自杀吗？\n");
	return ::valid_leave(me,dir);
}