// Room: /clone/misc/hudi.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
// edit: by Zine aug 28 1010
#include <ansi.h>
inherit "/biwu/biwuroom1";

void create()
{
	set("short", "湖底");
	set("long", @LONG
湖底潜流冲击，你几乎站立不稳，很难控制游的方向。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"out" : __DIR__"lakeside2",
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
	if (me->query_temp("lakepass"))
		{
			message_vision("$N按照襄阳地形图里的记载，很容易分辨方向，游向湖边。\n", me);
			me->add_busy(random(2));
			me->move(__DIR__"lakeside");
			return 1;
		}
	else if (me->query("qi")<5000)
		{
			message_vision("$N气血翻腾，再也无法闭气，还是赶紧上岸为妙。\n", me);
			me->set_temp("last_damage_from", "被湖底潜流冲击，口吐淤血而死。",me);
			me->add_busy(random(2));
			me->receive_wound("qi", 200+random(50));
			return 1;
		}
	else if (me->query_skill("dodge",1) < 200)
		{
			message_vision(HIR"$N轻功太差，在湖底站立不稳，跌了一个四仰八叉。\n"NOR, me);
			me->set_temp("last_damage_from", "被湖底潜流冲击，口吐淤血而死。",me);
			me->add_busy(random(2));
			me->receive_wound("qi", 200+random(50));
			return 1;
		}
		else
		{
			message_vision("$N向西面游了过去。\n", me);
			me->move(__DIR__"hudi2");
			me->add_busy(random(2));
			tell_room(environment(me), me->name() + "从东面游了过来。\n", me);
			return 1;
	    }
 }