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

	if ((int)me->query_skill("biyun-xinfa", 1) < 150)
		return notify_fail("你的碧云心法修为还不够。\n");



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
       else 	return notify_fail("你身上没有什么本门内功能解的毒!\n");
	write( HIB "你运起唐门的碧云心法，吐出了一口碧色的血夜!!解开了身上的毒！!\n" NOR);
		message("vision", 
	HIB+me->name()+"吐出了一口碧色的血夜!!\n" NOR,
		environment(me), me);

	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(2);

	return 1;
}
