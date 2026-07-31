#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"水裂山谷"NOR);
	set("long", WHT @LONG
    你一个神秘的地方，此处是一个四周都围绕著高山峻岭的山谷
山谷的的中央有一个漂亮的湖，湖的四周有许多的垂杨，并且遍地
鲜花绿草，并且从此望去天空明晰可见，这里真是个世外桃源。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_npc",1);
	set("exits", ([
		"south" : __DIR__"dong100",
		"north" : __DIR__"dong9"+(random(4)+6),
		"east" : __DIR__"dong9"+(random(4)+6),
		"west" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(5)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+6),
            	"east" : __DIR__"dong9"+(random(4)+6),
		"south" : __DIR__"dong9"+(random(4)+6),
		"north" : __DIR__"dong9"+(random(4)+6),
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/lev8" : 2,
     __DIR__"npc/lev6" : 2,
     __DIR__"npc/lev7" : 2,
         ]));
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if ( !present("water jian", me) && dir == "south" )
        return notify_fail("一个声音拦住了你：你通过水之力量使的考验了吗??\n");
       if ( !present("water cloth", me) && dir == "south" )
        return notify_fail("一个声音拦住了你：你通过水之精灵王的考验了吗??\n");

	if (dir =="south")
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
