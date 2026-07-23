int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object target=me->select_opponent();
	if(target->query("combat_exp") < 300000)
	return 0;

	switch (me->query("real_menpai")) {
	case "huashan" :

	if( me->query("qi",1) < 10 || me->query("jing",1) < 10 || me->query("jingli",1) < 10) return;

//	if ( !me->is_fighting() ) {
//		if ( me->query("eff_qi") < me->query("max_qi") )
//		me->exert_function("heal");
//		return 1;
//		}

		if ( objectp(weapon) ) {
			if ( weapon->query("skill_type") == "sword" && random(4) == 0 )
			return command("perform jianzhang"); 
			else if ( weapon->query("skill_type") == "blade" && random(4) == 0)
			return command("perform sanshen");
		}
	else if ( !me->query_temp("leidong") && random(4) == 0) {
		return command("perform leidong");
	}
	else if ( !me->query_temp("wuji") && target->query_condition("hyz_damage") <= 5 && random(4) == 0) {
		return command("perform wuji");
	}
	
//	if ( !me->is_fighting() ) {
//		if ( me->query("eff_qi") < me->query("max_qi") )
//			exert_function("heal");
//		return 1;
//	}

		break;
		
	case "wudang" :
	if ( !objectp(target)
		|| !random( (int)me->query("combat_exp") * 2
		/ (int)target->query("combat_exp") + 1) ) return 0;

	if( !objectp(target->query_temp("weapon")) || me->query_temp("chan/"+target->name()))
		command("unwield sword");
	else
		command("wield sword");

	if( !me->query_temp("taiji") && random(3) == 0 && me->query("combat_exp") > 2000000 )
		command("exert taiji");

	else if( objectp(weapon) && weapon->query("skill_type") == "sword")
	{
		me->map_skill("parry", "taiji-jian");
		me->reset_action();

		if( !target->is_busy() )
			return command("perform shenmen");
		else
			return command("perform chan");
	}
	else
	{
		me->map_skill("parry", "taiji-quan");
		me->reset_action();

		switch( random(2) )
		{
			case 0:
				if( target != me->query_temp("nian") )
					return command("perform nian");
				else
					return command("perform luanhuan");
				break;
			case 1:
				return command("perform luanhuan");
				break;
		}
	}

		break;

	case "shaolin" :

	if ( !objectp(target)
		|| !random( (int)me->query("combat_exp") * 2
		/ (int)target->query("combat_exp") + 1) ) return 0;


	if ( objectp(weapon) ) {
		switch (weapon->query("skill_type")) {
	
		case "whip" : 
		return command("perform chanrao");
		break ;
	
		case "club" :
		if (me->query_skill_mapped("club") == "zui-gun")
			return command("perform zuida");
		else
			return 0;
			
		break;

		case "sword" :
		if (me->query_skill_mapped("sword") == "damo-jian" && random(3) == 0)
		return command("perform weituo");
		else 
		return 0;
		break;  
		}       
	}
	else
	{       
		command("exert jingang");

		if (me->query_skill_prepared("strike") == "banruo-zhang" && random(3) == 0)
		{
		me->reset_action();
		return command("perform san");
		}
		
		if (me->query_skill_prepared("finger") == "nianhua-zhi" && random(2) == 0 )
		{
		me->map_skill("parry", "nianhua-zhi");
		me->reset_action();
		return command("perform fuxue");
		}	       

		if (me->query_skill_prepared("finger") == "yizhi-chan" && random(2) == 0 )
		{
		me->map_skill("parry", "yizhi-chan");
		me->reset_action();
		return command("perform jingmo");
		}
		
		if (me->query_skill_prepared("cuff") == "jingang-quan")
		{
		me->map_skill("parry", "jingang-quan");
		me->reset_action();
		return command("perform jingang");
		}
		return 0;
				
	}
		break;
		
	case "emei" :
	if ( !objectp(target)
		|| !random( (int)me->query("combat_exp") * 2
		/ (int)target->query("combat_exp") + 1) ) return 0;

	if( !objectp(target->query_temp("weapon")) || me->query_temp("chan/"+target->name()))
		command("unwield sword");
	else
		command("wield sword");

	if( !me->query_temp("fengyun") && random(3) == 0 && me->query("combat_exp") > 500000 )
		command("exert fengyun");

	else if( objectp(weapon) && weapon->query("skill_type") == "sword")
	{
		me->map_skill("parry", "emei-jian");
		me->reset_action();

			return command("perform jue");
		else
			return command("perform mie");
	}
	

		break;
	case "gaibang" :
	if ( !objectp(target)
		|| !random( (int)me->query("combat_exp") * 2
		/ (int)target->query("combat_exp") + 1) ) return 0;

	if( !objectp(target->query_temp("weapon")) || me->query_temp("chan/"+target->name()))
		command("unwield bang");
	else
		command("wield bang");

	if( !me->query_temp("powerup") && random(3) == 0 && me->query("combat_exp") > 500000 )
		command("exert powerup");

	else if( objectp(weapon) && weapon->query("skill_type") == "stick")
	{
		me->map_skill("parry", "dagou-bang");
		me->reset_action();

		if( !target->is_busy() )
			return command("perform chan");
		else
			return command("perform feng");
	}

	else
	{
		me->map_skill("parry", "xianglong-zhang");
		me->reset_action();

		switch( random(2) )
		{

			case 0:

			       return command("perform sanhui");
				break;
			case 1:
				return command("perform leiting");
				break;
		}
	}


		break;
       case "dali" :
	if ( !objectp(target)
		|| !random( (int)me->query("combat_exp") * 2
		/ (int)target->query("combat_exp") + 1) ) return 0;

	if( !objectp(target->query_temp("weapon")) || me->query_temp("chan/"+target->name()))
		command("unwield sword");
	else
		command("wield sword");

	if( !me->query_temp("kurong") && random(3) == 0 && me->query("combat_exp") > 2000000 )
		command("exert kurong");

	else if( objectp(weapon) && weapon->query("skill_type") == "sword")
	{
		me->map_skill("parry", "duanjia-jian");
		me->reset_action();

//		if( !target->is_busy() )
			return command("perform ailao");

	}
	else
	{
		me->map_skill("parry", "yiyang-zhi");
		me->reset_action();

		switch( random(2) )
		{
			case 0:
				if( target != me->query_temp("qiankun") )
					return command("perform qiankun");
				else
					return command("perform piaomiao");
				break;
			case 1:
				return command("perform qiankun");
				break;
		}
	}

		break;

	default:
		return 0;
	}
}
