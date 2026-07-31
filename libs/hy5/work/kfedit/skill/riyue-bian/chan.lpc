// chan.c 日月鞭法「缠绕」诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    object weapon = me->query_temp("weapon");  
    if( !target ) target = offensive_target(me);

    if( !target
    ||      !target->is_character()
    ||      !me->is_fighting(target) )
        return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

    if (!weapon || weapon->query("skill_type") != "whip"
    || me->query_skill_mapped("whip") != "riyue-bian")
        return notify_fail("你现在无法使用「缠绕」。\n");
	if((int)me->query_skill("hunyuan-yiqi",1) < 50)
		return notify_fail("你混元一气功的功力不够!\n");

    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

    msg = CYN "$N使出日月鞭法「缠绕」诀，连挥数鞭企图把$n的全身缠绕起来。\n";

        me->add("neili", -200);
        me->add("jing", - 40);
        me->start_busy(2);
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
    {
        msg += "结果$p被$P攻了个措手不及ⅵ\n" NOR;
                  	target->receive_damage("qi",(int)me->query_skill("riyue-bian", 1)*3,me);
          	target->receive_wound("qi",(int)me->query_skill("riyue-bian", 1)*3,me);
        target->start_busy( (int)me->query_skill("riyue-bian") / 50 + 2);
    } else {
        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(3);
    }
    message_combatd(msg, me, target);
 
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
    {
 msg = HIR "$N口中高宣佛号，使出日月鞭中「日月」绝技，手中长索滚动飞舞，宛若灵蛇乱颤，自上而下劈向$n,\n" NOR;
	msg += HIR "接着$N手腕一抖，便如张牙舞爪的墨龙相似，急升而上，又往$n扑到。\n";
        message_vision(msg, me, target);
	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 1800);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
   	me->add_temp("apply/attack", -100);	
	me->add_temp("apply/damage", -1800);
}

    return 1;
}

