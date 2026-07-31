// chan.c 太极剑法「缠」字诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("瀑布剑法「缠」字诀只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
                
        if( (int)me->query_skill("xuantie-jianfa", 1) < 40 )
                return notify_fail("你的瀑布剑法不够娴熟，不会使用「缠」字诀。\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("你的内力不够。\n");

        msg = HIG "$N使出瀑布剑法「缠」字诀，顿时波涛汹涌，连绵不绝，扰乱了$n的攻势。\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += HIR " 结果$p被$P闹个手忙脚乱，惊慌失措，呆在当场，不知如何应对！\n" NOR;
                target->start_busy( (int)me->query_skill("xuantie-jianfa",1) / 40 + 1 );
        } else {
                msg += "可是$p看破了$P的企图，镇定逾恒，全神应对自如。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
	me->add("neili", - 60);
        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

