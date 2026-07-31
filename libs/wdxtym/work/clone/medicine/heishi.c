// heishi.c

#include <ansi.h>
#include "medicine.h"

void create()
{
	set_name(WHT "玉洞黑石丹" NOR, ({ "heishi dan", "dan" }));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一颗淡灰色的的玉洞黑石丹，药效端的是神妙无比。\n");
		set("base_unit", "颗");
		set("base_value", 80000);
		set("no_sell", 1);
		set("base_weight", 80);
		set("only_do_effect", 1);
		set("mixture", ([
			"herb" : ([ "tianqi"   : 1,
				    "duhuo"    : 1,
				    "hafen"    : 1,
				    "xiongdan" : 1,
				    "heshouwu" : 2,
				    "renshen"  : 2,
				    "zzfen"    : 1,
				    "xuelian"  : 1,
				    "xuejie"   : 1,
				    "renshen"  : 2,
				    "guiwei"   : 1, ]),
			"neili" : 400,
			"jing"  : 60,
			"time"  : 8,
			"min_level" : 150,
			"xiaoyao-qixue" : 200,
		]));
	}
	setup();
}

int do_effect(object me)
{
	mapping my;

	if (time() - me->query_temp("last_eat/heishi") < 180)
	{
		write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
		return 1;
	}

	me->set_temp("last_eat/heishi", time());

	message_vision(HIR "$N" HIR "吞下" + name() + HIR "，脸色泛一阵清气。"NOR"\n", me);
	tell_object(me, HIY "你只觉得真气充沛，几乎就要喷薄而出。"NOR"\n");

	log_file("static/using", sprintf("%s(%s) eat 玉洞黑石丹 at %s.\n",
		 me->name(1), me->query("id"), ctime(time())));

	my = me->query_entire_dbase();
	my["neili"] = my["max_neili"] * 2;

	me->start_busy(3);

	add_amount(-1);
	if (query_amount() < 1)
		destruct(this_object());

	return 1;
}

