#include <ansi.h>
inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(BLU"蓝色药花"NOR, ({"lanse yaohua", "yaohua"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵蓝色药花。\n");
		set("value", 10000);
	}
set("make/drug",1);
	setup();
}

 
int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	     message_vision(HIG "$N吃下一棵蓝色药花!\n" NOR, me);
        me->add("qi", me->query("int")/2);
       me->start_busy(3);
       destruct(this_object());
	return 1;
}
