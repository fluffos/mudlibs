// xiongshe.c
// 精气 max

#include <ansi.h>
#include "medicine.h"

void create()
{
	set_name(HIG "九转熊蛇丸" NOR, ({ "xiongshe wan", "wan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一颗淡绿的的药丸，用熊胆蛇胆等珍稀药材精制而成。\n");
		set("base_unit", "颗");
		set("base_value", 100000);
		set("no_sell", 1);
		set("base_weight", 100);
		set("only_do_effect", 1);
		set("mixture", ([
			"herb" : ([ "tianqi"   : 1,
				    "xuelian"  : 1,
				    "lurong"   : 1,
				    "honghua"  : 1,
				    "zzfen"    : 1,
				    "heshouwu" : 1,
				    "renshen"  : 1,
				    "dangui"   : 1,
				    "xiongdan" : 3,
				    "shedan"   : 2, ]),
			"neili" : 300,
			"jing"  : 50,
			"time"  : 5,
			"min_level"     : 150,
			"xiaoyao-qixue" : 250,
		]));
	}
	setup();
}

int do_effect(object me)
{
	mapping my;

	if (time() - me->query_temp("last_eat/xiongshe") < 120)
	{
		write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
		return 1;
	}

	me->set_temp("last_eat/xiongshe", time());

	message_vision(HIM "$N" HIG "吃下一粒" + name() +
		       HIM "，两眼直冒紫光！\n", me);
	tell_object(me, HIG "不一会儿你只觉得精神饱满，神气完足，内力充沛之极。"NOR"\n");

	log_file("static/using", sprintf("%s(%s) eat 九转熊蛇丸 at %s.\n",
			me->name(1), me->query("id"), ctime(time())));

	my = me->query_entire_dbase();
	my["eff_jing"] = my["max_jing"];
	my["jing"] = my["max_jing"];
	my["eff_qi"] = my["max_qi"];
	my["qi"] = my["max_qi"];
	if (my["jingli"] < my["max_jingli"])
		my["jingli"] = my["max_jingli"];
	if (my["neili"] < my["max_neili"])
		my["neili"] = my["max_neili"];

	me->start_busy(3);

	add_amount(-1);
	if (query_amount() < 1)
		destruct(this_object());

	return 1;
}

