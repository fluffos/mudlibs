// shedu.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_weight(50);
	set_name(HIG "蛇毒" NOR, ({"she du", "du", "shedu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一粒由蛇毒毒液精制而成的毒药，只要一丁点就可以置人于死地！\n");
		set("value", 50);
		set("poison_type", "poison");
		set("can_pour", 1);
		set("can_daub", 1);
		set("can_drug", 1);
		set("poison", ([
			"level" : 250,
			"id"    : "欧阳峰",
			"name"  : "蛇毒",
			"duration": 20,
		]));
		set("no_sell", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision("$N一仰脖，把毒药全部倒入了嘴中。\n",me);
	me->set_temp("die_reason", "吃了蛇毒暴毙身亡了");
	me->die();
	destruct(this_object());
	return 1;
}

