#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"虚神的洞窟的尽头"NOR);
	set("long", HIB @LONG
这洞穴像是一直延申到地底去.而风从地底不停地吹
上来. 一些奇奇怪怪的图形画满了整个洞穴,除此之外,
地上的足迹也是零零乱乱的.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
if (random(2)==0)
	set("exits", ([
//		"west" : "/d/migong/lev20/dong21",
		"east" : __DIR__"dong99",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(3)+1),
		"north" : __DIR__"dong99",
	]));
	set("exits", ([
		"east" : __DIR__"dong99",
//		"west" : "/d/migong/lev20/dong21",
	]));
if (random(2)==0)
	set("exits", ([
//		"west" : "/d/migong/lev20/dong21",
            	"east" : __DIR__"dong99",
		"south" : __DIR__"dong99",
		"north" : __DIR__"dong99",
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/player" : 3,
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
