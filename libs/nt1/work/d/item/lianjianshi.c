// lianjianshi.c 炼剑室，干将莫邪在此炼制各种道具
// Written by Doing Lu 1998/11/3

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIC "炼剑室" NOR);
	set("long",
"这里是炼剑的地方，干将的大弟子掌剑童子专门在这里炼剑的粗坯。\n"
"屋角处有一个火炉，火光暗暗的，看来他也不忙，屋里到处堆着各种各样\n"
"的剑坯，看来都是一些没有炼成的剑的雏形。\n"
);

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("objects", ([
		__DIR__"npc/zhangjian" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"jianchang",		
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	object tongzi;

	if (! objectp(tongzi = present("tongzi", environment(me))) || tongzi->query_temp("item/铸造中"))
	{
		// 如果掌剑童子正在铸造或者不在这个屋子内，就不提示任何信息
		return ::valid_leave(me, dir);
	}
	if (objectp(present("jian pi", me)))
	{
		message_vision("掌剑童子对$N道：收好剑坯，一定要交给我师傅啊。\n", me);
	}

	if (me->query_temp("item"))
	{
		message_vision("掌剑童子对$N说道：你怎么这就走了？还没铸完剑呢。\n", me);
		if (me->query_temp("item/mat_id1") &&
		    objectp(ob = present(me->query_temp("item/mat_id1"), tongzi)))
		{
			ob->move(me);
			message_vision("掌剑童子把" + ob->query("name") + "还给了$N。\n", me);
		}
		if (me->query_temp("item/mat_id2") &&
		    objectp(ob = present(me->query_temp("item/mat_id2"), tongzi)))
		{
			ob->move(me);
			message_vision("掌剑童子把" + ob->query("name") + "还给了$N。\n", me);
		}
		me->delete_temp("item");
	}
	return ::valid_leave(me, dir);
}
