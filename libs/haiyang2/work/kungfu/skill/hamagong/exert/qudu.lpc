// qudu.c

#include <ansi.h>

int exert(object me, object target)
{
	int con1, con2, con3;
	con1 = me->query_condition("snake_poison");
	con2 = me->query_condition("scorpion_poison");
	con3 = me->query_condition("xx_poison");

	if( me->is_fighting() )
		return notify_fail("战斗中运功驱毒？找死吗？\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功修为还不够。\n");

	if (con1 > 0) 
	{
		if (con1 < 3)
		{
			me->apply_condition("snake_poison", 0);
			write( HIW "你运功把蛇毒驱除干净了。\n" NOR);
		}
		else
		{
			me->apply_condition("snake_poison", con1 - 4);
			write( HIW "你全身放松，坐下来开始运功驱除蛇毒。\n" NOR);
		}
		message("vision", 
	HIY+me->name()+"吐出一口金灿灿的瘀血，一滴滴黑血从伤口慢慢渗出。\n" NOR,
		environment(me), me);
	}
	else
	if (con2 > 0)
	{
		if (con2 < 3)
		{
			me->apply_condition("scorpion_poison", 0);
			write( HIW "你运功把蝎毒驱除干净了。\n" NOR);
		}
		else
		{
			me->apply_condition("scorpion_poison", con2 - 4);
			write( HIW "你全身放松，坐下来开始运功驱除蝎毒。\n" NOR);
		}
		message("vision", 
	HIY+me->name()+"吐出一口金灿灿的瘀血，一滴滴青紫血珠从伤口慢慢渗出。\n" NOR,
		environment(me), me);
	}
	else
	if (con3 > 0)
	{
		if ((int)me->query_skill("hamagong", 1) < 30)
			return notify_fail("你的蛤蟆功修为还不够。\n");
		if (con3 < 3)
		{
			me->apply_condition("xx_poison", 0);
			write( HIW "你运功把星宿掌毒驱除干净了。\n" NOR);
		}
		else
		{
			me->apply_condition("xx_poison", con3 - 4);
			write( HIW "你全身放松，坐下来开始运功驱除星宿掌毒。\n" NOR);
		}
		message("vision", 
	HIY+me->name()+"吐出一口紫血，苍白的脸上多了点血色。\n" NOR,
		environment(me), me);
	}
	else write( HIW "你好象没中毒吧。\n" NOR);

	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(4);

	return 1;
}
