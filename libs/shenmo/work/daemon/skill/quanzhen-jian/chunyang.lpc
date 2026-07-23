// sanqing.c 一剑化三清

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count,damage,attack,dodge;
 	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
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

       if( !wizardp(me) &&(int)me->query_skill("qixing-array", 1) < 400 )
		return notify_fail("你的本门阵法不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("quanzhen-jian", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("xiantian-qigong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "xiantian-qigong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通全真武学，使出了全真的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
if (random(3)==0) target->start_busy(5);
        msg = YEL "$N使出全真派绝技「一剑化三清」，身法陡然加快,手握剑柄晃成三条白龙！" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", (int)me->query_skill("quanzhen-jian",1)/2);
        me->add_temp("apply/damage", (int)me->query_skill("quanzhen-jian",1)/3);

       msg = WHT  "赤血白龙！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT  "化血白龙！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT "怒血白龙！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query_skill("qixing-array",1)>80)
{
        msg = HIG "回形天罡！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>150)
{
        msg = HIG "七星移位！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>200)
{
        if (random(me->query("combat_exp")) > target->query("combat_exp")/2 )
        {
        message_vision(HIW"\n$N脚走七星,围着$n连走数个圈，$n只觉一阵眼花！\n"NOR,me,target);
//         msg = HIY "$N脚走七星,围着$n连走数个圈，$n只觉一阵眼花！" NOR;              
  if( !target->is_busy() )
{
         target->start_busy(2);
}
}

}

        me->add_temp("apply/attack", - (int)me->query_skill("quanzhen-jian",1)/2);
        me->add_temp("apply/damage", - (int)me->query_skill("quanzhen-jian",1)/3);
        msg = YEL "$N使出天罡剑法「七星拱月」，脚踏北斗星位，化成七个人影，从七个方位向$n连续攻出七剑。\n"NOR;

        msg +=YEL "上一剑 \n" NOR;

	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;

                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
        } else 
        {
       
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
        }

               
 
        msg += YEL "下一剑 \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {

                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
               
        } else 
        {

	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
        }
      

        msg += YEL "前一剑 \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {

                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);

	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
        } else 
        {
	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
         }  
	    msg += YEL "后一剑 \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);

	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
                
        } else 
        {
	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
        }

        msg += YEL "左一剑 \n" NOR;
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
               
        } else 
        {
	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
        }

	    msg += YEL "右一剑 \n" NOR;        
	
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {

                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
                
        } else 
        {
	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
        }

           msg += YEL "最后一剑 \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);                                      

        if (random(attack) > dodge/2 )
        {
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);

	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
	  } else 
        {
	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;         
        }
        message_vision(msg, me, target);
 	msg = MAG "$N一声长啸，一抖手中剑，顿时形成一道剑幕，狂风暴雨般压向$n。就在
$n慌乱之间，剑幕中飞出七朵寒星，如流星般射向$n。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += "$n躲闪不及，已然中剑！\n";
		damage = 4*(int)me->query_skill("quanzhen-jian", 1);
		damage = damage / 2 + random(damage / 2);
		target->receive_wound("qi", damage/3);
	 	if( damage < 40 ) msg += HIY"$n已身中数剑，身上到处是血。\n"NOR;
         	else if( damage < 80 ) msg += HIR"$n身中七剑，鲜血狂喷而出！\n"NOR;
         	else msg += RED"$n“哇”的狂叫一声，身上喷出七道血剑！\n"NOR;
		message_vision(msg, me, target);
	} 
	else {
	 	msg += HIW"$n情急之中向后激飞，随机趴下，堪堪躲过了这致命一击。\n" NOR;
		message_vision(msg, me, target);
	}
        me->start_busy(4);

        return 1;
}

