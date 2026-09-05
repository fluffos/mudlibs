// heal.c
//dingdang
#include <ansi.h>
int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");
         if ((int)me->query_skill("jiuyin-shengong", 1) < 120)
		return notify_fail("你的九阴神功修为还不够。\n");
	if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50 )
		return notify_fail("你的真气不够。\n");
//九阴真经里的疗伤应该是很强的,记得当年洪七公被西毒打的几乎丧命,就是用九阴真经里的疗伤篇
//得以复原,所以我在这里去掉受上过重的判断,但是增加疗伤所需九阴神功的等级
// modified by male
//        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
//                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
        write( HIR "你全身放松，坐下来开始用九阴神功疗伤。\n" NOR);
	message("exert",
		HIW + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,
		environment(me), me);
        me->receive_curing("qi", 20 + (int)me->query_skill("force")/5+(int)me->query_skill("jiuyin-shengong",1)/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
	return 1;
}
