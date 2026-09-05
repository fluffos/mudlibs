#include <ansi.h>
inherit COMBINED_ITEM;
#include "eat.h"
void create()
{
        set_name(WHT"虎鞭大力丸"NOR, ({"hubian daliwan", "wan"}));
        set_weight(300+random(60));
        set("long", "这是一个虎鞭大力丸，能够让你大力大力更大力。\n");
        set("unit", "粒");
		set("value",1000);
		set_amount(1);
		setup();
}

int do_eat(string arg)
{
	int diff;
	object me=this_player(),ob=this_object();
	if (!can_eat(ob,arg)) return 0;
	if (me->is_busy())
	{
		tell_object(me,"你忙着呢，根本腾不开手。\n");
		return 1;
	}                 
	if (base_name(environment(me))[0..10] == "/d/xiakedao")
	return notify_fail("什么？\n");  
	if (time()-me->query_temp("last_eat_daliwan")<1500)
	{
		tell_object(me,"等等，大力丸不是糖豆，不能连续吃。\n");
		return 1;
	}
	if (me->query_temp("jiali_daliwan"))
	{	
		tell_object(me,"你上次吃的大力丸效果还没有完全发挥完毕呢。\n");
		return 1;
	}
//	me->add("neili", diff*4/5+random(diff/5) );   
	me->set_temp("jiali_daliwan",30);
	me->set_temp("last_eat_daliwan",time());
	message_vision("$N服下一粒$n，精神一振，感觉全身充满了力量。\n", me, this_object());
	if(query_amount()<=1)
	{
		write("你把剩下的"+name()+"都吃完了。\n");
	}
	add_amount(-1);
	call_out("buff_destroy", 1200, me);
	return 1;
}


void buff_destroy(object me)
{
        if ( !me ) return;
		if (me->query_temp("jiali_daliwan"))
		{
			me->delete_temp("jiali_daliwan");
			tell_object(me,"大力丸的药效已经过去，你感觉有点萎靡。\n");

		}

        
        return;
}


