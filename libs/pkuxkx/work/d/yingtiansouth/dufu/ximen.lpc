inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "西门");
        set("long", 
"这里是建康府都统制府的西侧门，几个下人正准备去采办点东西。\n"

        );
        set("exits", ([
                
                "east" : __DIR__"huilang2",
                "west" : "/d/yingtiansouth/z_street1",
               // "west" : __DIR__"dating",
               // "south" : __DIR__"shiwei2",
                
        ]));
        set("objects", ([
		//"/d/yingtiannorth/npc/wujiang" : 1,
        __DIR__"npc/shiwei" : 1,
        
        ]));
		set("dufu_gate",1);
        //set("outdoors", "yingtianfu");
        setup();
   
}
int valid_leave(object me,string dir)
{
	if (dir=="east")
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