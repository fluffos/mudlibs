//whuan，加入随机装备特效功能
int special_armor_effect(object me,object victim,int damage)
{
	int magic,kar,success; //
	int ratio,mf_bonus;
	magic = me->query_temp("apply/magic");
	kar=me->query_kar();
	
//修改装备特效的触发几率，触发几率为15%到85%
//by seagate@pkuxkx 2012/02/16
//稍微扩大封顶数值，目前封顶值是福源40，幸运值1925，之前是幸运值1800
//触发几率从10%到85%
//by seagate@pkuxkx 2012/12/31
	if (kar > 50) kar = 50;
	mf_bonus=kar + to_int(ceil(pow( magic*1.0, 0.66)*2/5)) ;
	success=mf_bonus/2+random(mf_bonus/2+100);

//如果对象昏迷不醒，禁止装备特效产生。
//by seagate@pkuxkx 2012/02/16
	if ( !living(me) )
		return damage;

	//armor特效
	if(me->query_temp("apply/armor_effect_poison")) //盔甲中毒
	{
		if(success >= 100)
		{  
			//message_vision(HIG"$N的盔甲上淬有剧毒！只见一道绿气迅速延伸到$n的手臂！\n"NOR,me,victim);
			combat_msg(HIG"$N的盔甲上淬有剧毒！只见一道绿气迅速延伸到$n的手臂！\n"NOR, 2, me, victim);
			F_POISON->poison_attack(me,victim,"emerald_poison", 
				victim->query_condition("emerald_poison") + me->query_temp("apply/armor_effect_poison"));
			if (!victim->is_killing(me->query("id"))) victim->kill_ob(me);
        }       	
    }
	if(me->query_temp("apply/armor_effect_rebound")) //盔甲反击
    {
		if(success >= 100 )
		{      	
			ratio = me->query_temp("apply/armor_effect_rebound");
			if(ratio > 100) ratio = 100;
			//message_vision(RED"$n这一击就像撞在了一堵墙上，攻击竟尽数被$N反弹了回来！\n"NOR,me,victim);
			combat_msg(RED"$n这一击就像撞在了一堵墙上，攻击竟尽数被$N反弹了回来！\n"NOR, 2, me, victim);
			F_KUNGFU->hit_wound("qi", damage * ratio / 100, random( damage * ratio / 100 ), me , victim);
            COMBAT_D->report_status(victim);
			if (wizardp(me))
				tell_object(me, sprintf("反震伤害力： %d[攻击伤害：%d]\n", damage * ratio / 100, damage));
		}
    }
	if(me->query_temp("apply/armor_effect_armor_vs_force")) //减少物理伤害,用一半的内力来抵扣物理伤害
	{
		if(me->query("neili")>0)              //取消内力吸收伤害的概率要求，因为现在是从exert shield产生的，护体真气作用机理就不要概率了，而且这个效果也变差了
		{  
			ratio = me->query_temp("apply/armor_effect_armor_vs_force");
			if(ratio > 100) ratio = 100;
			if ( me->query("neili")>damage * ratio / 300 &&
				   me->query("neili")>100 )
		  {
//内力先扣除，扣除内力修改为扣除伤害/3
//by seagate@pkuxkx 2012/02/16
			  me->add("neili", - damage * ratio / 300);
			  damage =damage - damage * ratio / 100;
			  //message_vision(diamond_effect_msg[random(3)],victim,me);
			  combat_msg(diamond_effect_msg[random(3)], 2, victim, me);
			  if (wizardp(me))
				  tell_object(me, sprintf("内力抵扣伤害： %d\n", damage * ratio / 100));
      }
    }       	
  } 
	if(me->query_temp("apply/armor_effect_healup")) //物理伤害的比例变成内力
	{
		if(success >= 100 )
		{  
			ratio = me->query_temp("apply/armor_effect_healup");
			if(ratio > 100) ratio = 100;
			if ( me->query("neili") < me->query("max_neili")*2 )
			  me->add("neili",  damage * ratio / 100);
			//message_vision(HIY"$N被$n击中，内力被送入膻中气海，积贮了起来。\n"NOR,me,victim);
			combat_msg(HIY"$N被$n击中，内力被送入膻中气海，积贮了起来。\n"NOR, 2, me, victim);
			if (wizardp(me))
				tell_object(me, sprintf("伤害转化成内力： %d\n", damage * ratio / 100));
        }       	
    }            
	return damage;
	
}

