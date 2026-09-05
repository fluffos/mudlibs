// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{	
	int diff,neilineed,cd,recv_jing, recv_coef;
	string force;
	
	if (target != me) 
		return notify_fail("你只能用内功恢复自己的精力。\n");
	
  force=me->query_skill_mapped("force");
  if (me->query_skill("force") < 1 || !stringp(force) )
    return notify_fail("你得先学习内功才能用内功恢复自己的精气。\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够。\n");
  
  if ( ((int)me->query("eff_jing") - (int)me->query("jing")) < 10 )
    return notify_fail("你现在精力充沛。\n");

 	diff = me->query("eff_jing") - me->query("jing");
	cd = SKILL_D(force)->force_character("TYPE_REC_CD");
	if ( !cd )
		cd=6;
		
    	//neilineed = diff * 50 / (int)me->query_skill("force");
  neilineed = diff *(50-(int)me->query_temp("forceextra")*(int)me->query("drugbath/continue")*5)/ (int)me->query_skill("force"); //by Zine 恢复加成for mutong quest
  if(neilineed < 1)
	  return notify_fail("你现在精力充沛。\n");
	  
	if ( me->query_temp("neili_speedup") )
		return notify_fail("你正在运行真气加速气血恢复，无法再分出内力来。\n");
	
	if ( time()-me->query_temp("recover_time")<= cd )
		return notify_fail("你上一次恢复气血，全身真气还没有平缓，请过一会儿再运行真气吧。\n");

	if ( !me->is_fighting() )
	{
    if(neilineed > me->query("neili")) 
    	neilineed = me->query("neili");
  
    diff = neilineed * (int)me->query_skill("force") / (50-(int)me->query_temp("forceextra")*(int)me->query("drugbath/continue")*5);
                                      		
	  me->receive_heal("jing", diff);
	  me->add("neili", -neilineed);
	}
	else
	{
		recv_coef=SKILL_D(force)->force_character("TYPE_RECOVER");
		if ( !recv_coef )
			recv_coef=100;
		recv_jing=me->query("max_jingli")/10 * me->query("int")/10 * recv_coef/100;
		if ( recv_jing > diff )
			recv_jing=diff;
		
		if ( recv_jing <= 0 )
		  recv_jing=1;
		 
		me->add("neili",-100);
		me->receive_heal("jing", recv_jing);
		me->start_busy(1);
		me->set_temp("recover_time",time());
	}
	
	message_vision("$N略一凝神，精神看起来好多了。\n", me);

	return 1;
}

