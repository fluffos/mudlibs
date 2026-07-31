// armorroom.c 炼甲室，干将莫邪在此炼制各种道具
// Written by Doing Lu 1998/11/3

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIC "炼甲室" NOR);
	set("long",
"这里是炼甲的地方，干将的二弟子掌甲童子专门在这里炼护甲的粗坯\n"
"。屋子里收拾得干干净净，没有一点多余的东西。屋角有一个火炉，暗暗\n"
"的火苗不断的跳动，旁边放着一些打造使用的工具。一个眉清目秀的童子\n"
"坐在火炉旁，正在思索，看到你进来似乎浑不在意。\n"
);

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("objects", ([
		__DIR__"npc/zhangarmor" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"jianchang",		
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	object tongzi;

	if (! objectp(tongzi = present("tongzi", environment(me))) || tongzi->query_temp("item/铸造中"))
	{
		me->delete_temp("item");
		return ::valid_leave(me, dir);
	}
	if (objectp(present("jian pi", me)))
	{
		message_vision("掌甲童子对$N道：收好甲坯，记得交给我师傅，不要弄丢了。\n", me);
	}

	if (me->query_temp("item"))
	{
		message_vision("掌甲童子对$N说道：你怎么这就走了？还没铸完甲呢。\n", me);
		if (me->query_temp("item/mat_id1") &&
		    objectp(ob = present(me->query_temp("item/mat_id1"), tongzi)))
		{
			ob->move(me);
			message_vision("掌甲童子把" + ob->query("name") + "还给了$N。\n", me);
		}
		if (me->query_temp("item/mat_id2") &&
		    objectp(ob = present(me->query_temp("item/mat_id2"), tongzi)))
		{
			ob->move(me);
			message_vision("掌甲童子把" + ob->query("name") + "还给了$N。\n", me);
		}
		me->delete_temp("item");
	}
	return ::valid_leave(me, dir);
}
