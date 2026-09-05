inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "阡陌小路"NOR);
        set("long", 
"这里是三山门外的一条小路，西北不远是一片大湖。\n"

        );
        set("exits", ([
                
				"northwest" : __DIR__"lakes2",
				"east" : __DIR__"sanshan",
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
	if (dir=="northwest"&&!userp(me))
	return 0;
	return ::valid_leave(me,dir);
}
