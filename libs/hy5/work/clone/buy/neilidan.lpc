// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "内力丹" NOR, ({ "neili wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的内力丹，据说吃了可以加内力。\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;
int max;
        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
// max = me->query_skill("force")*10 + me->query("combat_exp")/1000;
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
                tell_object(me, HIR "你觉得似乎自己充满了内力。\n" NOR);
                me->add("max_neili", 200);
        destruct(this_object());
	return 1;
}
