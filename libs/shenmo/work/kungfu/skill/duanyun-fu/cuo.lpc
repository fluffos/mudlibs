#include <ansi.h>
#include <combat.h>

#define CUO "「" HIR "错字诀" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int level,ap,dp;
	string msg;
        int i, attack_time;
 
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CUO "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "axe")
                return notify_fail("你使用的武器不对，难以施展" CUO "。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

    if( (int)me->query_skill("duanyun-fu",1) < 70)
    return notify_fail("你目前功力还使不出「错字诀」。\n");
    
        if ((int)me->query_skill("force") < 120)
                return notify_fail("你的内功火候不够，难以施展" CUO "。\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("你的内力修为不够，难以施展" CUO "。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你现在真气不够，难以施展" CUO "。\n");


        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "高举手中" + weapon->name() + HIR "，陡然一声断喝，朝着$n"
              HIR "猛挥数斧，气势如虹。\n" NOR;

        ap = me->query("combat_exp");
        dp = target->query("combat_exp");
        level=me->query_skill("duanyun-fu",1);
        me->add("neili", -30);
        if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "$p" HIR "见$P" HIR "来势汹涌，不得不中途"
                       "变招，这一下登时便失了先机！\n" NOR;
                target->start_busy(level / 50 + 3);
	} else
        {
		msg += CYN "可是$p" CYN "看破$P" CYN "招式的来路，斜"
                       "斜跳开，使这招未起到丝毫作用。\n" NOR;
		me->start_busy(2);
	}
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 )
         {
         attack_time = random((int)me->query_skill("duanyun-fu", 1) / 10);
if (attack_time > 7) attack_time=7;
        message_combatd(msg, me, target);
        for(i = 0; i < attack_time; i++){
         msg = HIR "$N双斧连环，狂劈乱砍！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                                        }
         }
                me->start_busy(3);

	return 1;
}
