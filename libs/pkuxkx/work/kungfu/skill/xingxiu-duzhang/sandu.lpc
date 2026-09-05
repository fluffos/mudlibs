//sandu.c
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    string msg;
    int level, damage, pflv;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「散毒」只能对战斗中的对手使用。\n");

    if (me->query_skill("force", "huagong-dafa") < 150)
        return notify_fail("有效内功等级 150 以上才能施展「散毒」。\n");

    if (me->query_skill("strike", "xingxiu-duzhang") < 150)
        return notify_fail("有效掌法等级 150 以上才能散毒\n");

    if (me->query("neili") < 300)
        return notify_fail("内力 300 以上才能散毒。\n");
	
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "星宿派") 
		pflv=0;

    msg = HIB "$N积聚全身剧毒奋力击向$n。\n";
    message_vision(msg, me, target);
    msg = "";
    me->add("neili", -200);
    level = me->query_skill("strike", "xingxiu-duzhang");
//命中率级别C-
    if (F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 9-((pflv>=3)?(pflv-2):0), me, target))
    {
        msg += "结果$p被$P一击命中，$P的剧毒散至$p的全身！\n" NOR;
        damage = level * 2;
        if (!target->is_busy())
            target->start_busy(2);
        F_KUNGFU->hit_wound("qi", damage, damage / 2, me, target);
        damage = level / 2;
        F_KUNGFU->hit_wound("jing", damage, damage / 2, me, target);
        //target->set_temp("death_cond_origin/xx_poison", me);
		F_POISON->poison_attack(me,target,"xx_poison", 10 + target->query_condition("xx_poison"));
		if (pflv>=4)
			F_POISON->poison_attack(me,target,"xxx_poison", 10 + target->query_condition("xxx_poison"));
		if (pflv>=5)
			F_POISON->poison_attack(me,target,"xx-poison-palsy", 10 + target->query_condition("xx-poison-palsy"));
        message_vision(msg, me, target); 
        COMBAT_D->report_status(target);
    }
    else
    {
        msg += "可是$p还是躲过了$P的致命一击！！\n" NOR;
        message_vision(msg, me, target);
    }

    me->start_busy(2);
    target->kill_ob(me);
    return 1;
}

