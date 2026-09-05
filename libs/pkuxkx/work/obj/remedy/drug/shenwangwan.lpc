#include <ansi.h>
inherit COMBINED_ITEM;
#include "eat.h"
void create()
{
        set_name(HIG"千年参王丸"NOR, ({"qiannian shenwangwan", "wan"}));
        set_weight(300+random(60));
        set("long", "这是一粒千年参王丸，补充真元有相当帮助。\n");
        set("unit", "粒");
		set("value",120);
		set_amount(1);
		setup();
}

int do_eat(string arg)
{
	object me=this_player(),ob=this_object();
	if (!can_eat(ob,arg)) return 0;
	if (me->is_busy())
	{
		tell_object(me,"你忙着呢，根本腾不开手。\n");
		return 1;
	}                 
	if (base_name(environment(me))[0..10] == "/d/xiakedao")
	return notify_fail("什么？\n");  
	if (time()-me->query_temp("last_eat_renshenwan")<40)
	{
		tell_object(me,"等等，你上次吃的千年参王丸效果还没有完全发挥呢。\n");
		return 1;
	}
	me->set_temp("last_eat_renshenwan",time());   
	if (me->query("neili")<me->query("max_neili")*2-1000)
	me->add("neili", 900+random(100));   
	message_vision("$N服下一粒$n，经脉各处内息充盈多了。\n", me, this_object());
	if(query_amount()<=1)
	{
		write("你把剩下的"+name()+"都吃完了。\n");
	}
	add_amount(-1);
	return 1;
}


