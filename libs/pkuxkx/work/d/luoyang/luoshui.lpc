//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"洛水"NOR);
        set("long", @LONG
远远看去，洛水映在阳光之下，泛起点点银光。北面一条木板架起的
木桥搭建了一个小码头，几艘船停靠在码头旁边。
LONG
        );

        set("exits", ([
               "south" : __DIR__"guandao8",  
               "northup" : "/d/huanghe/dkn2",         
        ]));
        set("objects", ([
              __DIR__"npc/randomnpc" : random(4),
        ]));
        set("couldfish",1);
        set("outdoors", "luoyang");
        setup();
       
}

int valid_leave(object me,string dir)
{  
	if (dir=="northup")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}