inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	}
void create()
{
	set_name(HIR"千年火龙丹"NOR, ({"qiannian dan", "dan"}));
	set("unit", "颗");
	set("long", "这是一颗千年火龙的内丹。\n");
    set("value", 10000);
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
                me->add("max_neili",30);
                me->add("max_jingli",20);
		
                message_vision(HIR"$N吃下一颗千年火龙丹，只觉一股火热之气直冲丹田，四肢百骸说不出的舒服!\n"NOR,me);
				
		//吃丹最多吃到超过最大值20%
		if ((int)me->query("max_neili") > (12*(int)me->query_max_neili()/10) ) 
			me->set("max_neili", (12*(int)me->query_max_neili()/10));
		
		if ((int)me->query("max_jingli") > (12*(int)me->query_max_jingli()/10) ) 
			me->set("max_jingli", (12*(int)me->query_max_jingli()/10));

		destruct(this_object());
	}
	return 1;
}
