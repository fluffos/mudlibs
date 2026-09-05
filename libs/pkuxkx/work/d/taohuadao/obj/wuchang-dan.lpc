   // wuchang-dan.c 无常丹

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
      set_name("无常丹",({"wuchang dan","dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
      set("long","这是一颗桃花岛的无常丹，可以助长内力。\n");
		set("value", 10000);
		set("no_drop", "这样东西不能离开你。\n");
	}

     set("taohuadao",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
         {
	return notify_fail("你要吃什么？\n");
        }

	if ( me->query("neili") >= me->query("max_neili")*2 )
        {
      return notify_fail("你现在不需要无常丹。\n");
         }
          else
         {
		me->add("neili", 200);
        message_vision(HIY"$N吃下一颗无常丹，顿觉一股暖流直上丹田，气息舒畅。\n"NOR,me);
        }
   if((int)me->query_condition("taoism_drug") < 100)
        {
      me->apply_condition("taoism_drug",100);
}

	destruct(this_object());
	return 1;
}


