inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "前院");
        set("long", 
"这里是建康府都府的前院，只栽种了几棵古树。\n"

        );
        set("exits", ([
                
                "north" : __DIR__"dating",
                "west" : __DIR__"xier",
                "south" : __DIR__"huilang1",
                "east" : __DIR__"donger",
                
        ]));
        set("objects", ([
		__DIR__"npc/zongguan" : 1,
        //"/d/city/npc/bing" : 1,
        
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}
int valid_leave(object me,string dir)
{
	if (dir=="north"&&!userp(me)&&me->query("is_puren"))
	return notify_fail(".");
	return ::valid_leave(me,dir);
}
