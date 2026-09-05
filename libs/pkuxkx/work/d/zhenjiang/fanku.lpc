// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "藩库");
        set("long", @LONG
这里是掌管镇江府钱粮的仓库。
LONG);
        
        set("exits", ([     
                
                "south" : __DIR__"w2",
                "north" : __DIR__"micang",
                "east" : __DIR__"yinku",
]));
        set("objects", ([
		__DIR__"npc/kanshou" : 1,
        
        ]));  
       
   setup();
}

int valid_leave(object me,string dir)
{  
	if (dir=="north"||dir=="east")
    {
        if (!me->query_temp("jn/step5d"))
        {
            return notify_fail(HIR"库房重地！\n"NOR);
        }
       
    }
	return ::valid_leave(me, dir);
}