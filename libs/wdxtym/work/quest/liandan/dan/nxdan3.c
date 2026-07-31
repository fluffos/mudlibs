//Cracked by Kafei
// baodan.c 豹子胆
// sdong 08/06/98

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
		  set_name("豹子胆", ({ "baozi dan", "dan" }) );
		  set_weight(1000);
		  if( clonep() )
					 set_default_object(__FILE__);
		  else {
					 set("unit", "颗");
					 set("long", CYN"这是一颗象拳头一样大的豹子胆，又黑又绿。\n"NOR);
					 set("value", 10000);
					 set("medicine", 1);
		  }
		  setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");

		  me->add("food", 50);


		  if ( (int)me->query_condition("medicine") > 0 ){
					 me->add("max_jingli", -1);
					 me->add("eff_jingli", -1);
					 me->set("jingli", 0);
					 me->apply_condition("medicine", 30);
					 message_vision(HIR "$N吃下一颗豹子胆，只觉得肝肠寸断，五脏欲裂，原来服食太多药物，药效适得其反！\n" NOR, this_player());
					 call_out("destroy", 0);
					 return 1;
		  }

		  if( !me->query_temp("qz/baozidan") ) {
					 me->add_temp("apply/attack", 100);
					 me->set_temp("qz/baozidan", 1);
					 if(random(2))me->set("max_jingli",me->query("max_jingli",1)+2);
		  }

		  me->add("neili", 500);
		  me->add("jingli", 300);
		  me->apply_condition("medicine",
		  me->query_condition("medicine")+30);
		  message_vision(HIY "$N吞下一颗豹子胆，只觉得全身充满热气，斗志昂扬，混身有劲。\n" NOR, me);

		  remove_call_out("destroy");
		  call_out("destroy", 0);
		  return 1;
}

void destroy()
{
		  if(this_object())
			  destruct(this_object());
}

