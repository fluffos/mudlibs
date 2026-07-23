#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"王家的灵墓的中心"NOR);
	set("long", HIM @LONG
这是传说中光神的的灵墓，通路的中央飘浮著一颗颗闪亮
的红水晶。四周的墙壁和天花板上满布著美丽的壁画和精致
的石雕。四周散发著神秘的光芒。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
if (random(2)==0)
	set("exits", ([
		"eastdown" : __DIR__"dong99",
	]));
if (random(2)==0)
	set("exits", ([
		"southdown" : __DIR__"dong7"+(random(3)+1),
		"northdown" : __DIR__"dong99",
	]));
	set("exits", ([
		"eastdown" : __DIR__"dong99",
	]));
if (random(2)==0)
	set("exits", ([
		"southdown" : __DIR__"dong99",
		"northdown" : __DIR__"dong99",
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/player" : 2,
     __DIR__"npc/lev8" : 3,
     __DIR__"npc/lev9" : 3,
     __DIR__"npc/boss" : 1,
       "/clone/box/gboxm" : 2,
         ]));
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
    if (me->is_fighting() && dir == "west") 
        return notify_fail("你正打的热闹着呢!\n");

    if(me->is_busy() && dir == "west")
        return notify_fail("你现在正忙。\n");

       if ( !present("air boot", me) && dir == "west" )
        return notify_fail("一股神奇的力量挡住了你!!\n");

	if (dir =="west")
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
