inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	}
void create()
{
	set_name(HIR"火龙丹"NOR, ({"huolong dan", "dan"}));
	set("unit", "颗");
	set("long", "这是一颗火龙修炼以久的内丹。\n");
    set("value", 5000);
    set("no_sell",1);
    set("sell_in_playershop",1);
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	//if(arg=="dan")
	{
                me->add("max_neili",20);
                		
                message_vision(HIR"$N吃下一颗火龙丹，只觉一股火热之气直冲丹田，丹田内力源源而生!\n"NOR,me);

		//吃丹最多吃到超过最大值20%
		if ((int)me->query("max_neili") > (12*(int)me->query_max_neili()/10) ) 
			me->set("max_neili", (12*(int)me->query_max_neili()/10));
		
		destruct(this_object());
	}
	return 1;
}
