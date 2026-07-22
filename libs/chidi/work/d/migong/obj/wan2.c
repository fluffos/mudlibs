inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIG"清心丸"NOR, ({"wan"}));
	set("unit", "颗");
	set("value", 200000);
	set("long", "这是海洋天骄专为眠龙洞秘制的解毒丹。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	if(arg=="wan") 
	{
message_vision(HIG"$N服下一颗清心丸，只觉一股清香沁入心肺，顿时灵台一片空明，神意清爽！\n" NOR, me);
		if (me->query_condition("xiezi"))
		me->apply_condition("xiezi",0);
		if (me->query_condition("flower_poison"))
			me->apply_condition("flower_poison",0);
		if (me->query_condition("ice_poison"))
			me->apply_condition("ice_poison",0);
		if (me->query_condition("iceshock"))
			me->apply_condition("iceshock",0);
		if (me->query_condition("chanchu_poison"))
			me->apply_condition("chanchu_poison",0);
		if (me->query_condition("sanxiao_poison"))
			me->apply_condition("sanxiao_poison",0);
		if (me->query_condition("scorpion_poison"))
			me->apply_condition("scorpion_poison",0);
		if (me->query_condition("dragon_drug"))
			me->apply_condition("dragon_drug",0);
		if (me->query_condition("snake_poison"))
			me->apply_condition("snake_poison",0);
		if (me->query_condition("wugong_poison"))
			me->apply_condition("wugong_poison",0);
		if (me->query_condition("zhizhu_poison"))
			me->apply_condition("zhizhu_poison",0);
		if (me->query_condition("zhua_poison"))
			me->apply_condition("zhua_poison",0);
		destruct(this_object());
	}
	me->start_busy(2);
	return 1;
}
