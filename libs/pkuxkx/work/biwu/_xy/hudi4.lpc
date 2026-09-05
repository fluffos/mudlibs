// Room: /clone/misc/hudi4.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
#include <ansi.h>
inherit "/biwu/biwuroom1";

void create()
{
	set("short", "湖底");
	set("long", @LONG
湖底潜流冲击，你几乎站立不稳，很难控制游的方向。
LONG
	);
	set("exits", ([
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_swim", ({ "swim", "you" }));
	::init();
}

int do_swim(string arg)
{
	object me;
	me = this_player();
	if(me->is_busy())
		{
			return notify_fail("你正忙着呢。\n");
		}
		if (me->query("qi")<8000)
			{
				message_vision("$N气息渐渐不济，前面水流更加湍急。\n", me);
				me->set_temp("last_damage_from", "$N被湖底潜流冲击，连续口吐淤血而死。",me);
				me->add_busy(random(2));
				me->receive_wound("qi", 500+random(50));
				return 1;
			}
		if (me->query_skill("dodge",1) < 400)
			{
				message_vision(HIR"$N轻功太差，在湖底站立不稳，重重撞在湖底岩石上。\n"NOR, me);
				me->set_temp("last_damage_from", "$N被湖底潜流冲击，连续口吐淤血而死。",me);
				me->add_busy(random(2));
				me->receive_wound("qi", 500+random(50));
				return 1;
			}
		else
			{
				message_vision("$N向西面游了过去。\n", me);
				me->move(__DIR__"hudi5");
				me->add_busy(random(2));
				tell_room(environment(me), me->name() + "从东面游了过来。\n", ({ me }));
			}
		return 1;
}