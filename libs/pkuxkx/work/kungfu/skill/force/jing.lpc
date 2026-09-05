// regenerate.c
//inherit SSERVER;

int exert(object me, object target)
{
	string force;
	int recv_speed, neili_dec;

	if (me != target)
		return notify_fail("你只能用内功恢复自己的精气。\n");
  
  force=me->query_skill_mapped("force");
  if (me->query_skill("force") < 1 || !stringp(force) )
    return notify_fail("你得先学习内功才能用内功恢复自己的精气。\n");
  
  if (me->query_temp("neili_speedup") )
  	return notify_fail("你已经运行内功凝神加快自身精气恢复。\n");
  
  if ( recv_speed=SKILL_D(force)->recover_speed(me) )
  {
  	neili_dec=SKILL_D(force)->force_character("TYPE_DEC_SPD");//TYPE_DEC_SPD
  	if ( !neili_dec )
  		neili_dec=100; 
    me->set_temp("apply/jing_recover_speed", recv_speed );
    me->set_temp("apply/neili_decrease", neili_dec);
    me->set_temp("neili_speedup",1);
  }
  me->set_temp("recover/jing_recover", me->query_jing_recover());  	
  message_vision("$N静心凝神，加速自身的精气恢复。\n", me);
  call_out("speed_end", 60, me);
	return 1;
}

void speed_end(object me)
{
	if ( !objectp(me) ) 
		return;
	me->delete_temp("apply/jing_recover_speed");
	me->delete_temp("apply/neili_decrease");
	me->delete_temp("neili_speedup");
  me->set_temp("recover/jing_recover", me->query_jing_recover());
	message_vision("$N减缓真气运行，让自身恢复正常。\n", me);
}