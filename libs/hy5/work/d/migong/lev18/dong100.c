#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"不归的迷宫的尽头"NOR);
	set("long", HIM @LONG
   你来到了一个破旧的废墟，到处散落著颓圮的石柱和石块。城市大道在
这里被瓦砾堆给堵死了。这片残破萧条的景像和城门附近雄伟瑰丽的建筑
真是个极为讽刺的对比，你的直觉告诉你还是往回走才能找到出路。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
if (random(2)==0)
	set("exits", ([
		"west" : "/d/migong/lev19/dong21",
		"east" : __DIR__"dong71",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(3)+1),
		"north" : __DIR__"dong99",
	"west" : "/d/migong/lev19/dong21",
	]));
	set("exits", ([
		"east" : __DIR__"dong99",
		"west" : "/d/migong/lev19/dong21",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : "/d/migong/lev19/dong21",
            	"east" : __DIR__"dong99",
		"south" : __DIR__"dong99",
		"north" : __DIR__"dong99",
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/player" : 2,
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

       if ( !present("earth shield", me) && dir == "west" )
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
