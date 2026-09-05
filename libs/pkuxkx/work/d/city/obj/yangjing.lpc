#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
   set_name("养精丹", ({"yangjing dan", "dan"}));
  set_weight(10);
   if (clonep())
      set_default_object(__FILE__);
   else {
		set("unit", "瓶");
		set("base_unit", "粒");
		set("base_weight", 10);
      set("long", "这是一包武林人士必备的养精丹。\n");
      set("value", 1500);
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
   this_player()->receive_curing("jing", 200);
		this_object()->add_amount(-1);
   return 1;
}

