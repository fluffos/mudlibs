#include <ansi.h>
inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name("解药", ({"jie yao", "jieyao", }));   
	set("no_drop",1);
	set("no_get",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗药丸。\n");
		set("value", 10000);     
                        set("medicine", "drug");
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	me->set("jingli", 0);
	me->set("jing", 0);
	me->set("neili", 0);
	message_vision(HIR "$N吃下一颗不知名字的药丸，只觉得头重脚轻，摇摇欲倒！\n" NOR, me);
	destruct(this_object());
	return 1;
}
