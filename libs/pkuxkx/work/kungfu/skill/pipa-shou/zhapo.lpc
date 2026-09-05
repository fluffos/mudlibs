//手挥五弦 by Zine

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    int damage, p;
    object weapon;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("你只能对战斗中的对手使用「银瓶乍破」。\n");

    if( (int)me->query_skill("pipa-shou",1) < 200)
        return notify_fail("你目前功力还使不出「银瓶乍破」。\n");

    if( me->query_temp("shouhuiwuxian") )
        return notify_fail("你刚刚使用过琵琶手特殊攻击。\n");

    if( (int)me->query("neili") < 1000 )
        return notify_fail("你的内力不够。\n");
            
    me->add("neili", - 200);
    msg = HIW"$N不管不顾，双手握合，从中路缓缓推出，\n" + "双手隐隐已有风雷之声，$n大惊失色！\n"NOR;
    me->set_temp("shouhuiwuxian",1);
//D-        
    if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 12, me, target) )
    {
        damage = ((int)me->query_skill("pipa-shou",1) + (int)me->query_skill("hand", 1) + me->query("jiali"))*2;
        damage += random(damage);
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        msg += HIR"只见$N双手画了半个圆，缓缓推进，一式「银瓶乍破」，正中$n胸前要害！\n"NOR;                                                
        me->add("neili", -me->query("jiali"));
        message_combatd(msg, me, target);
        COMBAT_D->report_status(target);
    } 
    else
    {
        msg += HIC "可是$p早有防备，$P完全失去先机。\n" NOR;
        me->add("neili", -me->query("jiali")/2);
        me->add_busy(4);
        message_combatd(msg, me, target);
    }
    me->add_busy(1);
    call_out("remove_wuxian",5+random(6),me);
    return 1;
}

void remove_wuxian(object me)
{
    if (!me) return;
    me->delete_temp("shouhuiwuxian");
}


