// yao2.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC "»Ø´ºÍè" NOR, ({"huichun wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Á£");
		set("value", 2000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision("$N³ÔÏÂÒ»Á£" + name() + "¡£\n", me);

	me->receive_curing("jing", (int)me->query("max_jing") / 40);
	destruct(this_object());
	return 1;
}
