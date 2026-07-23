// qixinggongyue.c 天罡剑法---七星拱月

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me,object target)
{
        int damage,attack,dodge;
        string msg;
        object ob;
        if( !target ) target = offensive_target(me);

	 if( !target
      	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("七星拱月只能对战斗中的对手使用。\n");


         if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能使用七星拱月。\n");        
                
        if( (int)me->query_skill("quanzhen-jian",1) < 280 )
                return notify_fail("你的全真剑法还不到家，无法使用「七星拱月」！\n");

        if( (int)me->query_skill("xiantian-qigong",1) < 280 )
                return notify_fail("你的先天神功火候不够，无法使用「七星拱月」！\n");
                        
        if( (int)me->query_skill("qixing-array",1) < 200 )
                return notify_fail("你的北斗七星阵功能表火候不够，无法使用「七星拱月」！\n");

    if(me->query_skill_mapped("force") != "xiantian-qigong" )
        return notify_fail("你要把先天神功做为内功才能用。\n");

        if( (int)me->query("neili") < 2000 )
                return notify_fail("你现在内力太弱，不能使用七星拱月。\n");
                        
        if( (int)me->query("jing") < 80 )
                return notify_fail("你的精不足，不能使用七星拱月。\n");

        msg = YEL "$N使出天罡剑法「七星拱月」，脚踏北斗星位，化成七个人影，从七个方位向$n连续攻出七剑。\n"NOR;

        msg +=YEL "上一剑 \n" NOR;

	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
       
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
        }

               
 
        msg += YEL "下一剑 \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
               
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
        }
      

        msg += YEL "前一剑 \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
         }  
	    msg += YEL "后一剑 \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
                
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
        }

        msg += YEL "左一剑 \n" NOR;
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
               
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
        }

	    msg += YEL "右一剑 \n" NOR;        
	
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
                
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;
        }

           msg += YEL "最后一剑 \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);                                      

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"嗤的一声，白影闪处，$p被$P一剑穿胸，惨叫一声，倒在了地上。\n" NOR;
	  } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"可是$p看破了$P的招数，身形几闪，轻而易举的躲过了这一剑。\n" NOR;         
        }
        message_vision(msg, me, target);

        return 1;
}



