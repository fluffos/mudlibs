//leiting.c -雷霆降龙

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        int damage, kar, level;

        if( !target ) target = offensive_target(me);

        if( !me->query("leiting"))
                return notify_fail("你的外功中没有这种功能。\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「雷霆降龙」只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) || objectp(me->query_temp("secondary_weapon")))
                return notify_fail("你必须空手才能施展「雷霆降龙」！\n");

 	if (me->query_skill("force",1)/2 + me->query_skill("huntian-qigong",1) < 135 )
                return notify_fail("你的内功等级不够，无法施展「雷霆降龙」。");

        if (me->query_skill("strike",1)/2 + me->query_skill("xianglong-zhang", 1) < 135 )
                return notify_fail("你的降龙十八掌等级不够，施展不出「雷霆降。\n");

      	if (me->query("neili")< 400 || me->query("max_neili") < 200)
                return notify_fail("你的内力不够，无法施展「雷霆降龙」。");
        msg = RED "$N全身暴长，纵身越起，一式「雷霆降龙」，奋力扑向$n。";

	kar = me->query("kar") / 10;
	damage = me->query_skill("xianglong-zhang", 1);
	level = me->query_skill("xianglong-zhang", 1) / 50;
	damage = damage * 5 / 2;
	me->start_busy(3);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3)
	{
                msg += "结果$p被$P攻了个措手不及！\n" NOR;
                if (random(100) < 1 + kar + level)
                {//特效：critical strike
                	damage = damage * 2;
                	msg += HIR"$P在一瞬间臂力爆增，掌风带着强烈的内劲重击在$p的$l\n"NOR;
                	me->add("neili", - 100));
                }
                message_vision(msg, me, target);
                target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage / 2, me);
		me->add("neili", - 100));
        } else {
                msg += "可是$p还是躲过了$P的最后一击！！\n" NOR;
                message_vision(msg, me, target);
		me->set("neili",(me->query("neili")-200));
        }
        return 1;
}
