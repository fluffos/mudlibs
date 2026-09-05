// 五毒神功  heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if ((int)me->query_skill("wudu-shengong", 1) < 30)
		return notify_fail("你的五毒神功修为还不够。\n");
	if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	write( BLU+ "你调息凝精，默运内功开始运功疗伤。\n" NOR);
	message("vision",
		BLU + me->name() + "盘腿坐下，周身萦绕着一股淡蓝色的雾气。\n"+
		"过了一会，雾气消去，"+ me->name() +"看起来脸色好多了。\n" NOR,
		environment(me), me);

	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
      me->start_busy(2);

	return 1;
}
