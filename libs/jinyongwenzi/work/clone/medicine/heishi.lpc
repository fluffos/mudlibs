//Modify by Looklove@SJ 2000/10/06

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("玉洞黑石丹", ({"heishi dan", "dan","heishi"}));
   	if (clonep())
      		set_default_object(__FILE__);
   	else {
      	set("unit", "包");
      	set("long","这是一包崆峒派的解毒灵药。\n");
      	set("value", 5000);
   	}
   	setup();
}

int init()
{
   	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

   	if(!id(arg))
       		return notify_fail("你要吃什么？\n");

   	message_vision("$N吃下一包" + name() + "。\n", me);
   	if ((int)me->query_condition("hb_poison") < 5) {
      		me->apply_condition("hb_poison", 1);
   	}
	else {
		me->apply_condition("hb_poison", -5);
	}
   	destruct(this_object());
   	return 1;
}
