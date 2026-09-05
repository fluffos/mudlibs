// recover.c

//inherit SSERVER;

int exert(object me, object target)
{
	string force;
	int lvl, feff, flvl;
	int sld_pc, sld_nl;

	if (me != target)
		return notify_fail("你只能用内功调匀自己的气息。\n");

  force=me->query_skill_mapped("force");
  lvl=me->query_skill("force");
  feff=to_int(ceil(me->pure_degree("neili")*100));
  if ( lvl < 750 || !stringp(force) )
    return notify_fail("你的内功修为不够，无法运起「护体真气」。\n");
	
	if ((int)me->query("max_neili") < 5000 )
		return notify_fail("你的内力修为不够。\n");

	if ((int)me->query("neili") < 3000 )
		return notify_fail("你的内力不够。\n");
  
  if ( me->query_temp("active_force_buffer/force.shield") )
    return notify_fail("你正在运起「护体真气」。\n");

  flvl=lvl/750;
  if ( flvl>5 )
    flvl=5;
	
	sld_pc = SKILL_D(force)->force_character("TYPE_SHIELD_DEF");
	sld_nl = SKILL_D(force)->force_character("TYPE_SHIELD_NEILI");
	if ( !sld_pc )
	  sld_pc=5;
	
	if ( !sld_nl )
	  sld_nl=5;
	
	me->add_temp("apply/neili_recover", -sld_nl*flvl);
	me->add_temp("apply/armor_effect_armor_vs_force", sld_pc*flvl);
  me->add("neili", -100);
  
  me->set_temp("active_force_buffer/force.shield/name", "护体真气");                         //buff名称
  me->set_temp("active_force_buffer/force.shield/last_time", time() + 120 );                 //持续时间
  me->set_temp("active_force_buffer/force.shield/effect1", "内力吸收伤害："+(sld_pc*flvl)+"%");       //效果描述1   
  me->set_temp("active_force_buffer/force.shield/effect2", "内力恢复速度-"+(sld_nl*flvl)+"点/秒");              //效果描述2
	
  message_vision("$N运起「护体真气」抵御攻击。\n", me);
  me->start_call_out(__FILE__, "remove_effect", 120, me, sld_pc*flvl, sld_nl*flvl);
	if( me->is_fighting() ) me->start_busy(3);
	
	return 1;
}

void remove_effect(object me, int vsforce, int nl_rcv)
{
	me->add_temp("apply/neili_recover", nl_rcv);
	me->add_temp("apply/armor_effect_armor_vs_force", -vsforce);
  me->delete_temp("active_force_buffer/force.shield"); 
  tell_object(me, "你的「护体真气」运行完毕，将内力收回丹田。\n");
}