//暗器也就是action里面设置成skip_action的所有功夫调用的特效模式
int anqi_attack(object me,object victim,string martial_skill)
{
    mapping my, your;

   	my = me->query_entire_dbase();
	  your = victim->query_entire_dbase();
    if(my["neili"]>=my["jiali"])
    {
        me->add("neili",0-my["jiali"]);
        SKILL_D(martial_skill)->hit_ob(me, victim, my["jiali"]);
    }
    else
    {
        me->set("neili",0);
        SKILL_D(martial_skill)->hit_ob(me, victim, my["neili"]);
    }
    
    if(random(2)>0)
    {
        if( random(my["dex"]) < 5 )
        {
            combat_msg("$N瞅准$n一个破绽，发动反击！\n",1,victim, me);
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
        }
        else
        {
            combat_msg("$N以攻为守，向$n使出看家本领！\n",1, victim, me);
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
        }
    }
    return 1;
}

//武器在战斗过程中的磨损处理
string weapon_clash(object weapon,object me,object victim)
{
    object ob, uitem;
    string result = "";

    //Vast增加武器的相互碰撞损耗(武器对武器时的格挡)
    if(weapon && ob = victim->query_temp("weapon"))
    {
        if(random(weapon->query("rigidity") + ob->query("rigidity") + 100) > ob->query("rigidity"))
        {
            ob->add("rigidity", -1);
            ob->add_temp("rigidity", 1);
            ob->set_temp("clash_time", time());
            if( ob->query("gem_ob_autoloaded") == 1 &&
                ( ob->query_temp("rigidity")>10 ||
                  time()- ob->query_temp("clash_time")>=120 || 
                  ob->query("rigidity")<=2 ) &&
                userp(victim) )
            {
                uitem=new(UITEM_OB);
                uitem->set("id", victim->query("id"));
//                if ( uitem->check_save() )
                  uitem->restore();
                
                if ( ob->query("autoload_serial") )
                  uitem->update_autoload(ob->query("autoload_serial"), "set", ([ "rigidity": ob->query("rigidity") ]));
                
                uitem->save();
                destruct(uitem);
            }
        }
        
        if(random(ob->query("rigidity") + weapon->query("rigidity") + 100) > weapon->query("rigidity"))
        {
            weapon->add("rigidity", -1);
            weapon->add_temp("rigidity", 1);
            weapon->set_temp("clash_time", time());
            
            if( weapon->query("gem_ob_autoloaded") == 1 &&
                ( weapon->query_temp("rigidity")>10 ||
                  time()- weapon->query_temp("clash_time")>=120 || 
                  weapon->query("rigidity")<=2 ) &&
                userp(me) )
            {
                uitem=new(UITEM_OB);
                uitem->set("id", me->query("id"));
//                if ( uitem->check_save() )
                  uitem->restore();
                
                if ( weapon->query("autoload_serial") )
                  uitem->update_autoload(weapon->query("autoload_serial"), "set", ([ "rigidity": ob->query("rigidity") ]));
                
                uitem->save();
                destruct(uitem);
            }
        }
        
        
        if(ob->query("rigidity") < 1)
        {
            result = HIW "( 只听见「啪」地一声，$n"+HIW+"手中的" + ob->name() + HIW + "已经断为两截！ )\n" NOR;
            combat_msg(result, 2, me, victim);
            ob->unequip();
            ob->move(environment(victim));
            ob->set("name", "断掉的" + ob->query("name"));
            if (!ob->query("gem_ob_autoloaded"))
            {
                ob->set("value", 0);
                ob->set("weapon_prop", 0);
            } 
            destruct(ob);
            victim->reset_action();
        }
        if( objectp(weapon) && weapon->query("rigidity") < 1)
        {
            result = HIW "( 只听见「啪」地一声，$N手"+HIW+"中的" + weapon->name() + HIW + "已经断为两截！ )\n" NOR;
            combat_msg(result, 2, me, victim);
            weapon->unequip();
            weapon->move(environment(me));
            weapon->set("name", "断掉的" + weapon->query("name"));
            if (!weapon->query("gem_ob_autoloaded"))
            {
                weapon->set("value", 0);
                weapon->set("weapon_prop", 0);
            }  
            destruct(weapon);
            me->reset_action();
        }
        else if ( objectp(ob) )
        {
            result = "( $N的" + weapon->name() + "和$n的" + ob->name() + "相击，冒出点点的火星。 )\n";
            combat_msg(result, 0, me, victim);
        }
						
    }
    return result;
}
