// duwan.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_weight(50);
	set_name(RED "毒丸" NOR, ({"du wan", "poison", "wan", "duwan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一粒由毒虫毒液精制而成的毒药，要是你想不开了，可以尝尝！\n");
		set("value", 50);
		set("poison_type", "poison");
		set("can_pour", 1);
		set("can_daub", 1);
		set("can_drug", 1);
		set("poison", ([
			"level" : 200,
			"id"    : "丁春秋",
			"name"  : "毒",
			"duration": 15,
		]));
		set("no_sell", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision("$N一仰脖，把毒药全部倒入了嘴中。\n",
		       me);
	me->set_temp("die_reason", "吃了毒药去见黑白无常了");
	me->die();
	destruct(this_object());
	return 1;
}
