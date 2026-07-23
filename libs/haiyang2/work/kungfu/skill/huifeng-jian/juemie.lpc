// juemie 灭星绝
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int extra;
        int count;
                int damage;
int finger, skill, jiali, my_rate, your_rate, neili_cost, jingli_cost;
 	if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("只能在战斗中使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("开始时必须拿着一把剑！\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("jinding-zhang", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("huifeng-jian", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("linji-zhuang", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "linji-zhuang")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通峨嵋派武学，使出了峨嵋派的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
if (random(3)==0) target->start_busy(3);
	extra = me->query_skill("huifeng-jian",1) / 15;
	extra += me->query_skill("linji-zhuang",1) /15;
 
        msg = YEL "$N使出回风拂柳剑绝技「一剑化三清」，一招连环三剑，手中的"+ weapon->name()+  "闪电般攻出第一剑！" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", extra*2);
        me->add_temp("apply/damage", extra*4);
        msg = HIY "只见$N右手一抖，"+ weapon->name()+ HIY"划向$n的左肩！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/3 )
        {                
        msg = HIW "第一道剑气"+HIR+"击向$n周身，$n只觉得全身气脉通道阻塞，真气立受干挠！\n"NOR;   
        message_vision(msg, me, target);
  if( !target->is_busy() )
{
        target->start_busy(2);
}
        }
        msg =  HIW "$N凌空一劈，"+ weapon->name()+ GRN"削向$n的右肩！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/3 )
        {                
        msg = HIC "第二道剑气"+HIM+"扫中$n的身上,$n只觉得全身一阵急痛！\n"NOR;   
                message_vision(msg, me, target);
        target->add("jing",-extra);
        target->add("eff_jing",-extra);
        }
        msg = CYN "$N长啸一声，聚功力于左手，使出剑法的最高境界--灭剑，朝$n的胸前劈去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/3 )
        {                
        msg = MAG "最后一道剑气"+HIB+"扫中$n的章门穴,$n只觉得全身内力提不起来了！\n"NOR;   
        message_vision(msg, me, target);
        target->add("neili",-extra*4);
        target->add("eff_neili",-extra*4);
        }
        me->add_temp("apply/attack", - extra*2);
        me->add_temp("apply/damage", - extra*4);
        me->start_busy(4);

        msg = YEL "$N手中长剑剑芒跃动，剑光暴长，幻出死亡的色彩，剑尖渐渐逼近$n，\n"NOR;
        msg += YEL"$n看到漫天剑光，抽身后跃，只这一刹，漫天剑影化为一剑直刺$n前胸，"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("combat_exp"))+5000 > target->query("combat_exp")/2) {  
    msg += HIM"\n$p只觉得浑身一热，手掌虎口巨痛，手中"
                + target->query_temp("weapon")->query("name") + "脱手而出。\n" NOR;
		message_vision(msg, me, target);
		(
		target->query_temp("weapon"))->move(environment(target));
	} else {
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
		message_vision(msg, me, target);
          message_vision(HIW "但$N飘身而起，使出峨嵋绝技「灭剑」心法，顿时剑意空灵飘逸，似万千柳絮飞舞，又如和风阵阵
拂过。$n惊骇之下，顿时出招散乱，无从招架！\n" NOR, 
                         me, target);
	}
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 
        || random(me->query("combat_exp"))+8000 > target->query("combat_exp")/4 )
	{
		
		damage = (int)me->query_skill("huifeng-jian", 1);
		
		damage = damage*6 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n结果$n脸色被一剑击中，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果一剑击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，一剑穿心,$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，一剑穿心,$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		
	} else 
	{
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
	message_vision(msg, me, target);
            message_vision(HIW "但$N飘身而起，使出峨嵋绝技「灭剑」心法，顿时剑意空灵飘逸而，似万千柳絮飞舞，又如和风阵阵
拂过。$n虽已加倍提防，但仍感攻势频频收挫。\n" NOR, 
me, target);
        target->add("jing",-extra);
        target->add("eff_jing",-extra/2);
        target->add("qi",-extra);
        target->add("eff_qi",-extra/2);
	}
	message_vision(msg, me, target);

        }
 msg = HIY "\n$N突然间全身骨骼中发出劈劈拍拍的轻微爆裂之声，炒豆般的响声未绝，右掌已向$n胸口击去。\n\n"NOR;
  msg += HIG"这一掌是峨嵋派的绝学，叫做“佛光普照”。这“佛光普照”的掌法便只一招，而且这\n";
  msg += HIG"一招也无其他变化，招式平平淡淡，一成不变，可是其威力之生，就在于以峨嵋派绝顶\n";
  msg += HIG"内功作为根基。一掌既出，内力如排山倒海一般袭来，敌人挡无可挡，避无可避。\n\n";

