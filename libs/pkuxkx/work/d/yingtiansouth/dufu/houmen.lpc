inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", RED"都府后门"NOR);
        set("long", 
"这里是都统制府的后门，连接着纵星桥。\n"

        );
        set("exits", ([
                
                //"east" : __DIR__"",
                "north" : "/d/yingtiannorth/zongxingqiao",
                //"west" : __DIR__"zuoxiang",
                "south" : __DIR__"houyuan",
                
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
	if (dir=="south")
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