
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"古代遗迹"NOR);
	set("long", GRN @LONG
   这里是个危险的区域，很大且很容易迷路，从不少死里逃生的居民口中
获知这区域内除了一些毒物之外还住著专门猎人头的矮灵族，已经有不少
居民进去之後就没有回来过。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"south" : __DIR__"dong20",
                "north" : __DIR__"dong71",
		"east" : __DIR__"dong1"+(random(8)+1),
                "west" : __DIR__"dong1"+(random(8)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong20",
                "west" : __DIR__"dong1"+(random(8)+1),
"north" : __DIR__"dong71",
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong20",
                "north" : __DIR__"dong71",
	]));
         set("objects", ([
              __DIR__"npc/lev3" : random(6),
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
	
       if ( !present("earth meteor", me) && dir == "north" )
        return notify_fail("一个士兵拦住了你：你通过大地之力量使的考验了吗??\n");
       if ( !present("earth badge", me) && dir == "north" )
        return notify_fail("一个士兵拦住了你：你通过大地之精灵王的考验了吗??\n");

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
