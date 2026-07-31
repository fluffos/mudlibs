
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"混沌的迷宫"NOR);
	set("long", RED @LONG
这里是混沌的迷宫,似乎是用来避难的地方。然而地
上到处是一堆堆的骨骸与乾掉的血迹。更让人觉得气氛
显得十分的诡异。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"north" : __DIR__"dong71",
                "northdown" : __DIR__"dong20",
		"eastsouth" : __DIR__"dong1"+(random(8)+1),
                "westnorth" : __DIR__"dong1"+(random(8)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong20",
                "north" : __DIR__"dong1"+(random(8)+1),
"north" : __DIR__"dong71",
	]));
if (random(3)==1)
	set("exits", ([
		"east" : __DIR__"dong20",
                "north" : __DIR__"dong71",
	]));
         set("objects", ([
              __DIR__"npc/lev3" : random(3),
              __DIR__"npc/lev5" : random(3),
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if ( !present("dark blade", me) && dir == "north" )
        return notify_fail("一个士兵拦住了你：你通过懒惰之坠天使的考验了吗??\n");
       if ( !present("dark shield", me) && dir == "north" )
        return notify_fail("一个士兵拦住了你：你通过嫉妒之坠天使的考验了吗??\n");

	if (dir =="north")
	{

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}
