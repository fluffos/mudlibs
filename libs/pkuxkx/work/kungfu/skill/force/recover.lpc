// recover.c

//inherit SSERVER;

int exert(object me, object target)
{
	int n, q, recv_qi, recv_coef,cd;
	string force;

	if (me != target)
		return notify_fail("你只能用内功调匀自己的气息。\n");

  force=me->query_skill_mapped("force");
  if (me->query_skill("force") < 1 || !stringp(force) )
    return notify_fail("你得先学习内功才能用内功调匀自己的气息。\n");
	
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够。\n");

	q = (int)me->query("eff_qi") - (int)me->query("qi");
	cd = SKILL_D(force)->force_character("TYPE_REC_CD");
	if ( !cd )
		cd=6;
 
	if (q < 10)
		return notify_fail("你现在气力充沛。\n");
	
	if ( me->query_temp("neili_speedup") )
		return notify_fail("你正在运行真气加速气血恢复，无法再分出内力来。\n");
	
	if ( time()-me->query_temp("recover_time")<= cd )
		return notify_fail("你上一次恢复气血，全身真气还没有平缓，请过一会儿再运行真气吧。\n");
		
    // n = 100 * q / me->query_skill("force");
  n = (100-me->query_temp("forceextra")*me->query("drugbath/continue")*10) * q / me->query_skill("force"); //by Zine 恢复加成for mutong quest

	if (n < 20)
		n = 20;
	
	if ( !me->is_fighting() )
	{
  	if ((int)me->query("neili") < n) {
	  	q = q * (int)me->query("neili")/n ;
		  n = (int)me->query("neili");
	  }

	  me->add("neili", -n);
	  me->receive_heal("qi", q);
	}
	else 
	{
		recv_coef=SKILL_D(force)->force_character("TYPE_RECOVER");
		if ( !recv_coef )
			recv_coef=100;
		recv_qi=me->query("max_neili")/10 * me->query("con")/10 * recv_coef/100;
		if ( recv_qi > q )
			recv_qi=q;
		
		if ( recv_qi <=0 )
		  recv_qi=1;
	  
		me->add("neili",-100);
		me->receive_heal("qi", recv_qi);
		me->start_busy(1);
		me->set_temp("recover_time",time());
	}
	
  message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);
	
	return 1;
}
