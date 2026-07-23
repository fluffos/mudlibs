// qudu.c

#include <ansi.h>

int exert(object me, object target)
{
	int con1, con2, con3;

	if( me->is_fighting() )
		return notify_fail("战斗中运功驱毒？找死吗？\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	if ((int)me->query_skill("biyun-xinfa", 1) < 250)
		return notify_fail("你的碧云心法修为还不够。\n");

if (!userp(target))
	return notify_fail("对方不接受你的医疗。\n");

if (!userp(me))
	return notify_fail("对方不接受你的医疗。\n");

		if (target->query_condition("scorpion_poison"))
        target->clear_condition("scorpion_poison");
		if (target->query_condition("ss_poison"))
        target->clear_condition("ss_poison");
		if (target->query_condition("tmzhuihun_poison"))
	target->clear_condition("tmzhuihun_poison");
		if (target->query_condition("tmpili_poison"))
        target->clear_condition("tmpili_poison");
		if (target->query_condition("zm_poison"))
        target->clear_condition("zm_poison");
		if (target->query_condition("drunk"))
			target->clear_condition("drunk");
		if (target->query_condition("flower_poison"))
			target->clear_condition("flower_poison");
		if (target->query_condition("ice_poison"))
			target->clear_condition("ice_poison");
		if (target->query_condition("iceshock"))
			target->clear_condition("iceshock");
		if (target->query_condition("rose_poison"))
			target->clear_condition("rose_poison");
		if (target->query_condition("sanxiao_poison"))
			target->clear_condition("sanxiao_poison");
		if (target->query_condition("scorpion_poison"))
			target->clear_condition("scorpion_poison");
		if (target->query_condition("slumber_drug"))
			target->clear_condition("slumber_drug");
		if (target->query_condition("snake_poison"))
			target->clear_condition("snake_poison");
		if (target->query_condition("ss_poison"))
			target->clear_condition("ss_poison");
		if (target->query_condition("xx_poison"))
			target->clear_condition("xx_poison");
		if (target->query_condition("zhua_poison"))
			target->clear_condition("zhua_poison");
        if (target->query_condition("snake_poison"))
        {          target->clear_condition("snake_poison");}
        if (target->query_condition("wugong_poison"))
        {          target->clear_condition("wugong_poison");}
        if (target->query_condition("zhizhu_poison"))
        {          target->clear_condition("zhizhu_poison");}
        if (target->query_condition("xiezi_poison"))
        {          target->clear_condition("xiezi_poison");}
        if (target->query_condition("chanchu_poison"))
        {          target->clear_condition("chanchu_poison");}
        if (target->query_condition("qishang_poison"))
        {          target->clear_condition("qishang_poison");}
        if (target->query_condition("jy-poison"))
        {          target->clear_condition("jy-poison");}
        if (target->query_condition("xx_poison"))
        {          target->clear_condition("xx_poison");}
        if (target->query_condition("cold_poison"))
        {          target->clear_condition("cold_poison");}
        if (target->query_condition("flower_poison"))
        {          target->clear_condition("flower_poison");}
        if (target->query_condition("chilian_poison"))
        {          target->clear_condition("chilian_poison");}
        if (target->query_condition("yufeng_poison"))
        {          target->clear_condition("yufeng_poison");}
        if (target->query_condition("anqi_poison"))
        {          target->clear_condition("anqi_poison");}
       if (target->query_condition("yf_poison"))
        {          target->clear_condition("yf_poison");}
       if (target->query_condition("nx_poison"))
        {          target->clear_condition("nx_poison");}
       if (target->query_condition("x2_poison"))
        {          target->clear_condition("x2_poison");}
       if (target->query_condition("sanpoison"))
        {          target->clear_condition("sanpoison");}
       if (target->query_condition("insect_poison"))
        {          target->clear_condition("insect_poison");}
	if (me->query_condition("zm_poison"))
		me->apply_condition("zm_poison",0);
	else if (me->query_condition("tmpili_poison"))
		me->apply_condition("tmpili_poison",0);
	else if (me->query_condition("tmzhuihun_poison"))
		me->apply_condition("tmzhuihun_poison",0);
        else if (me->query_condition("snake_poison"))
        {          me->clear_condition("snake_poison");}
        else if (me->query_condition("wugong_poison"))
        {          me->clear_condition("wugong_poison");}
        else if (me->query_condition("zhizhu_poison"))
        {          me->clear_condition("zhizhu_poison");}
        else if (me->query_condition("xiezi_poison"))
        {          me->clear_condition("xiezi_poison");}
        else if (me->query_condition("chanchu_poison"))
        {          me->clear_condition("chanchu_poison");}
      if (me=target)
{
		if (target->query_condition("tmqidu_poison"))
			target->clear_condition("tmqidu_poison");
		if (target->query_condition("wuhudu_poison"))
			target->clear_condition("wuhudu_poison");
		if (target->query_condition("fire_poison"))
			target->clear_condition("fire_poison");
		if (target->query_condition("corpse_poison"))
			target->clear_condition("corpse_poison");
		if (target->query_condition("shenlong_poison"))
			target->clear_condition("shenlong_poison");
		if (target->query_condition("xuanming_poison"))
			target->clear_condition("xuanming_poison");
		if (target->query_condition("xuantian_han"))
			target->clear_condition("xuantian_han");
		if (target->query_condition("baituo_poison"))
			target->clear_condition("baituo_poison");
		if (target->query_condition("qx_snake_poison"))
	target->clear_condition("qx_snake_poison");
}      
	write( HIB "你运起唐门的碧云心法，吐出了一口碧色的血夜!!解开了身上的毒！!\n" NOR);
		message("vision", 
	HIB+me->name()+"吐出了一口碧色的血夜!!\n" NOR,
		environment(me), me);

	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(5);

	return 1;
}
