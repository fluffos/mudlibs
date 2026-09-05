// force.c
//调整下空手伤害,削弱高damage的伤害
inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
  int damage;
  int my_max_nl,victim_max_nl, base, maxpct, maxnt, enf_nl;
  string force;

  if ( me->query("max_neili")>me->query_skill("force")*10 )
    my_max_nl=me->query_skill("force")*10;
  else
    my_max_nl=me->query("max_neili");

  if ( victim->query("max_neili")>victim->query_skill("force")*10 )
    victim_max_nl=victim->query_skill("force")*10;
  else
    victim_max_nl=victim->query("max_neili");

  if ( !victim_max_nl && my_max_nl )
    maxnt=125;
  else if ( !victim_max_nl && !my_max_nl )
    maxnt=100;
  else 
    maxnt=my_max_nl*100/victim_max_nl;
  
  if ( maxnt>125 )
    maxnt=125;
  if ( maxnt<80 )
    maxnt=80;
  
  if (me->query("neili") < me->query("max_neili") * 2)
    my_max_nl = me->query("neili")/2 + my_max_nl/2;
  else
    my_max_nl = my_max_nl * 3 / 2;

  if (victim->query("neili") < victim->query("max_neili") * 2)
    victim_max_nl = victim->query("neili")/2 + victim_max_nl/2;
  else
    victim_max_nl = victim_max_nl * 3 / 2;
  
  if ( me->query_temp("weapon") )
  {
    base=me->query_skill("force")/5;  
    damage = ( my_max_nl/15 - victim_max_nl/20 + factor - base ) * factor / base * maxnt/100;
  }
  else
  {
    base=me->query_skill("force")/7;  
    damage = ( my_max_nl/15 - victim_max_nl/25 + factor - base ) * factor / base * maxnt/100;
  }
  
  //确定伤害的最高上限为damage_bonus*maxpct，这里求maxpct的具体倍数，默认值为8倍，最低值不低于5倍，最高值不高于25倍
  //获取加力攻击的内力消耗系数，默认是100%
  force=me->query_skill_mapped("force");
  if ( !stringp(force) )
  {
    enf_nl=100;
    maxpct=8;
  }
  else
  {
    enf_nl=SKILL_D(force)->force_character("TYPE_ENF_NL");
    maxpct=SKILL_D(force)->force_character("TYPE_ENFORCE");
  }
  
  //对加力攻击的内力消耗系数进行调整，首先试图调用内功中的change_enforce函数，如果存在该函数并对消耗系数进行调整
  //则内力消耗系数使用该函数的返回值，否则调整项是空手功夫内力消耗系数减半。
  //空手内力消耗变低没有了
  if ( stringp(force) &&
       SKILL_D(force)->change_enforce(me, enf_nl) )
    enf_nl=SKILL_D(force)->change_enforce(me, enf_nl);
  else if ( !me->query_temp("weapon") )
	{
	  if (me->query_temp("jiali_daliwan"))
		{
			enf_nl -= me->query_temp("jiali_daliwan");//大力丸效果
		}

	}
 
  me->add("neili", - factor*enf_nl/100 );
  
  if ( me->query_temp("weapon") )
    maxpct=maxpct/2;
  else
	maxpct=maxpct*3/4;
  
  if ( maxpct<4 )
    maxpct=4;
  
  if ( maxpct>15 )
    maxpct=15;
  
  //不管damage大于0或者小于0，都不能脱离damage_bonus*maxpct确定的范围
  if ( damage_bonus>0 )
  {
    if ( damage > 0 && damage>damage_bonus*maxpct )
      damage=damage_bonus*maxpct;
  
    if ( damage < 0 && damage+damage_bonus*maxpct<0 )
      damage=-damage_bonus*maxpct;  
  }
  else 
    damage=0;

 //if ( wizardp(me) && me->query("env/combat")=="verbose" )
   // tell_object(me, sprintf("combat: 加力效果测试，加力伤害：%d\n", damage));
  

