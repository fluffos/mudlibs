// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
//这里修改经验等对ap,dp的影响
varargs int skill_power(object ob, string skill, int usage, object opponent)
{
    int status, level, power, value, ratio, enemy_num, combat_exp;
    int ap_factor, pp_factor, dp_factor;
    string askill;

    if (!living(ob)) return 0;
    
    //增加临时属性：命中率调节因子，取值范围是-50到+100
    //含义是对应命中率-50%到+100%
    //by seagate@pkuxkx 2014/04/10
    ap_factor=ob->query_temp("apply/attack_factor");
    pp_factor=ob->query_temp("apply/parry_factor");
    dp_factor=ob->query_temp("apply/dodge_factor");
    if ( ap_factor<-50 )
      ap_factor=-50;
    if ( ap_factor>100 )
      ap_factor=100;
    if ( pp_factor<-50 )
      pp_factor=-50;
    if ( pp_factor>100 )
      pp_factor=100;
    if ( dp_factor<-50 )
      dp_factor=-50;
    if ( dp_factor>100 )
      dp_factor=100;
    
    if ( usage == SKILL_USAGE_ATTACK && 
         mapp(ob->query_temp("attack_val")) && mapp(ob->query_temp("attack_val/skill")) )
    {
        if ( objectp(ob->query_temp("weapon")) && stringp(ob->query_temp("attack_val/skill/weapon")) )
            askill = ob->query_temp("attack_val/skill/weapon");
        else if ( !objectp(ob->query_temp("weapon")) && stringp(ob->query_temp("attack_val/skill/no_weapon")) )
            askill = ob->query_temp("attack_val/skill/no_weapon"); 

        if ( stringp(askill) && 
             (find_object(SKILL_D(askill)) || file_size(SKILL_D(askill) + ".lpc") > 0) && 
             SKILL_D(askill)->valid_enable(skill))
            level = ob->query_skill(skill, 1) / 2 + ob->query_skill(askill, 1) + ob->query("level");
        else
            level = ob->query_skill(skill);
    }
    else
        level = ob->query_skill(skill);
/*  
  if(level > 1500)
  {
    level = 1500 + (level-1500)/10;
  }
  
  if(combat_exp > 400000000)
  {
    combat_exp = 400000000 + (combat_exp-400000000)/10;
  }  
*/
    combat_exp = ob->query("combat_exp");

    //icer added 20061211
    if ((ob->query("env/combat") == "verbose") && wizardp(ob))
        tell_object(ob, sprintf("skill_power step1 is %d\n", level));
    if (objectp(opponent) && (opponent->query("env/combat") == "verbose") && wizardp(opponent))
        tell_object(opponent, sprintf("opp skill_power step1 is %d\n", level));

    switch (usage)
    {
    case SKILL_USAGE_ATTACK:
        level += ob->query_temp("apply/attack");

        //icer added 20061211
        if ((ob->query("env/combat") == "verbose") && wizardp(ob))
            tell_object(ob, sprintf("apply/attack is %d\n", ob->query_temp("apply/attack")));
        if (objectp(opponent) && (opponent->query("env/combat") == "verbose") && wizardp(opponent))
            tell_object(opponent, sprintf("opp apply/attack is %d\n", ob->query_temp("apply/attack")));

        break;
    case SKILL_USAGE_DEFENSE:
        level += ob->query_temp("apply/defense");

        //icer added 20061211
        if ((ob->query("env/combat") == "verbose") && wizardp(ob))
            tell_object(ob, sprintf("apply/defense is %d\n", ob->query_temp("apply/defense")));
        if (objectp(opponent) && (opponent->query("env/combat") == "verbose") && wizardp(opponent))
            tell_object(opponent, sprintf("opp apply/defense is %d\n", ob->query_temp("apply/defense")));

        if (ob->is_fighting())
        //dodge 100的话就翻倍，是不是太高了？
        //icer modified 20061211: 减小fight/dodge参数的效力为原来的1/3，否则立方之后不得了
        {
            if (ob->query_temp("fight/dodge") > 50)
                level = level * (100 + ob->query_temp("fight/dodge") / 3) / 100;
            else
                level = level * (100 + ob->query_temp("fight/dodge") * 2 / 3) / 100;
        }
        //icer added 20061211
        if ((ob->query("env/combat") == "verbose") && wizardp(ob))
            tell_object(ob, sprintf("fight/dodge is %d\n", ob->query_temp("fight/dodge")));
        if (objectp(opponent) && (opponent->query("env/combat") == "verbose") && wizardp(opponent))
            tell_object(opponent, sprintf("opp fight/dodge is %d\n", ob->query_temp("fight/dodge")));


        break;
    }
    //icer added 20061211
    if ((ob->query("env/combat") == "verbose") && wizardp(ob))
        tell_object(ob, sprintf("skill_power step2 is %d\n", level));
    if (objectp(opponent) && (opponent->query("env/combat") == "verbose") && wizardp(opponent))
        tell_object(opponent, sprintf("opp skill_power step2 is %d\n", level));

    /****************************************************************************
    
     if( !level ) return (int)ob->query("combat_exp") / 2;
     
      // here need a modification later
      power = (level/3)*level*level;
      
       if (usage == SKILL_USAGE_ATTACK)
       return ((power+ob->query("combat_exp"))/30)*ob->query_str();
       else
       return ((power+ob->query("combat_exp"))/30)*ob->query_dex();
       
      modified by icer
      考虑到轻功为负值时，dp应该降低；经验为0时，应由先天属性决定skill_power，修改返回值如下:
      （此公式可能需要修改，以防溢出）
  *****************************************************************************/
    if (level <= 0)
        return (int)combat_exp / 50;

    if (level < 30)
        power = level * level * level / 30;
    else if (level >= 30 && level < 300)
        power = 900 + (level / 10) * (level / 10) * (level / 10) / 3;
    else if (level >= 300 &&
             level < 600)
        power = 7400 + (level / 15) * (level / 15) * (level / 15) / 3;
    else if (level >= 600 &&
             level < 1200)
        power = 19800 + (level / 20) * (level / 20) * (level / 20) / 3;
    else if (level >= 1200 &&
             level < 1800)
        power = 70600 + (level / 30) * (level / 30) * (level / 30) / 3;
    else if (level >= 1800 &&
             level < 3000)
        power = 127200 + (level / 50) * (level / 50) * (level / 50) / 3;
    else
        power = 196800 + (level / 150) * (level / 150) * (level / 150) / 3;
//  power = to_int((to_float(level)/600)*level*level);

    //icer added 20061211
    if ((ob->query("env/combat") == "verbose") && wizardp(ob))
        tell_object(ob, sprintf("skill_power step3 is %d\n", power));
    if (objectp(opponent) && (opponent->query("env/combat") == "verbose") && wizardp(opponent))
        tell_object(opponent, sprintf("opp skill_power step3 is %d\n", power));

    if (combat_exp / 1000 < 30)
        power = power + (int)combat_exp / 100;
    else if (combat_exp / 1000 >= 30 &&
             combat_exp / 1000 < 3000)
        power = power + 270 + (int)combat_exp / 1000;
    else if (combat_exp / 1000 >= 3000 &&
             combat_exp / 1000 < 21000)
        power = power + 2270 + (int)combat_exp / 3000;
    else if (combat_exp / 1000 >= 21000 &&
             combat_exp / 1000 < 180000)
        power = power + 5770 + (int)combat_exp / 6000;
    else if (combat_exp / 1000 >= 180000 &&
             combat_exp / 1000 < 600000)
        power = power + 20770 + (int)combat_exp / 12000;
    else
        power = power + 46770 + (int)combat_exp / 25000;

    //icer added 20061211
    if ((ob->query("env/combat") == "verbose") && wizardp(ob))
        tell_object(ob, sprintf("skill_power step4 is %d\n", power));
    if (objectp(opponent) && (opponent->query("env/combat") == "verbose") && wizardp(opponent))
        tell_object(opponent, sprintf("opp skill_power step4 is %d\n", power));

    //icer added 20091008
    //如果power在这里为负值，说明已经溢出，由下面处理成value最大值，不在这里设置为1，否则会引起无法命中的情况
    if (power == 0)
        power = 1;

    //避免溢出规定上限。mudy
    //icer modified 20061211：现在不光attack,连defense都会溢出了
    if (usage == SKILL_USAGE_ATTACK)
    {
        value=(int)(power*(ob->combat_str()*5+ob->combat_dex())/6);
        if ( ap_factor )
          value=value*(100+ap_factor)/100;

        if (objectp(opponent) && opponent->query("yidaizhenlong") && random(opponent->query("mud_age")) < 86400 * 20 && random(2))
        {
            message_vision(HIY"$N狂喝道:一代真龙，群豪俯首！$n被$N气势所震，劲力大减。\r\n"NOR, opponent, ob);
            value = value / 2;
        }
        
        if (value < 0)
        {
            log_file("wiz/combatd", sprintf("\n%s\n异常数据（攻击命中率溢出）：计算目标：%s(%s,%s)，类型：%s，等级：%d，经验：%d，命中：%d\n",
                                            ctime(time()), ob->query("name"), ob->query("id"), base_name(ob), skill, level, combat_exp, value));
            value = 2100000000;
        }
        //icer added 20061211
        if ((ob->query("env/combat") == "verbose") && wizardp(ob))
            tell_object(ob, sprintf("final skill_power ATTACK is %d\n", value));
        if (objectp(opponent) && (opponent->query("env/combat") == "verbose") && wizardp(opponent))
            tell_object(opponent, sprintf("opp final skill_power ATTACK is %d\n", value));

        return value;
    }
    else
    {
        if ( skill=="parry" ) 
        {
          value=(int)(power*(ob->combat_dex()*3+ob->combat_str())/4);
          if ( pp_factor )
            value=value*(100+pp_factor)/100;
        }
        else
        {
          value = (int)(power * ob->combat_dex());
          if ( dp_factor )
            value=value*(100+dp_factor)/100;
        }
        //解决dex为负数时的bug
        if(ob->combat_dex() < 0) value = 0;

        //一打多的时候降自己dp。Pal
        //隔30秒检查一次，否则会大幅增加系统负担
        //对手数量在20个以内正常下降dp,超过20个（hitall的限制）下降速度增加
        //朝廷守门难度太低，就不例外考虑了
        //只有玩家作此设置，npc不考虑，降低cpu负担
        if (userp(ob))
        {
            if (time() - ob->query_temp("combat/last_check_opp") > 30)
            {
                enemy_num = (int)sizeof(ob->query_enemy());
                enemy_num = enemy_num * enemy_num / 4;
                if (enemy_num > 40)
                    enemy_num = enemy_num * enemy_num / 4;
                enemy_num = enemy_num / 40;
                ob->set_temp("combat/enemy_num", enemy_num);
                ob->set_temp("combat/last_check_opp", time());
            }
            else
            {
                enemy_num = ob->query_temp("combat/enemy_num");
            }
            value = to_int(value / (0.98 + enemy_num));
        }

        if (objectp(opponent) && opponent->query("yidaizhenlong") && random(opponent->query("mud_age")) < 86400 * 20 && random(2))
        {
            message_vision(HIY"$N狂喝道:一代真龙，群豪俯首！$n被$N气势所震，空门大开。\r\n"NOR, opponent, ob);
            value = value / 2;
        }


        if (value < 0)
        {
            log_file("wiz/combatd", sprintf("\n%s\n异常数据（防御命中率溢出）：计算目标：%s(%s, %s)，类型：%s，等级：%d，经验：%d，命中：%d\n",
                                            ctime(time()), ob->query("name"), ob->query("id"), base_name(ob), skill, level, combat_exp, value));
            value = 2100000000;
        }
        //icer added 20061211
        if ((ob->query("env/combat") == "verbose") && wizardp(ob))
            tell_object(ob, sprintf("final skill_power DEFENSE is %d\n", value));

        if (objectp(opponent) && (opponent->query("env/combat") == "verbose") && wizardp(opponent))
            tell_object(opponent, sprintf("opp final skill_power DEFENSE is %d\n", value));

        return value;
    }
}

