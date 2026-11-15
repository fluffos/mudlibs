// /guanwai/chuanchang.c

inherit ROOM;

void create()
{
	set("short", "船厂");
	set("long", @LONG
这里是古镇船厂。船厂是位于关外大平原中部的一个古老的小镇，此镇
西、南、北、三面是以高墙垒筑，利于坚守。东面临松花江天成天险，乃兵
家必争的要地。松花江在冬春时结冰可通行，夏秋化冻你只好找船家帮忙了。
LONG );
	set("exits", ([
		"south"  : __DIR__"xuedi3",
		"east"   : __DIR__"bingmian",
	]));
	set("outdoors", "guanwai");
	set("action_list",([
		"坐船":"give 1 silver to chuan fu",
		"一苇渡江":"cross",
	]));
	setup();
}

void init()
{
	add_action("do_cross", "cross");
}

int do_cross()
{
	object me;

	switch (NATURE_D->query_month())
	{
	case 11: case 12: case 1: case 2: case 3: case 4:
		return notify_fail("湖面结着厚厚的一层冰，你走过去不就完了？\n");
	}

	me = this_player();
	if (me->is_fighting())
	{
		tell_object(me, "怎么也得先把架打完再走吧。\n");
		return 1;
	}

	if (me->query_skill("dodge") < 100)
	{
		tell_object(me, random(2) ? "你觉得河面太宽，没有十足的把握跃过去。\n"
					  : "你看着奔腾不息的白河，心里有点紧张，不敢乱来。\n");
		return 1;
	}

	if (me->query("neili") < 100)
	{
		tell_object(me, "你的内力不够，还是休息一下再说吧。\n");
		return 1;
	}

	me->add("neili", -50);
	message_vision("$N身形一晃，轻飘飘的落入白河，只见$P脚踢浪花，渐渐远去。\n", me);
	tell_object(me, "你顺利的到达了彼岸！\n");
	me->move(__DIR__"damenkan");
	return 1;
}

int valid_leave(object me, string dir)
{
	object obj;
 

	if (dir == "east")
	{
		switch (NATURE_D->query_month())
		{
		case 11: case 12: case 1: case 2: case 3: case 4:
			message_vision("$N见江面结冻，便壮起胆子踩冰而过。\n\n", me);
			if (random(me->query_dex()) + me->query_dex() * 2 / 3 < 20)
			{
				me->receive_wound("qi", 20);
				me->receive_damage("qi", 10);
				message_vision("$N只觉得脚下一滑，全身腾空"
					       "而起，结结实实的摔在了冰面上！\n", me);
			}
			return 1;
		default:
			if (! present("chuan fu", this_object()))
			{
				obj = new(__DIR__"npc/chuanfu");
				obj -> move(environment(me));
				message_vision("船厂里走出一个船夫，瞪着眼看着$N。\n", me);
			}
			else
				message_vision("船夫在旁边拿眼瞪着$N看。\n", me);
			write("冰面化冻，你还是乘船吧！\n");
			return -1;
		}
	}
	return ::valid_leave(me, dir);
}