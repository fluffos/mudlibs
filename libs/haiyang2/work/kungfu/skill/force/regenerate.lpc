// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{
	int j;
	if (target != me) 
		return notify_fail("你只能用内功恢复自己的精力。\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
	
	if ((int)me->query("neili") < 35)
		return notify_fail("你的内力不够。\n");
	j = (int)me->query("eff_jing") - (int)me->query("jing");
	if (j < 10)
		return notify_fail("你现在精气旺盛。\n");

	me->add("neili", -30);
if ((int)me->query("eff_jing") <= (int)me->query("max_jing"))
{
	me->receive_heal("jing", (int)me->query_skill("force") / 2);
}
if ((int)me->query("jing") <= (int)me->query("eff_jing"))
{
	me->add("jing", (int)me->query_skill("force") / 2);	
}        message_combatd("$N深深吸了几口气，精神看起来好多了。\n", me);
//        me->start_busy(1);

        if( me->is_fighting() ) me->start_busy(2);
	
	return 1;
}

