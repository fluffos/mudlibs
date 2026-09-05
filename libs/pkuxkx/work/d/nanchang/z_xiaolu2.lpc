
// edit: by zine Aug 21 2010


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是山间的小路，前面是一个大广场，两旁是无尽的密林。
LONG
	);
	set("exits", ([ 		
		"south" : __DIR__"z_xiaolu1",	
        "northup" : __DIR__"z_guangchang",
		"west" : __DIR__"milin",
        "east" : __DIR__"shanlin",
    ]));
	set("no_task",1);
    set("outdoors", "nanchang");
	setup();
	
}

int valid_leave(object me, string dir)
{        
         if (dir=="west" && !me->query_temp("老林2"))
           {   me->set_temp("老林2",1);
              return notify_fail("西面可就是老林了，你真的要去吗？\n");
           }
          if (dir=="east" && !me->query_temp("山林2"))
           {   me->set_temp("山林2",1);
              return notify_fail("东面林中有虎，你真的要去吗？\n");
           }
          return ::valid_leave(me, dir);
}