if (damage > 50000)
{
	damage= 45000+(damage-5000)/10;
}
else
{
	if (damage > 40000)
	{
		damage = 40000+random(damage-40000);
	}
}
	

 // if ( wizardp(me) && me->query("env/combat")=="verbose" )
   // tell_object(me, sprintf("combat: 加力效果测试，加力伤害：%d，加力：%d, 输入伤害：%d，内功最大限制倍数：%d\n", damage, factor, damage_bonus, maxpct));
  
  if( damage < 0 ) {
    if( !me->query_temp("weapon")
    &&  random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
      damage = - damage;
      F_KUNGFU->hit_wound( "qi", damage *2, damage, victim, me);
      if( damage < 800 ) return "$N受到$n的内力反震，闷哼一声。\n";
      else if( damage < 1500 ) return "$N被$n以内力反震，「嘿」地一声退了两步。\n";
      else if( damage < 4200 ) return "$N被$n以内力一震，胸口有如受到一记重锤，连退了五六步！\n";
      else return "$N被$n的内力一震，眼前一黑，身子向后飞出丈许！！\n";
    }
    if( damage_bonus + damage < 0 ) 
      return - damage_bonus;
    else
      return damage;
  }

  damage -= victim->query_temp("apply/armor_vs_force");
  if( damage_bonus + damage < 0 ) return - damage_bonus;
  if( random(me->query_skill("force")) < damage )
    return damage*factor*factor/((factor+10)*(factor+10));  //icer added to avoid jiali 1 bug
  else if ( damage <0 )
    return damage;
  else
    return 0;
}

//内功特征定义，不同char_type将有
//char_type: TYPE_RECOVER -- 战斗时exert recover/regenerate的恢复系数，默认100%
//           TYPE_REC_CD -- 战斗时exert recover/regenerate的CD，默认6s
//           TYPE_MIN_SPD -- 任何情况下exert qi/jing加速自然恢复速率的最小倍数，默认400%
//           TYPE_MAX_SPD -- 任何情况下exert qi/jing加速自然恢复速率的最大倍数，默认800%
//           TYPE_SPEED -- 任何情况下exert qi/jing加速自然恢复速率随等级增加的递增系数，默认8
//           TYPE_DEC_SPD -- 任何情况下exert qi/jing对内力的抑制作用，默认33，表示意思是内力恢复效率是原先的0.33
//           TYPE_FORCE -- 内力恢复速度，默认400，意思是有效内功等级每4级提升1点内力恢复
//           TYPE_ENFORCE -- 加力伤害的最高限制，这个值是一个倍数，指的是传入的damage_bonus的一定倍数作为最高限制，一般设置为默认值10
//           TYPE_ENF_NL -- 加力伤害的内力消耗系数，这是一个百分比参数，表示是内力消耗是加力值的百分比，默认值100表示100%
//           TYPE_NEILI -- 决定最大内力和有效内功等级的关系，一般来说是有效内功等级*TYPE_NEILI就是最大内力上限
//           TYPE_JINGLI -- 决定最大精力和有效内功等级的关系，一般来说是有效内功等级*TYPE_JINGLI就是最大精力上限
//           TYPE_SUCK_EFF -- suck类内力的杂质含量，仅suck类内力有定义，值为0-100，表示0%到100%
//           TYPE_SHIELD_DEF -- 内力特效：「护体真气」的防御效果设定，默认是每750级有效内功5%的伤害转换为内力消耗效果
//           TYPE_SHIELD_NEILI -- 内力特效：「护体真气」的内力消耗设定，默认是每秒钟消耗5点内力。
//           TYPE_SPECIAL_NEILI_EFF -- 受特技加内力最大值的影响，正常值100表示100%，设为0就不能通过特技加内力了
//内功特征系数3，4，5的含义是可以如下理解：
//比如特征3定义为min_spd，特征4定义为max_spd，特征5定义为spd，有效内功等级level
//则加速自然恢复速率的倍数实际值是min(min_spd+level/spd,max_spd)
int force_character(string char_type)
{
  switch(char_type)
  {
    case "TYPE_RECOVER":
      return 100;
    case "TYPE_REC_CD":
      return 6;
    case "TYPE_MIN_SPD":
      return 300;
    case "TYPE_MAX_SPD":
      return 600;
    case "TYPE_SPEED":
      return 8;
    case "TYPE_DEC_SPD":
      return 33;
    case "TYPE_FORCE":
      return 400;
    case "TYPE_ENFORCE":
      return 8;
    case "TYPE_ENF_NL":
      return 100;
    case "TYPE_NEILI":   //该参数默认值为10倍，也就是有效内功等级的10倍          
      return 10;
    case "TYPE_JINGLI":  //该参数默认值为10倍，也就是有效内功等级的10倍
      return 10;
    case "TYPE_SUCK_EFF":
      return 0;
    case "TYPE_SHIELD_DEF":
      return 5;
    case "TYPE_SHIELD_NEILI":
      return 5;
	case "TYPE_SPECIAL_NEILI_EFF":  // 受特技加内力最大值的影响，正常值100表示100%，设为0就不能通过特技加内力了
	  return 100;
    default:
      error("错误的内功特征类型："+char_type+"。\n");
  }
}

