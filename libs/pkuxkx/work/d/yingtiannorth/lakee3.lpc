inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", YEL"田间路"NOR);
        set("long", 
"这里是石城门外田间的一条小路，西南不远是一片大湖。\n"

        );
        set("exits", ([
                
				"northeast" : __DIR__"shicheng",
				"southwest" : __DIR__"lakee2",
        ]));
        /*set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));*/
		set("no_task",1);
        set("outdoors", "yingtianfu");
        setup();
   
}

int valid_leave(object me,string dir)
{
	if (dir=="southwest"&&!userp(me))
	return 0;
	return ::valid_leave(me,dir);
}
