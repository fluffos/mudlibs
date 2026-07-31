#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"红莲的迷宫"NOR);
	set("long", HIR @LONG
  此处是一个火山熔洞，四周都是奇怪的火红色岩石，并且有时有一些奇怪的
岩石结晶，当其被火光映照之时，会反射出绚丽的光线，加上原有的火红构成一副
优美的景色，
LONG NOR);
set("magicroom",1);
set("magicset",1);
set("no_npc",1);
	set("exits", ([
		"south" : __DIR__"dong100",
		"west" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+6),
            	"east" : __DIR__"dong9"+(random(4)+6),
		"south" : __DIR__"dong100",
		"north" : __DIR__"dong9"+(random(4)+6),
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/lev5" : 2,
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
	
       if ( !present("fire jian", me) && dir == "south" )
        return notify_fail("一个声音拦住了你：你通过炎之力量使的考验了吗??\n");
       if ( !present("fire armor", me) && dir == "south" )
        return notify_fail("一个声音拦住了你：你通过炎之精灵王的考验了吗??\n");

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
