// Room: /clone/misc/tree2.c
// create by zine aug 26 2010
inherit "/biwu/biwuroom1";
#include <ansi.h>

void create()
{
	set("short", "大树上");
	set("long", @LONG
这是一棵大约年龄超过千岁的古树，枝叶向四面八方伸展开去，繁密异常，
一条大蟒蛇缠在树枝上，被你惊醒后，似乎很暴躁。
LONG
	);
	set("exits", ([ 
	]));
	set("objects", ([ 
       ("/biwu/xy/npc/jumang") : 1,
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
			message_vision(HIW"$N抓紧树枝荡了过去，突然间，你支持不住你放开树枝，坠了下去。\n"NOR, me);
			message_vision(HIR"你似乎回到了刚才的地方，巨蟒疑惑地看着你。\n"NOR, me);
			me->add_busy(random(2));
			return 1;
		}
}
