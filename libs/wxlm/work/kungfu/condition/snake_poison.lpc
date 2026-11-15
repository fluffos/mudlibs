// snake_poison.c
// by jeeny



inherit F_CLEAN_UP;

int dispel(object me, object ob, int duration)
{
	int n;

	if (me != ob)
	{
		if (me->query_skill_mapped("finger") != "sun-finger" &&
		    me->query("max_neili") < 3500)
		{
			tell_object(ob, "你发觉" + me->name() + "的内力缓缓传入你体内，但" 
				    "你只觉腹痛如绞，额头渗出一粒粒斗大的汗珠。\n"); 
			tell_object(me, "你试图帮助" + ob->name() + "化解其体内剧毒，"
				    "但见" + ob->name() + "汗如雨下，连忙住手。\n"); 
			return -1;
		}

	} else
	{
		tell_object(me, "你试图运功化解灵蛇巨毒，但丹田内" 
				"传来阵阵撕心裂肺的疼痛，怎么也凝聚不起内力。\n"); 
		return -1;
	}

	n = ob->query_condition("snake_poison") -
	    (int)me->query_skill("sun-finger", 1);

	if (n < 1)
	{
		ob->clear_condition("snake_poison");
		me->add("max_neili", -(2000 + random(1000)));
	} else
		ob->apply_condition("snake_poison", n);

	tell_object(me, "你运用玄阳指神功，帮助" + ob->name() + "化解体内的剧毒。\n");

	return 1;
}

int update_condition(object me, int duration)
{
 

	if(! living(me) &&
	   (me->query("qi") < 25 || me->query("jing") < 25))
	{
		me->set_temp("die_reason", "灵蛇剧毒发作，不治身亡了");
		me->die();
		return 0;
	} else
	{
		me->receive_wound("jing", 25 + random(25));
		me->receive_damage("jing", 25 + random(25));
		me->receive_wound("qi", 50 + random(50));
		me->receive_damage("qi", 50 + random(50));
		tell_object(me, HIG "你中的" HIR "灵蛇剧毒" HIG "发作了！"NOR"\n" );
		message("vision", HIG + me->name() + "一阵摇晃，立足"
				  "不定。"NOR"\n",
			environment(me), me);
	}
	return 1;
}