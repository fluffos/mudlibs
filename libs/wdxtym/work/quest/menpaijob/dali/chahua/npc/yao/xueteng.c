//Cracked by Kafei
// xueteng.c 大血藤

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}


void create()
{
	set_name( GRN "大血藤" NOR , ({"da xueteng", "xueteng"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵南诏特产的大血藤，看起来是黑乎乎的枯木，但有补血振气的神效。\n");
		set("yaocao",1);
		set("value", 900);
		set("medicine", 1);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if ( (int)me->query_condition("bonze_drug" ) > 0 ){
                me->add("max_neili", -1);
                me->set("neili", 0);
                me->apply_condition("bonze_drug", 30);
        message_vision(HIR "$N吃下一颗大血藤，只觉得肝肠寸断，五脏欲裂，原来服食太多药物，药效适得其反！\n" NOR, this_player());
		destruct(this_object());
        }
	
	me->set("qi", (int)me->query("max_qi"));
	me->add("max_neili", 1);
	me->set("neili", (int)me->query("max_neili"));
	me->apply_condition("bonze_drug", me->query_condition("bonze_drug")+20);
	message_vision(HIY "$N吃下一棵大血藤，顿时血气翻涌血脉膨胀，气力大长。\n" NOR, me);

	destruct(this_object());
	return 1;
}
