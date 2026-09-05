inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "都府东门");
        set("long", 
"这里是建康府都统制府的东门，通向建康府的东门。\n"

        );
        set("exits", ([
                
               // "north" : __DIR__"huilang1",
               // "west" : __DIR__"puren",
                "west" : __DIR__"huilang3",
                "east" : "/d/yingtiansouth/chaoyang",
                
        ]));
        set("objects", ([
		//"/d/yingtiannorth/npc/wujiang" : 1,
        __DIR__"npc/shiwei" : 1,
        
        ]));
		set("dufu_gate",1);
        set("outdoors", "yingtianfu");
        setup();
   
}
int valid_leave(object me,string dir)
{
	if (dir=="west")
	{
		if (!userp(me))
		return 0;
		else if (me->query("song/pro"))
		return ::valid_leave(me,dir);
		else if (!me->query_temp("dutongfu/greet"))
		return notify_fail("没有经过通传，任何人等不得擅闯都统治府。\n");
		else
		return ::valid_leave(me,dir);
	}
	return ::valid_leave(me,dir);
}