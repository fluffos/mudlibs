// bianfu-except.c
// by jeeny 
      
 
      
inherit F_CLEAN_UP; 
      
int dispel(object me, object ob, int duration) 
{ 
	int n; 
 
	if (me != ob) 
	{ 
		if (me->query_skill_mapped("force") != "jiuyang-shengong")
		{
			tell_object(ob, "你发觉" + me->name() + "的内力源源涌进，但" 
				    "丹田还是冰冷，毫无帮助。\n");
			tell_object(me, "你试图帮助" + ob->name() + "化解其体内阴毒，" 
				    "却忽然发现阴毒源源不断地传来，不由大惊，连" 
				    "忙住手。\n");
			return -1;
		}
 
	} else
	if (me->query_skill_mapped("force") != "jiuyang-shengong")
	{
		tell_object(me, "你觉得丹田冰冷，无法凝聚内力。\n");
			     
		return -1; 
	} 
      
	n = ob->query_condition("bianfu-except") -
	    (int)me->query_skill("jiuyang-shengong", 1);

	if (n < 1) 
		ob->clear_condition("bianfu-except"); 
	else 
		ob->apply_condition("bianfu-except", n); 
  
	tell_object(me, "你默默的运用神功，帮助" + ob->name() + "化解体内的阴毒。\n"); 
   
	return 1; 
} 
   
int update_condition(object me, int duration) 
{ 
  
  
	if (! living(me) && (me->query("eff_qi") < 20 || me->query("eff_jing") < 10)) 
	{  
		me->unconcious(); 
		return 0; 
	} else 
	{ 
		me->receive_wound("qi", 100); 
		me->receive_wound("jing", 50); 
		tell_object(me, HIW"你只觉得一股寒意袭上心头，浑"
			    "身说不出得难受。"NOR"\n");
		message("vision", HIB + me->name() + HIB "忽然一"
			"颤，脸色发青，直打哆嗦。"NOR"\n", 
		       environment(me), ({ me }));
	} 
 
	return 1; 
} 