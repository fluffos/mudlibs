// chan.c 

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        object weapon;
		int mz_rate=9;

        if( !target ) target = offensive_target(me);
        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
            return notify_fail("「缠绕」只能对战斗中的对手使用。\n");
        
        if( target->is_busy() )
            return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "whip" )
            return notify_fail("你需要装备whip类武器才能使用缠绕的绝招。\n");

        if((int)me->query_skill("changhen-bian",1 ) < 100)
            return notify_fail("你的长恨鞭法等级不够，不能使用缠绕制敌。\n");
        
        if ((int)me->query_skill("yunu-xinfa", 1) < 100)
		    return notify_fail("你的玉女心法火侯太浅。\n");
		if ((int)me->query_skill("yunu-xinfa", 1) < 250)
			mz_rate += 1;

        if ( !wizardp(me) && me->is_busy() ) 
			return notify_fail("你正忙着呢。\n");

        if( (int)me->query("neili") < 400  ) 
                return notify_fail("你的内力不够。\n");

        msg = CYN "$N使出长恨鞭法「缠绕」诀，连挥数鞭企图把$n的全身缠绕起来。\n" NOR;

        me->start_busy(2);
//命中率C-||C-，更准确的命中率级别应该是B-
        if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), mz_rate, me, target)
         || F_KUNGFU->hit_rate(me->query_int(), target->query_int(), mz_rate, me, target) ) 
        {
                msg += HIR "结果$p被$P攻了个措手不及！\n" NOR;
                F_KUNGFU->hit_busy( "body", (int)me->query_skill("changhen-bian")/(11+mz_rate)+3, target );
        } else {
                msg += HIC "可是$p看破了$P的企图，并没有上当。\n" NOR;
        }
        me->add("neili", -100);
        message_vision(msg, me, target);

        return 1;
}


