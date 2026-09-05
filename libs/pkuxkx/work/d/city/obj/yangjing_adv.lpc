#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name("上等养精丹", ({"shangdeng yangjingdan", "dan"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "瓶");
		set("base_unit", "粒");
		set("base_weight", 20);
		set("long", "这是一包武林人士必备的养精丹。\n");
		set("value", 15000);
	}
	set_amount(1);
   setup();
}

int init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
	return 0;

   message_vision("$N吃下一粒" + name() + "。\n", me);
   this_player()->receive_curing("jing", 2000);
		this_object()->add_amount(-1);
   return 1;
}

