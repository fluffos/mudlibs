// xuanming_poison.c
// by jeeny



inherit F_CLEAN_UP;

int dispel(object me, object ob, int duration)
{
	int n;

	n = ob->query_condition("xuanming_poison") - (int)me->query_skill("jiuyang-shengong", 1) - (int)me->query_skill("force") / 100;

	if (n < 1)
		ob->clear_condition("xuanming_poison");
	else
		ob->apply_condition("xuanming_poison", n);

	if (me != ob)
		tell_object(me, "你运起内功，帮助" + ob->name() + "化解体内的寒毒。\n");  
	else
		tell_object(me, "你运起内功，开始化解体内的寒毒。\n");  
	
	return 1;
}

int update_condition(object me)
{
 

	if (! living(me) && (me->query("eff_qi") < 20 || me->query("eff_jing") < 10))
	{
		me->set_temp("身中玄冥掌毒，不治身亡了"); 
		me->die();
		return 0;
	} else
	{
		me->receive_wound("qi", 50);
		me->receive_wound("jing", 50);
		tell_object(me, MAG"你中的天幽神掌之毒发作了。"NOR"\n");
		message("vision", MAG + me->name() + MAG "牙齿直打冷颤，浑身抖个不停。"NOR"\n",environment(me), ({ me }));
	}
	
	return 1;
}