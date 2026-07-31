// /d/kunming/qiao
// netkill /98/8/14/


#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "独木桥" NOR);
        set("long", @LONG
一座独木桥，也不知是什么时候架起来的，走在上面摇摇晃晃，很是
危险，当时要过河的话，只有走这里。从桥上望下去，只见急流勇潺，一
掉下去，肯定没命。
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "south" : __DIR__"road6", 
                "north"  :__DIR__"road5",
                
        ]));
        set("objects", ([
            "d/kunming/npc/qiangdao" : 2,
	]));
        setup();
}

int valid_leave(object me, string dir)
{               if ( me->query_temp("dirs1") && (dir=="south"))
                return ::valid_leave(me, dir);

                if ( me->query_temp("dirs2") && (dir=="north"))
                return ::valid_leave(me, dir);

	        if ( !me->query_temp("dirs") && ( dir == "south" || dir =="north" ) &&
		objectp(present("qiang dao", environment(me))))
	        return notify_fail("强盗把手一伸 ，说道：不给钱就想过桥，你找死啊。\n");
		
                return ::valid_leave(me, dir);

}

