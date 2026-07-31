// jiu.c
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIC "玄冰碧火酒" NOR, ({"xuanbingbihuo jiu", "jiu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "壶");
		set("long", "这是一壶珍贵之极的玄冰碧火酒, 据说能解百毒。\n");
		set("only_do_effect", 1);
		set("do_drink", 1);
	}

	setup();
}

int do_effect(object me)
{
	message_vision("$N一扬脖，将玄冰碧火酒一下子就倒入了口中。\n", me);

	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", me->query("max_jing"));
	tell_object(me, HIC "你只觉一股清香沁入心肺，真是神意清爽！"NOR"\n");
	destruct(this_object());
	return 1;
}
