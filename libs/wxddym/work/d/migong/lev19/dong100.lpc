#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"飞船之遗迹的控制室"NOR);
	set("long", CYN @LONG
   传说这是一艘叫做天马号的飞船，是魔法王国的遗物，据说以前是
一座飞在天空的城市，不知什么时候掉到了这里。你说在的地方依稀还
看的到是甲板的样子，附近雾气重重，雾中的杀气越来越浓了。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
if (random(2)==0)
	set("exits", ([
		"up" : "/d/migong/lev20/dong21",
		"down" : "/d/migong/lev21/dong21",
		"east" : __DIR__"dong99",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(3)+1),
		"north" : __DIR__"dong99",
		"up" : "/d/migong/lev20/dong21",
		"down" : "/d/migong/lev21/dong21",
	]));
	set("exits", ([
		"east" : __DIR__"dong99",
		"up" : "/d/migong/lev20/dong21",
		"down" : "/d/migong/lev21/dong21",
	]));
if (random(2)==0)
	set("exits", ([
		"up" : "/d/migong/lev20/dong21",
		"down" : "/d/migong/lev21/dong21",
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
	
    if (me->is_fighting() && dir == "up") 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_fighting() && dir == "down") 
        return notify_fail("你正打的热闹着呢!\n");

    if(me->is_busy() && dir == "up")
        return notify_fail("你现在正忙。\n");
    if(me->is_busy() && dir == "down")
        return notify_fail("你现在正忙。\n");

       if ( !present("air boot", me) && dir == "down" )
        return notify_fail("一股神奇的力量挡住了你!!\n");
       if ( !present("air boot", me) && dir == "up" )
        return notify_fail("一股神奇的力量挡住了你!!\n");

       if ( me->query("shen") > -800000 && dir == "down" )
        return notify_fail("你的所做所为不适合去暗黑世界!!\n");

       if ( me->query_skill("magic-fire",1) < 600 && dir == "down" )
        return notify_fail("你的火系魔法不适合去暗黑世界!!\n");
       if ( me->query_skill("magic-water",1) < 600 && dir == "down" )
        return notify_fail("你的水系魔法不适合去暗黑世界!!\n");
       if ( me->query_skill("magic-ice",1) < 600 && dir == "down" )
        return notify_fail("你的气系魔法不适合去暗黑世界!!\n");
       if ( me->query_skill("magic-earth",1) < 600 && dir == "down" )
        return notify_fail("你的土系魔法不适合去暗黑世界!!\n");

       if ( me->query("shen") < 800000 && dir == "up" )
        return notify_fail("你的所做所为不适合去光明世界!!\n");

       if ( me->query_skill("magic-fire",1) < 600 && dir == "up" )
        return notify_fail("你的火系魔法不适合去光明世界!!\n");
       if ( me->query_skill("magic-water",1) < 600 && dir == "up" )
        return notify_fail("你的水系魔法不适合去光明世界!!\n");
       if ( me->query_skill("magic-ice",1) < 600 && dir == "up" )
        return notify_fail("你的气系魔法不适合去光明世界!!\n");
       if ( me->query_skill("magic-earth",1) < 600 && dir == "up" )
        return notify_fail("你的土系魔法不适合去光明世界!!\n");

	if (dir =="down")
	{

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}
		
	}
	if (dir =="up")
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
