
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"矮人村庄"NOR);
	set("long", HIG @LONG
   矮人国度的主要道路,道路的两旁有火把照亮著,由於矮人高超的建筑
技术,这道路修筑的非常笔直 , 很难相信你是处在地底下数十里的地方 .
这里有著非常和平安详的气氛,恍佛是一个世外桃源.这里已经多年没有战
争了。
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong23",
		"north" : __DIR__"dong0"+(random(6)+1),
	]));
         set("objects", ([
              __DIR__"npc/player" : random(2),
         ]));

	set("no_clean_up", 0);
	setup();
}
/*
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if ( !present("water jian", me) && dir == "north" )
        return notify_fail("一个士兵拦住了你：你通过水之力量使的考验了吗??\n");
       if ( !present("water armor", me) && dir == "north" )
        return notify_fail("一个士兵拦住了你：你通过水之精灵王的考验了吗??\n");

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
*/