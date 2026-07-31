// dahuan.c
// 气++

#include <ansi.h>
#include "medicine.h"

void create()
{
	set_name(CYN "大还丹" NOR, ({ "dahuan dan", "dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一粒淡青色的药丸，疗伤效果相当不错。\n");
		set("base_unit", "粒");
		set("base_value", 1500);
		set("base_weight", 60);
		set("only_do_effect", 1);
		set("mixture", ([
			"herb" : ([ "chuanwu"  : 1,
				    "honghua"  : 1,
				    "dangui"   : 1,
				    "chenpi"   : 1,
				    "moyao"    : 1,
				    "shengdi"  : 1,
				    "yjhua"    : 1,
				    "heshouwu" : 1, ]),
			"neili" : 80,
			"jing"  : 30,
			"time"  : 3,
			"min_level" : 80,
			"medical" : 100,
		]));
	}
	setup();
}

int do_effect(object me)
{
	mapping my;

	if (time() - me->query_temp("last_eat/dahuan") < 40)
	{
		write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
		return 1;
	}

	my = me->query_entire_dbase();
	if (my["eff_qi"] == my["max_qi"])
	{
		write("你现在并没有受伤，不必服用" + name() + "。\n");
		return 1;
	}

	me->set_temp("last_eat/dahuan", time());

	message_vision(CYN "$N" CYN "小心的服下了" + name() +
		       CYN "，试着运了两口气，脸色看来好多了。"NOR"\n", me);

	me->receive_curing("qi", 350);
	me->receive_heal("qi", 350);

	me->start_busy(1);

	add_amount(-1);
	if (query_amount() < 1)
		destruct(this_object());

	return 1;
}

