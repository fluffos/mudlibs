
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"孤高之城"NOR);
	set("long", HIC @LONG
   这是一个建在高山上的城堡，墙壁及地板都是以大理石铺设成 墙上
正有几只火把燃烧著，而天花板上则有许多的奇怪的小孔，应该是此城
堡的通风孔，由四周的景物看来此地必定有千年以上的历史，但是景物
依旧且空气清新.
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