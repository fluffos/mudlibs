#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"红莲的迷宫的尽头"NOR);
	set("long", HIR @LONG
  此处是一个火山熔洞，四周都是奇怪的火红色岩石，并且有时有一些奇怪的
岩石结晶，当其被火光映照之时，会反射出绚丽的光线，加上原有的火红构成一副
优美的景色，
LONG NOR);
set("magicroom",1);
set("magicset",1);

	set("exits", ([
		"east" : __DIR__"dong99",
		"west" : "/d/migong/lev17/dong01",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : "/d/migong/lev17/dong01",
            	"east" : __DIR__"dong99",
		"south" : __DIR__"dong99",
		"north" : __DIR__"dong99",
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/player" : 1,
     __DIR__"npc/lev8" : 2,
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

       if ( !present("fire hat", me) && dir == "west" )
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
