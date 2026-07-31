// lianjianshi.c 炼杖室，干将莫邪在此炼制各种道具
// Written by Doing Lu 1998/11/3

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIC "炼杖室" NOR);
	set("long",
"这里是炼杖的地氛痊干将的六弟子掌杖童子专门在这里炼杖的粗坯。\n"
"屋角处有一个火炉，火苗不断的跳跃闪动，旁边放了许多的模具，一个童\n"
"子正在冥思苦想，似乎正在研究那些模具。\n"
);

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("objects", ([
		__DIR__"npc/zhangzhang" : 1,
	]));

	set("exits", ([
		"northeast" : __DIR__"jianchang",		
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	object tongzi;

	if (! objectp(tongzi = present("tongzi", environment(me))) || tongzi->query_temp("item/铸造中"))
	{
		// 如果掌杖童子正在铸造或者不在这个屋子内，就不提示任何信息
		return ::valid_leave(me, dir);
	}
	if (objectp(present("jian pi", me)))
	{
		message_vision("掌杖童子对$N道：收好杖坯，一定要交给我师傅啊。\n", me);
	}

	if (me->query_temp("item"))
	{
		message_vision("掌杖童子对$N说道：你怎么这就走了？还没铸完杖呢。\n", me);
		if (me->query_temp("item/mat_id1") &&
		    objectp(ob = present(me->query_temp("item/mat_id1"), tongzi)))
		{
			ob->move(me);
			message_vision("掌杖童子把" + ob->query("name") + "还给了$N。\n", me);
		}
		if (me->query_temp("item/mat_id2") &&
		    objectp(ob = present(me->query_temp("item/mat_id2"), tongzi)))
		{
			ob->move(me);
			message_vision("掌杖童子把" + ob->query("name") + "还给了$N。\n", me);
		}
		me->delete_temp("item");
	}
	return ::valid_leave(me, dir);
}
