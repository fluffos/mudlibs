//Alan.F change add auto perform 20010927
//"baituo""huashan""emei""wudang""shaolin""gaibang""xingxiu""xueshan""taohua"
// auto perform function (dispatched by chat_combat_msg)

int baituo_perform()
{
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if( !me->query_temp("powerup") && random(3) ==1)
                command("exert powerup");
        else if( !me->query_temp("reverse") && random(3) ==1)
                command("exert reverse");

        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "staff" && (int)me->query_skill("poison", 1) > 200 && random(2) == 1)
                        return perform_action("staff.bite");
                else return perform_action("staff.shoot");

        }
        else return perform_action("strike.puji");
}

int huashan_perform()
{
object me=this_object();
        object weapon=me->query_temp("weapon");
        object opp=me->select_opponent();

        if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 50);

                return 1;
        }

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "sword" )
                        return perform_action("sword.jianzhang");
        }
        else if ( !me->query_temp("leidong") ) {
                        return perform_action("cuff.leidong");
        }
        else if ( !me->query_temp("wuji") && opp->query_condition("hyz_damage") <= 5 ) {
                        return perform_action("strike.wuji");
        }
}
int emei_perform()
{
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "sword" )
                        return perform_action("sword.mie");
                else if ( weapon->query("skill_type") == "blade" )
                        return perform_action("blade.huanying");
        }
}
int wudang_perform()
{
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if( !objectp(target->query_temp("weapon")) )
                command("unwield sword");
        else
                command("wield sword");

        if( !me->query_temp("taiji") )
                command("exert taiji");

        if( objectp(weapon) && weapon->query("skill_type") == "sword" )
        {
                me->map_skill("parry", "taiji-jian");
                me->reset_action();

                if( !target->is_busy() )
                        return perform_action("sword.chan");
        }
        else
        {
                me->map_skill("parry", "taiji-quan");
                me->reset_action();

                switch( random(2) )
                {
                        case 0:
                                if( target != me->query_temp("nian") )
                                        return perform_action("cuff.nian");
                                else
                                        return perform_action("cuff.luanhuan");
                                break;
                        case 1:
                                return perform_action("cuff.luanhuan");
                                break;
                }
        }
}

int shaolin_perform()
{
        
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");
        
        
        if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 100);
                return 1;
        }

        if ( !objectp(target)
                || !random( (int)me->query("combat_exp") * 2
                / (int)target->query("combat_exp") + 1) ) return 0;

        if ( objectp(weapon) ) {
                switch (weapon->query("skill_type")) {
        
                case "whip" : 
                return perform_action("whip.chanrao");
                break ;
        
                case "club" :
                if (me->query_skill_mapped("club") == "zui-gun")
                        {
                        if (me->query_condition("drunk", 1) < 40)
                        {       
                        me->apply_condition("drunk", 40);
                        return perform_action("club.zuida");
                        }
                else 
                        return perform_action("club.zuida");
                        }
                else
                        
                        return 0;
                        
                break;

                case "sword" :
                if (me->query_skill_mapped("sword") == "damo-jian")
                return perform_action("sword.sanjue");
                else 
                return 0;
                break;  
                }       
        }
        else
        {       
                if (me->query_skill_prepared("finger") == "nianhua-zhi")
                {
                me->map_skill("parry", "nianhua-zhi");
                me->reset_action();
                return perform_action("finger.fuxue");
                }               

                if (me->query_skill_prepared("finger") == "yizhi-chan")
                {
                me->map_skill("parry", "yizhi-chan");
                me->reset_action();
                return perform_action("finger.jingmo");
                }
 
                if (me->query_skill_prepared("cuff") == "jingang-quan")
                {
                me->map_skill("parry", "jingang-quan");
                me->reset_action();
                return perform_action("cuff.jingang");
                }
                return 0;
                                
}
}

int gaibang_perform()
{
object me=this_object();
        object weapon=me->query_temp("weapon");
        object opp=me->select_opponent();

        if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 50);

                return 1;
        }

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "blade" )
                        return perform_action("blade.lianhuan");
        }
}

int xingxiu_perform()
{
        object me = this_object();
        object target = me->select_opponent();

        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if( objectp(me->query_temp("weapon")) ) {
                command("perform jinxian");
        }
        else
        {
                if( !target->query_temp("huagong") )
                        command("perform sanyin");
                else
                	command("perform yiji");
                        command("yun qisuck "+target->query("id"));
        }

/*        if( present("sanxiao san", me) ||present("biling zhen", me)
          ||present("lianxin dan", me)){
          command("throw " + target->query("id"));
          }
*/
                return 1;
}

