// xiongdan.c
inherit ITEM;

#include <ansi.h>

void init()
{
	if (find_call_out("destdan") != -1)
		return;

	call_out("destdan", 10);
}

void destdan()
{
	object ob;
	message_vision("$N慢慢被风吹着，一会就不再新鲜了。\n", this_object());
	ob = new(__DIR__"xiongdan1");
	ob->move(environment());
	destruct(this_object());
}

void create()
{
	set_name(HIG "新鲜熊胆" NOR, ({"dan", "xiong dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("long", "这是一副新鲜熊胆，热气腾腾的，十分诱人。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	me->improve_neili(2);

	me->set("neili", me->query("max_neili"));
	me->set("qi", me->query("eff_qi"));
	message_vision("$N吃下一副新鲜熊胆，只觉得精"
		       "神健旺，体内真力源源滋生，气血充盈。\n",me);
	destruct(this_object());
	return 1;
}
