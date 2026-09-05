inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIM"后庭"NOR);
        set("long", 
"这里是都统制府的后庭，种了一些花草，娇艳但并不出奇。\n"

        );
        set("exits", ([
                
                "north" : __DIR__"houmen",
                "south" : __DIR__"houting",
                
        ]));
        set("objects", ([
		__DIR__"npc/huanong" : 1,
        __DIR__"obj/gang" : 1,
        
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}

int valid_leave(object me,string dir)
{
	if (dir=="north"&&!userp(me)&&me->query("is_yahuan"))
	return notify_fail(".");
	return ::valid_leave(me,dir);
}
