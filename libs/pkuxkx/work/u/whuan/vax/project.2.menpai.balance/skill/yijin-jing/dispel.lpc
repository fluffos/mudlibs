// dispel.c 来自蛤蟆功 qudu.c
// dewolf 2005

#include <ansi.h>

int exert(object me, object target)
{
          int con1, con2, con3, con4, a, b, c, d;
	   // 其他毒性、发疯、走火等待加入
	con1 = me->query_condition("snake_poison");//蛇毒
	con2 = me->query_condition("san_poison");//断肠散
	con3 = me->query_condition("xx_poison");//星宿掌毒

	if( me->is_fighting() )
		return notify_fail("战斗中无法定心运功驱毒？\n");

	if( (int)me->query("neili") < 600 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 4 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的易筋经神功修为还不够。\n");

       a=(int)me->query_skill("yijin-jing", 1);
       b=(int)me->query_skill("poison", 1) ;
       c=(int)(a/20+b/10)+1;

	if (con1 > 0) 
	{
		if (con1 < c)
		{
                         me->clear_condition("snake_poison");
			write( HIW "你运功把蛇毒驱除干净了。\n" NOR);
		}
		else
		{
			me->apply_condition("snake_poison", con1 - c);
			write( HIW "你全身放松，坐下来开始运功驱除蛇毒。\n" NOR);
		}
             d = 0 ;
		message("vision", 
	HIY+me->name()+"吐出一口金灿灿的瘀血，一滴滴黑血从伤口慢慢渗出。\n" NOR,
		environment(me), me);
	}
	else
	if (con2 > 0)
	{
		if ((int)me->query_skill("hamagong", 1) < 30)
			return notify_fail("你的蛤蟆功修为还不够。\n");

		if (con2 < c)
		{
                         me->clear_condition("s_poison");
			write( HIW "你运功把断肠散毒驱除干净了。\n" NOR);
		}
		else
		{
			me->apply_condition("s_poison", con2 - c);
			write( HIW "你全身放松，坐下来开始运功驱除断肠散毒。\n" NOR);
		}
              d = 30;
		message("vision", 
	HIY+me->name()+"吐出一口瘀血，苍白的脸上多了点血色。\n" NOR,
		environment(me), me);
	}
	else
	if (con3 > 0)
	{
		if ((int)me->query_skill("hamagong", 1) < 50)
			return notify_fail("你的蛤蟆功修为还不够。\n");
		if (con3 < c)
		{
                         me->clear_condition("xx_poison");
			write( HIW "你运功把星宿掌毒驱除干净了。\n" NOR);
		}
		else
		{
			me->apply_condition("xx_poison", con3 - c);
			write( HIW "你全身放松，坐下来开始运功驱除星宿掌毒。\n" NOR);
		}
              d = 50;
		message("vision", 
	HIY+me->name()+"吐出一口紫血，苍白的脸上多了点血色。\n" NOR,
		environment(me), me);
	}
	else write( HIW "你好象没中毒，或者是中了一种你无法驱除的毒。\n" NOR);

	me->add("neili", -50-d);
	me->set("jiali", 0);
	me->start_busy(4);

	return 2;
}
