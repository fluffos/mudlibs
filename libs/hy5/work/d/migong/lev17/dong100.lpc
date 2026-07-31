#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", WHT"水裂山谷的尽头"NOR);
	set("long", WHT @LONG
    你一个神秘的地方，此处是一个四周都围绕著高山峻岭的山谷
山谷的的中央有一个漂亮的湖，湖的四周有许多的垂杨，并且遍地
鲜花绿草，并且从此望去天空明晰可见，这里真是个世外桃源。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"east" : __DIR__"dong99",
		"west" : "/d/migong/lev18/dong21",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : "/d/migong/lev18/dong21",
            	"east" : __DIR__"dong99",
		"south" : __DIR__"dong99",
		"north" : __DIR__"dong99",
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/player" : 1,
     __DIR__"npc/lev8" : 3,
     __DIR__"npc/lev9" : 2,
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

       if ( !present("water armor", me) && dir == "west" )
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
