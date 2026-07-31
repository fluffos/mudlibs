// renshenguo.c
#include <ansi.h>

inherit ITEM;

void init()
{
	if (find_call_out("destguo") != -1)
		return;

	call_out("destguo", 10);
}

void destguo()
{
	tell_room("人参果慢慢渗出水来，一会就腐烂掉了。\n", environment());
	destruct(this_object());
}

void create()
{
	set_name(HIR "人参果" NOR, ({"guo", "renshen guo"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "朵");
		set("long", "这是一只人参果, 已经成型, 真的象极了三周不满的小孩。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	me->improve_neili(10);

	me->set("neili", me->query("max_neili"));
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", me->query("eff_qi"));
	message_vision("$N吃下一枚人参果，只觉得精神健旺，真"
		       "力源源滋生，甚至不再感到饥饿干渴！\n",me);

	destruct(this_object());
	return 1;
}