//attack的命中率纠正
int ap_factor(int ap, object me, object victim)
{
    object *partners;
    int i, deap;
    partners = victim->query_temp("partners");

    if (arrayp(partners))
    {
        for (i = 0; i < sizeof(partners); i++)
        {
            if (objectp(partners[i]) && environment(victim) == environment(partners[i]))
            {
                deap = partners[i]->help_defense(victim, me);
                if (deap > ap)
                    ap = 1;
                else
                    ap -= deap;
            }
        }
    }

    if (victim->query_temp("combat_factor"))
        ap = to_int(ap * victim->query_temp("combat_factor"));

  if( ap < 1) ap = 1;

    return ap;
}

//parry的命中率纠正
int pp_factor(int pp, object me, object victim, object weapon)
{
    object *partners;
    int i, depp;
    partners = me->query_temp("partners");

    //icer modified 20061211: 提高空手pp，降低有兵器pp，以提高空手功夫命中率
    /*icer的命中率修正有问题，导致空手命中下降而有兵器命中上升，现修正命中规则如下：
      当防御方有武器，攻击方空手，则防御方招架命中下降到66%（以前上升到150%）
      当防御方无武器，攻击方有武器，则防御方招架命中下降到50%（和以前保持不变）
      这个规则暂时合理性不太足，不过应该达到了提高空手命中下降武器命中的原先设计目的。
      by seagate@pkuxkx 20121225
    */
    if (victim->query_temp("weapon") && !weapon)
        pp = pp / 3 * 2; //iszt@pkuxkx, 2007-03-14, prevent overflow
    else if (weapon &&
             !victim->query_temp("weapon"))
        pp = pp / 2;

	if( victim->is_busy() ) pp /= 3;
	if( pp < 1) pp = 1;

    if (arrayp(partners))
    {
        for (i = 0; i < sizeof(partners); i++)
        {
            if (objectp(partners[i]) && environment(me) == environment(partners[i]))
            {
                depp = partners[i]->help_attack(me, victim);
                if (depp > pp)
                    pp = 1;
                else
                    pp -= depp;
            }
        }
    }
    return pp;
}

