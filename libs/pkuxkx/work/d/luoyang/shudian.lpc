//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"镖局大门"NOR);
        set("long", @LONG
这里原来是一家书店，店主家道中落，把这里卖给了一家镖局，现在
在这家镖局做了一个看门小厮。
LONG
        );
        set("item_desc", ([
        ]) );

        set("exits", ([
               "south" : __DIR__"xidajie1", 
               "enter" : __DIR__"biaoju",
        ]));
        set("objects", ([
        __DIR__"npc/shudianlaoban":1,
//                __DIR__"npc/laoban" : 1,
        ]));

//        set("outdoors", "luoyang");
        setup();
        
}

int valid_leave(object me,string dir)
{  
	if (dir=="enter")
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}