int taohua_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");
	object weapon2 = target->query_temp("weapon");

        if( !me->query_temp("wuzhuan") && random(2)==0)
                command("exert wuzhuan");

	if ( !objectp(target)
	  || !random( (int)me->query("combat_exp") * 2
		   / (int)target->query("combat_exp") + 1) ) return 0;

	if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "sword" )
		{
		switch( random(3) )
                {
                        case 0:
				return perform_action("sword.jinglei");
                                break;
                        case 1:
                                return perform_action("sword.jianmang");
                                break;
                        case 2:
                        	{me->prepare_skill("kick");
                        	me->prepare_skill("strike");
                        	me->prepare_skill("finger","tanzhi-shentong");
                                return perform_action("sword.jianzhi");}
                                break;

			}
                }
	}
	
	else {
	if(objectp(weapon2) && random(2) == 0) {
	me->prepare_skill("kick");
	me->prepare_skill("strike");
	me->prepare_skill("finger","tanzhi-shentong");
	return perform_action("finger.jinglei");
	}
	else {
	me->prepare_skill("kick","xuanfeng-saoye");
	me->prepare_skill("strike","luoying-shenjian");
	me->prepare_skill("finger");
	return perform_action("strike.kuangfeng");
	}
	}
}

int quanzhen_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");


	//if ( !objectp(target) ) return 0;



	if( !is_busy() && !is_fighting() && !objectp(target) )
	{
		if( me->query("eff_qi",1) < me->query("max_qi") && me->query("eff_qi",1) > me->query("max_qi")/2 )
		{
			command("yun heal");
			command("yun heal");
			command("yun recover");
			return 1;
		}

		command("dazuo 500");
		return 1;
	}




	if ( objectp(weapon) && weapon->query("skill_type") == "sword")
	{

		  if( me->query("eff_qi",1) > me->query("max_qi")/2 &&
			me->query("eff_qi",1) < me->query("max_qi",1)*2/3)
		  {
			command("halt");
			command("yun heal");
			command("yun heal");
			command("yun heal");
			command("yun recover");
		  }
		  else if( me->query("neili") < 150 && me->query("eff_qi",1) < me->query("max_qi")/2 )
			perform_action("sword.tonggui");
		  else
		  {
			if(!me->query_temp("sanqing"))
				return perform_action("sword.sanqing");
			else if( me->query("id") == "wang chongyang" )
			{
				command("yun shentong "+target->query("id"));
			}
			else return perform_action("sword.sanqing");
		  }


	}
	else if ( objectp(weapon) && weapon->query("skill_type") == "whip")
	{
		return perform_action("whip.riyue");
	}
	else
	{
		if( !me->query_temp("sanhua",1) )
			return perform_action("strike.sanhua");
		else if( me->query("id") == "wang chongyang" )
		{  command("yun shentong "+target->query("id"));
		}
		else return perform_action("cuff.lianhuan");
	}
}

int dali_perform()
{
	int tempjiali;
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if (!me->is_fighting()) {
		if ( me->query("eff_qi") < me->query("max_qi") ) {
			tempjiali=me->query("jiali");
			exert_function("heal");
			me->set("jiali", tempjiali);
		}
		return 1;
	}

	if (!objectp(target)
		|| !random( (int)me->query("combat_exp") * 2 / (int)target->query("combat_exp") + 1) )
		return 0;

	if (objectp(weapon)) {
		if (weapon->query("skill_type") == "sword")
			return perform_action("sword.ailao");
	}

	if (!objectp(weapon)) {
		if ( me->query_skill("yiyang-zhi", 1) > 80)
			return perform_action("finger.qiankun");
	}
	else

	return 1;
}

int xueshan_perform()
{
	int tempjiali;
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if (!me->is_fighting()) {
		if ( me->query("eff_qi") < me->query("max_qi") ) {
			tempjiali=me->query("jiali");
			exert_function("heal");
			me->set("jiali", tempjiali);
		}
		return 1;
	}

	if ( !objectp(target)
	  || !random( (int)me->query("combat_exp") * 2
		   / (int)target->query("combat_exp") + 1) ) return 0;
	if( !me->query_temp("longxiang") && random(2) == 0 )
		command("exert longxiang");
	else if( !me->query_temp("shielded") && random(2) == 0)
		command("exert shield");

	else if( objectp(weapon) && weapon->query("skill_type") == "blade")
	{
		me->reset_action();
		if( !target->is_busy() )
			return perform_action("blade.shendao");
	}

	return perform_action("strike.fen");
}

int auto_perform()
{
	object me = this_object();
	string menpai;

	if (me->query("combat_exp") < 1000000)  return 0;

	if (query("menpai"))
	{
		menpai = query("menpai");
		switch (menpai){
			case "baituo":
				baituo_perform();
				break;
			case "huashan":
				huashan_perform();
				break;
			case "shaolin":
				shaolin_perform();
				break;
			case "quanzhen":
				quanzhen_perform();
				break;
			case "gaibang":
				gaibang_perform();
				break;
			case "taohua":
				taohua_perform();
				break;
			case "emei":
				emei_perform();
				break;
			case "xingxiu":
				xingxiu_perform();
				break;
			case "dali":
				dali_perform();
				break;
			case "xueshan":
				xueshan_perform();
				break;
		}
	}
	return 1;
}