// because hy2 can not jiajin, so update jiajin to jiali (by xbd)
  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")*2 ) || !living(target) )
  {
                        damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
                        if(damage > 8100) damage = 8100;
                        if(damage < 500) damage = 500;
//                        me->add("jing", -me->query("jiajin")/2);

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage), me);

                msg += HIR"猛听得砰然一声大响，$N已打中在$p胸口.\n"NOR;
                if ( damage < 400) {
                        msg += HIC"$n身子一晃，立足不定，差点儿就要摔倒。\n"NOR;
                }else if ( damage < 600) {
                        msg += HIR"$n向后接连摔了两个筋斗，哇的一声，喷出一口鲜血。\n"NOR;
                }else if ( damage < 1000) {
                        msg += YEL"$n哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥。\n"NOR;
                }else if ( damage < 2000) {
                        msg += RED"$n身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷．\n"NOR;
                }else if ( damage < 3000) {
                        msg += RED"只听一声巨响，$n口中鲜血狂喷，全身骨骼碎裂。\n"NOR;
                }else {
                        msg += RED"只听一声巨响，$n全身骨骼碎裂，竟被这排山倒海般的一击将身子打成了两截。\n"NOR;
                }
                msg += NOR;
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
                                &&  random(target->query_skill("dodge")) < random( me->query_skill("strike") )  )
  {
                        damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
                        damage = damage / 2+600;
                        if(damage > 9000) damage = 9000;
                        if(damage < 350) damage = 350;

//                        me->add("jing", -me->query("jiajin")/2);

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage), me);

                        msg += HIY"$p眼看这一招来势汹汹，知道难于对付，连忙发力抵抗，猛听得砰然一声大响，$N已打中在$p胸口.\n"NOR;
                if ( damage < 400) {
                        msg += HIC"$n身子一晃，立足不定，差点儿就要摔倒。\n"NOR;
                }else if ( damage < 600) {
                        msg += HIR"$n向后接连摔了两个筋斗，哇的一声，喷出一口鲜血。\n"NOR;
                }else if ( damage < 1000) {
                        msg += RED"$n哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥。\n"NOR;
                }
                else msg += RED"$n身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷．\n"NOR;

                msg += NOR;
                target->add( "neili", -damage/4 );
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) &&
          random( target->query_skill("dodge")*2 ) > random( me->query_skill("strike") ) )
  {
                        damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
                        damage = damage / 3;
                        if(damage > 6000) damage = 6000;
                        if(damage < 550) damage = 550;

//                        me->add("jing", -me->query("jiajin")/2);

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage), me);

                        msg += HIM"$p眼看这一招来势汹汹，慌忙使出本门身法，向侧跃出数丈，可是这佛光普照蕴藏峨眉内家上乘内功，\n";
                        msg += "方圆数丈都被神功所震撼，$p只觉得后心一震，已被劈空掌力所伤.\n"NOR;
                if ( damage < 400) {
                        msg += HIC"$n身子一晃，立足不定，差点儿就要摔倒。\n"NOR;
                }else if ( damage < 600) {
                        msg += HIR"$n向后接连摔了两个筋斗，哇的一声，喷出一口鲜血。\n"NOR;
                }else if ( damage < 1000) {
                        msg += RED"$n哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥。，\n"NOR;
                }
                else msg += RED"$n身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷．\n"NOR;

                msg += NOR;
                target->add( "neili", -damage/4 );
  }
  else {
         msg += HIC"$n眼看这一招来势汹汹，使出本门身法，向後跃出数丈，\n\n"NOR;
         msg += HIW"$N这一招乃是使上了全力，丝毫不留余地。没想到全无用处，不觉脸如死灰，手掌微微发抖。\n" NOR;
         neili_cost = jiali*3;
//         jingli_cost = me->query("jiajin")*2;
         if(neili_cost > me->query("neili")) 
                neili_cost = me->query("neili");
         if(jingli_cost > me->query("jingli"))
                jingli_cost = me->query("jingli")-1;

         message_vision(msg+"\n", me, target);
         return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
        return 1;
}

