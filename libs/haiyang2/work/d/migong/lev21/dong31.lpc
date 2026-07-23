
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"背德城"NOR);
	set("long", BLU @LONG
背叛神的城市，这里生活着的都是魔族和一些妖物，
魔族，背弃神的种族，在几千年的流放下，依然顽强的
生存着。由此可以看出任何种族都有其存在的理由和方
式。
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