//计算exert qi/jing加速恢复的时候的恢复倍率
int recover_speed(object me)
{
  string force;
  int min_sp,max_sp,add_sp, speed;
  if ( !objectp(me) )
    return 100;

  force=me->query_skill_mapped("force");
  if ( !stringp(force) )
    return 100;
  
  min_sp=SKILL_D(force)->force_character("TYPE_MIN_SPD");
  max_sp=SKILL_D(force)->force_character("TYPE_MAX_SPD");
  add_sp=SKILL_D(force)->force_character("TYPE_SPEED");
  
  if ( !add_sp )
    add_sp=8;
  
  if ( !min_sp )
    min_sp=300;
  
  if ( !max_sp )
    max_sp=600;

  speed=min_sp+me->query_skill("force")/add_sp;
  if ( speed>max_sp )
    return max_sp;
  else
    return speed;
}

//备份当前内功的内力数据
//输入参数为玩家对象和玩家当前内功的id
//可以在当前内功中设置函数translate将多个存在共性的内功转换为同一id
void backup_neili(object me, string skill_id)
{
  string newsk;
  object ob=this_object();
  
  if ( !stringp(newsk=ob->translate(skill_id)) )
    newsk=skill_id;
  
  //当共享内功的情况下，如果存在内功切换并且切换后的最大内力比之前备份的最大内力低，则不更新备份数据
  if ( newsk!=skill_id && 
       me->query("backup_neili/"+newsk+"/force") && 
       me->query("backup_neili/"+newsk+"/force")!=skill_id && 
       me->query("backup_neili/"+newsk+"/max_neili")>me->query("max_neili") )
    return;
  me->set("backup_neili/"+newsk+"/neili", me->query("neili"));
  me->set("backup_neili/"+newsk+"/max_neili", me->query("max_neili"));
  me->set("backup_neili/"+newsk+"/exercised_neili", me->query("exercised_neili"));
  me->set("backup_neili/"+newsk+"/sucked_neili", me->query("sucked_neili"));
  me->set("backup_neili/"+newsk+"/max_jingli", me->query("max_jingli"));
  me->set("backup_neili/"+newsk+"/jingli", me->query("jingli"));
  me->set("backup_neili/"+newsk+"/limit_neili", me->query_max_neili(1));
  if ( newsk!=skill_id )
    me->set("backup_neili/"+newsk+"/force", skill_id);
}

//恢复当前内功的内力数据
//输入参数为玩家对象和玩家当前内功的id
//可以在当前内功中设置函数translate将多个存在共性的内功转换为同一id
void restore_neili(object me, string skill_id)
{
  string newsk;
  object ob=this_object();
  
  if ( !stringp(newsk=ob->translate(skill_id)) )
    newsk=skill_id;
  
  me->set("neili", me->query("backup_neili/"+newsk+"/neili"));
  me->set("max_neili", me->query("backup_neili/"+newsk+"/max_neili"));
  me->set("exercised_neili", me->query("backup_neili/"+newsk+"/exercised_neili"));
  me->set("sucked_neili", me->query("backup_neili/"+newsk+"/sucked_neili"));
  if ( me->query("max_jingli")<=me->query("backup_neili/"+newsk+"/max_jingli")*120/100 )
    me->set("max_jingli", me->query("backup_neili/"+newsk+"/max_jingli"));
  me->set("jingli", me->query("backup_neili/"+newsk+"/jingli"));
  me->delete("jiali");
//为了防止内力超限，每次恢复数据都要检查当前内力是否超限，超限立刻纠正
  if ( me->query("max_neili")>me->query_max_neili() )
    me->set("max_neili", me->query_max_neili() );
  if ( me->query("max_jingli")>me->query_max_jingli() )
    me->set("max_jingli", me->query_max_jingli() );
}