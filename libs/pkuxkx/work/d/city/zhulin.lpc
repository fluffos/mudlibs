// 竹林
// edit: by zine Sep 2 2010

inherit __DIR__"skfroom1";
#include <ansi.h>

void create()
{
	set("short", "竹林");
	set("long", @LONG
一片绿意盎然的竹林，生长着许多高大的竹子。你可以把竹子劈(pi)下来。
LONG
	);
	set("exits", ([ 
		"northwest" : __DIR__"grass",
	]));
	set("no_task",1);
	setup();
	::create();
}

void init()
{
	add_action("do_pi", ({ "pi" }));
	::init();
}

int do_pi()
{
	object me = this_player(),ob;
	object gangfu=present("gang fu",me);
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");
	if(gangfu&&gangfu->query("equipped"))
	{
		ob= new("/d/city/obj/bamboo");
		message_vision("$N大喝一声，一斧劈下了一根$n。\n", me,ob);
		me->add_busy(random(2));
		ob->move(me);
	}
	else
	{
		message_vision("$N奋力用手向竹子劈去。\n", me);
		if((int)me->query("qi")<100)
		{
			message_vision("竹子猛烈反弹，直接打在$N的脑门上。\n", me);
			me->unconcious();
		}
		else
		{
			ob= new("/d/city/obj/bamboo");
			message_vision("$N潇洒地收掌，捡起一根$n，其实手掌疼痛难忍。\n", me,ob);
			me->add("qi",-100);
			me->add_busy(random(3));
			ob->move(me);
		}
	}
	return 1;
}

