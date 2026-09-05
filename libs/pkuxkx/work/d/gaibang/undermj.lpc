#include <room.h>
inherit ROOM;

void create()
{
        set("short", "草棚密室");
        set("long", @LONG
这是丐帮重要密道之一。由此上往，可直达草棚。四周光线昏暗，
似乎有几个黑暗的洞口在你身边。脚下地上扔满了垃圾，踩上去悉悉
索索地响。
LONG
        );

        set("exits", ([
                        "up" : "/d/mingjiao/fandian",
                        "southeast" : __DIR__"mjandao5",
        ]));
        set("no_task",1);
        set("objects",([
                 CLASS_D("gaibang") + "/jiang-sh" : 1,
        ]));
        setup();
        
        
}

int valid_leave(object me,string dir)
{  
	if (dir=="southeast")
    {
        if (!wizardp(me))
        {
            return notify_fail("因暗道渗水，已不能通行。\n");
        }
        
    }
	return ::valid_leave(me, dir);
}