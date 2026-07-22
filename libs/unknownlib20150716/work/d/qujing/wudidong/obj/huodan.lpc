#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name( HIC "潜龙丹" NOR , ({"dan"}));
	set_weight(90);
        set("no_get", "你手里一松，潜龙丹从指间滑落！\n");
        set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
	set("no_give", "这么宝贵的丹药，你自己留着吧！\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "一颗血红色的丹丸，略微能闻到些许香气。\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if( !arg || !id(arg) )
		return 0;
	me->add("potential", 100+random(500));
        message_vision(HIC "$N轻轻掰开一颗潜龙丹送入嘴中，一时间香气四溢。\n" NOR, me);
	destruct(this_object());
	return 1;
}
