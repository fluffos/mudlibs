//Zine Dec 1 2010

inherit ROOM;
#include "/d/parties/public/entry.h"
void create()
{
        set("short", "铜雀台");
        set("long", @LONG
这里是铜雀台，相传曹操击败袁绍时修建。往上可以登顶。
LONG
        );
        set("outdoors", "beijing");
        set("exits", ([
		"northeast" : __DIR__"puyang",
        "up" : "/d/wizard/zine/safari",
        ]));
	    set("self_build_entry",1);
        setup();
        
}


int valid_leave(object me,string dir)
{
    
	if (me->query("combat_exp")<5000000&&dir=="up")
    {
           return notify_fail("你的经验太低，登上铜雀台只会受人耻笑。\n");
        
    }
    if (!userp(me)&&dir=="up")
    {
        return notify_fail("畜生不许上！\n");
    }
	return ::valid_leave(me, dir);
}