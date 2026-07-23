inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIR"朱"NOR"睛"HIC"冰"NOR"蟾"NOR, ({"chan"}));
	set("unit", "只");
	set("value", 300000);
	set("long", "这是一千年难得一见的朱睛冰蟾, 通体透明,
惟眼呈赤色, 能解百毒。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	if (me->is_fighting() )
		return notify_fail("打架时吃，不要找死了!!\n");

	if(arg=="chan") 
	{
message_vision(HIG"$N吃下一只朱睛冰蟾，只觉一股清香沁入心肺，顿时灵台一片空明，神意清爽！\n" NOR, me);
		if (me->query_condition("drunk"))
			me->apply_condition("drunk",0);
		if (me->query_condition("flower_poison"))
			me->apply_condition("flower_poison",0);
		if (me->query_condition("ice_poison"))
			me->apply_condition("ice_poison",0);
		if (me->query_condition("iceshock"))
			me->apply_condition("iceshock",0);
		if (me->query_condition("rose_poison"))
			me->apply_condition("rose_poison",0);
		if (me->query_condition("sanxiao_poison"))
			me->apply_condition("sanxiao_poison",0);
		if (me->query_condition("scorpion_poison"))
			me->apply_condition("scorpion_poison",0);
		if (me->query_condition("slumber_drug"))
			me->apply_condition("slumber_drug",0);
		if (me->query_condition("snake_poison"))
			me->apply_condition("snake_poison",0);
		if (me->query_condition("ss_poison"))
			me->apply_condition("ss_poison",0);
		if (me->query_condition("xx_poison"))
			me->apply_condition("xx_poison",0);
		if (me->query_condition("zhua_poison"))
			me->apply_condition("zhua_poison",0);
        if (me->query_condition("snake_poison"))
        {          me->clear_condition("snake_poison");}
        if (me->query_condition("wugong_poison"))
        {          me->clear_condition("wugong_poison");}
        if (me->query_condition("zhizhu_poison"))
        {          me->clear_condition("zhizhu_poison");}
        if (me->query_condition("xiezi_poison"))
        {          me->clear_condition("xiezi_poison");}
        if (me->query_condition("chanchu_poison"))
        {          me->clear_condition("chanchu_poison");}
        if (me->query_condition("qishang_poison"))
        {          me->clear_condition("qishang_poison");}
        if (me->query_condition("jy-poison"))
        {          me->clear_condition("jy-poison");}
        if (me->query_condition("xx_poison"))
        {          me->clear_condition("xx_poison");}
        if (me->query_condition("cold_poison"))
        {          me->clear_condition("cold_poison");}
        if (me->query_condition("flower_poison"))
        {          me->clear_condition("flower_poison");}
        if (me->query_condition("chilian_poison"))
        {          me->clear_condition("chilian_poison");}
        if (me->query_condition("yufeng_poison"))
        {          me->clear_condition("yufeng_poison");}
        if (me->query_condition("anqi_poison"))
        {          me->clear_condition("anqi_poison");}
       if (me->query_condition("yf_poison"))
        {          me->clear_condition("yf_poison");}
       if (me->query_condition("nx_poison"))
        {          me->clear_condition("nx_poison");}
       if (me->query_condition("x2_poison"))
        {          me->clear_condition("x2_poison");}
       if (me->query_condition("sanpoison"))
        {          me->clear_condition("sanpoison");}
       if (me->query_condition("insect_poison"))
        {          me->clear_condition("insect_poison");}

}
	me->start_busy(3);
		destruct(this_object());
	return 1;
}
