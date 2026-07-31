
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"炎之都市"NOR);
	set("long", HIY @LONG
  由于火元素的影响，这附近全是砂漠，而这炎之都市正是在
这砂漠绿洲上的一颗明珠!!附近人来人往，叫卖声，说话声，
吵成一片。
LONG NOR);
set("magicroom",1);
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong23",
		"north" : __DIR__"dong71",
	]));
         set("objects", ([
              __DIR__"npc/player" : random(2),
         ]));

	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if ( !present("fire jian", me) && dir == "north" )
        return notify_fail("一个士兵拦住了你：你通过炎之力量使的考验了吗??\n");
       if ( !present("fire armor", me) && dir == "north" )
        return notify_fail("一个士兵拦住了你：你通过炎之精灵王的考验了吗??\n");

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
