// tree.c
// edit: by zine Aug 21 2010
#include <ansi.h>
inherit "/biwu/biwuroom1";

void create()
{
	set("short", "大树上");
	set("long", @LONG
这是一棵大约年龄超过千岁的古树，枝叶向四面八方伸展开去，繁密异常，
你视线被枝叶所挡，根本不辨东西，你可以从树枝上荡(swing)过去。
LONG
	);
	set("exits", ([ 
		"down" : __DIR__"estreet2",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_swing", ({ "swing", "dang" }));
	::init();
}

int do_swing(string arg)
{
	object me;
	me = this_player();
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
	if (random(10)>8) 
		{
			message_vision(HIB"$N抓紧树枝荡了过去，突然间你发现树枝动了动，似乎是活的。\n"NOR, me);
			message_vision("$N被什么东西狠狠地咬了一口。\n", me);
			me->set_temp("last_damage_from", "$N惊恐地发现，所谓的树枝是一条黑色的大蟒蛇。");
			me->receive_wound("qi", 2500+random(50));
			me->add_busy(random(2));
			me->move(__DIR__"tree2");
			return 1;
		}
	else 
		{
			if (random(10)>7)
				{
					message_vision(HIG"$N抓紧树枝荡了过去，下面是一片草地，你放开树枝，坠了下去。\n"NOR, me);
					me->set_temp("last_damage_from", "$N一屁股跌倒在草地上，幸好草地很软，没有受到严重伤害。");
					me->receive_wound("qi", random(50));
					me->move(__DIR__"grass");
					me->add_busy(random(2));
					tell_room(environment(me), me->name() + "从天上掉了下来。\n", ({ me }));
					return 1;
				}
			else
				{
					message_vision(HIR"$N抓紧树枝荡了过去，突然间，你支持不住你放开树枝，坠了下去。\n"NOR, me);
					message_vision(HIW"你似乎回到了刚才的地方。\n"NOR, me);
					me->add_busy(random(2));
					return 1;
				}
		}
}
