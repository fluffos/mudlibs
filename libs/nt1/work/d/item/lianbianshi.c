// lianbianshi.c 炼鞭室，干将莫邪在此炼制各种道具
// Written by Doing Lu 1998/11/3

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIC "炼鞭室" NOR);
	set("long",
"这里是炼鞭的地方，干将的三弟子掌鞭童子专门在这里炼鞭的粗坯。\n"
"屋角处有一个火炉，边上系着一些丝带，被火焰吹得四下飞舞，一个女孩\n"
"默默的坐在炉边，一动不动，看见你进来，微微一笑，并不搭话。\n"
);

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("objects", ([
		__DIR__"npc/zhangbian" : 1,
	]));

	set("exits", ([
		"south" : __DIR__"jianchang",		
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	object tongzi;

	if (! objectp(tongzi = present("tongzi", environment(me))) || tongzi->query_temp("item/铸造中"))
	{
		// 如果掌鞭童子正在铸造或者不在这个屋子内，就不提示任何信息
		return ::valid_leave(me, dir);
	}
	if (objectp(present("jian pi", me)))
	{
		message_vision("掌鞭童子对$N道：好了，交给我师傅吧。\n", me);
	}

	if (me->query_temp("item"))
	{
		message_vision("掌鞭童子对$N说道：别走啊，还没铸完鞭呢。\n", me);
		if (me->query_temp("item/mat_id1") &&
		    objectp(ob = present(me->query_temp("item/mat_id1"), tongzi)))
		{
			ob->move(me);
			message_vision("掌鞭童子把" + ob->query("name") + "还给了$N。\n", me);
		}
		if (me->query_temp("item/mat_id2") &&
		    objectp(ob = present(me->query_temp("item/mat_id2"), tongzi)))
		{
			ob->move(me);
			message_vision("掌鞭童子把" + ob->query("name") + "还给了$N。\n", me);
		}
		me->delete_temp("item");
	}
	return ::valid_leave(me, dir);
}
