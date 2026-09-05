// baoming-dan.c 天王保命丹

#include <ansi.h>

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{

     set_name("天王保命丹",({"baoming dan","dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
     set("unit","粒");
     set("long","这是一粒极具灵效的天王保命丹，专治内外伤。\n");
		set("value", 2000);
		set("no_drop", "这样东西不能离开你。\n");
	}

       set("taohuadao",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg)) return notify_fail("你要吃什么？\n");

	if (me->query("eff_qi") == me->query("max_qi"))
      return notify_fail("你现在不需要天王保命丹。\n");
      else
	{
    this_player()->receive_curing("qi",100);
     this_player()->add("qi",100);
    message_vision("$N吃下一粒天王保命丹，气色好多了.\n",this_player());
   destruct(this_object());
      return 1;
	}


}

