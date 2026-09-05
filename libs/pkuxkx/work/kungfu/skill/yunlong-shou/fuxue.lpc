
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;

    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

    if( me->query_skill("hand") < 100 )
        return notify_fail("云龙手拂穴需要有效手法 100 级。\n");
    if( me->query("neili") < 100 )
        return notify_fail("云龙手拂穴需要内力 100 以上。\n");
        
    msg = HIY "$N使出云龙手绝技「拂穴」，罩住了$n的全身要穴。\n";
    me->add("neili", - 100);
	if( (int)target->query_temp("hmg_yixue") )
		{
			me->start_busy(3);
			msg += HIR "$P一指点中，心中正自高兴，不料$p早将经脉移位，这一指毫无效果。\n" NOR;	
			message_vision(msg, me, target); 
		}

    else if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
        msg += "结果$p被$P一击点中。\n" NOR;
        target->start_busy(5 + random(6));
    }
    else
    {
        me->start_busy(4);
        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
    }
    message_vision(msg, me, target);
    // 最后再叫杀，使得信息显示更合理
    if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
    if( !me->is_fight(target) ) me->fight_ob(target);
    
    return 1;
}
