mixed calc_damage(object me,object victim,object weapon,mapping my,mapping your,mapping action)
{
    int damage_bonus,defense_factor,damage;
    int deepj, weekj, defatk, absweekj;
    string result = "";
    string force_skill,martial_skill,attack_skill;
    mixed foo;

    attack_skill = choose_attack_skill(me, weapon);
    
    if ( me->query_temp("attack_val/skill") )
    {
        if ( objectp(weapon) )
        {
            martial_skill = me->query_temp("attack_val/skill/weapon");
        }
        else
        {
            martial_skill = me->query_temp("attack_val/skill/no_weapon");
        }
    }

    if ( !martial_skill || file_size(SKILL_D(martial_skill)+".lpc") < 0 )
        martial_skill = me->query_skill_mapped(attack_skill);

    //命中！计算伤害
    //增加单系伤害的支持，dmg_map下空手功夫统一置unarmed，其他为各兵器伤害
    if ( objectp(weapon) )
      damage = me->query_temp("apply/damage")+me->query_temp("apply/dmg_map/"+attack_skill);
    else
      damage = me->query_temp("apply/damage")+me->query_temp("apply/dmg_map/unarmed");
    
//防止外部加载的伤害为负数导致后续计算出现问题，统一将扣为负数的伤害认为没有damage。by seagate@pkuxkx
    if ( damage<0 )
    	damage=0;
    if ((me->query("env/combat")=="verbose") && wizardp(me))
      tell_object(me,sprintf("damage step 1: apply/damage is %d\n", damage));
    damage = (damage + random(damage)) / 2;      
    if ((me->query("env/combat")=="verbose") && wizardp(me))
      tell_object(me,sprintf("damage step 2: damage is %d\n", damage));
    if( action["damage"] )
        damage += action["damage"] * damage / 100;
    if ((me->query("env/combat")=="verbose") && wizardp(me))
      tell_object(me,sprintf("damage step 3: damage is %d\n", damage));      
    damage_bonus = me->query_str();      
    if( action["force"] )
        damage_bonus += action["force"] *damage_bonus / 100;
    
    if ((me->query("env/combat")=="verbose") && wizardp(me))
      tell_object(me,sprintf("damage step 4: damage_bonus is %d, action/force is %d\n", damage_bonus,action["force"]));
    
    // Let force skill take effect.
    if( my["jiali"] && (my["neili"] > my["jiali"]) ) {
        if( force_skill = me->query_skill_mapped("force") ) {
            foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);          
            if ((me->query("env/combat")=="verbose") && wizardp(me))
              tell_object(me,sprintf("damage step 4.5: force & jiali foo is %d\n", foo));
            if( stringp(foo) )
                result += foo;
            else if( intp(foo) )
                damage_bonus += foo;
        }

        if (strwidth(result))
        {
            combat_msg(result, 2, me, victim);
            COMBAT_D->report_status(victim);
            result = "";
        }
    }
    
    if ((me->query("env/combat")=="verbose") && wizardp(me))
      tell_object(me,sprintf("damage step 5: damage_bonus is %d\n", damage_bonus));

    if( martial_skill )
    {
        foo = find_skill(martial_skill)->hit_ob(me, victim, damage_bonus);        
        if( stringp(foo) )
            result += foo;
        else if(intp(foo) )
        {
            damage_bonus += foo;
            if ((me->query("env/combat")=="verbose") && wizardp(me))
              tell_object(me,sprintf("damage step 6: martial skill foo is %d\n", foo));
        }

        if (strwidth(result))
        {
            combat_msg(result, 2, me, victim);
            COMBAT_D->report_status(victim);
            result = "";
        }
    }
    
    // Let weapon or monster have their special damage.
    if( objectp(weapon) ) 
    {
        foo = weapon->hit_ob(me, victim, damage_bonus);
        if( stringp(foo) ) result += foo;
        else if(intp(foo) ) damage_bonus += foo;
        if (strwidth(result))
        {
            combat_msg(result, 2, me, victim);
            COMBAT_D->report_status(victim);
            result = "";
        }
    } 
    else 
    {
        foo = me->hit_ob(me, victim, damage_bonus);
        if( stringp(foo) ) result += foo;
        else if(intp(foo) ) damage_bonus += foo;
        if (strwidth(result))
        {
            combat_msg(result, 2, me, victim);
            COMBAT_D->report_status(victim);
            result = "";
        }
    }
    
    if ((me->query("env/combat")=="verbose") && wizardp(me))
      tell_object(me,sprintf("damage step 7: weapon damage is %d\n", foo));
    
    if( damage_bonus > 0 )
        damage += (damage_bonus + random(damage_bonus))/2;

    if ((me->query("env/combat")=="verbose") && wizardp(me))
      tell_object(me,sprintf("damage step 8: damage after adding bonus is %d\n", damage));

    //提供额外的攻击增益和防御增益
    //apply/deep_injure  普通伤害增益，按照百分比增加普通攻击伤害，加深效果最多不超过400%
    //apply/week_injure  普通伤害抗性（%），按照百分比削弱普通攻击伤害，削减效果最多不超过75%
    //apply/defense_attack 普通伤害抗性（点），按照固定数字削弱普通攻击伤害，削弱数字不超过总伤害的50%
    //apply/abs_week_injure 普通伤害绝对抗性，最多不超过25%
    deepj=me->query_temp("apply/deep_injure");
    weekj=victim->query_temp("apply/week_injure");
    defatk=victim->query_temp("apply/defense_attack");
    absweekj=victim->query_temp("apply/abs_week_injure");
    if ( deepj>0 || weekj>0 || defatk>0 )
    {
    	if ( deepj<-75 )
    		deepj=-75;
    	
    	if ( deepj>400 )
    		deepj=400;
    	
    	if ( weekj<-400 )
    		weekj=-400;
    	
    	if ( weekj>75 )
    		weekj=75;
      
      if ( absweekj<=0 )
        absweekj=0;
      
      if ( absweekj>25 )
        absweekj=25;
    	
    	if ( defatk<0 )
    		defatk=0;
    	
    	if ( defatk>damage/2 )
    		defatk=damage/2;
    	
    	damage=(damage-defatk)*(100+deepj)/100*(100-weekj-absweekj)/100;
    }
    
    damage=special_armor_effect(victim,me,damage);
    //whuan,这里注意，调用对手的盔甲特效
    if( damage < 0 ) 
    {
  	  log_file( "wiz/combatd", sprintf("\n%s\n异常数据（伤害负值）：计算目标：%s(%s)，对方：%s(%s), 武器伤害：%d，伤害：%d，附加伤害：%d\n", 
  	    ctime(time()), me->query("name"), me->query("id"), victim->query("name"), victim->query("id"), me->query_temp("apply/damage"), damage,  damage_bonus) );
      damage = 0;
    }
    
    // Let combat exp take effect
    defense_factor = your["combat_exp"];
    if(!intp(my["combat_exp"]) || my["combat_exp"] <= 0) my["combat_exp"] = 0;
    while( random(defense_factor) > my["combat_exp"] ) {
        damage -= damage / 3;
        defense_factor /= 2;
    }
    return ({damage,result});
}