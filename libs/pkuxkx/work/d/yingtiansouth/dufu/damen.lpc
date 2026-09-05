//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIR"都统制府大门"NOR);
        set("long", 
"这里是建康府诸军督统治孟珙的府邸。\n"

        );
        set("exits", ([
                
                "north" : __DIR__"qianting",
                "south" : "/d/yingtiansouth/huaiqingqiao",
                "east" : __DIR__"jimashi",
                //"west" : __DIR__"neicheng/donganmen",
                
        ]));
        set("objects", ([
		//"/d/yingtiannorth/npc/wujiang" : 1,
        __DIR__"npc/shiwei" : 1,
        
        ]));
		set("dufu_gate",1);
        set("dirty",5+random(5));
		set("inbound","west");
        set("outdoors", "yingtianfu");
        setup();
   
}
int valid_leave(object me,string dir)
{
	if (dir=="north")
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