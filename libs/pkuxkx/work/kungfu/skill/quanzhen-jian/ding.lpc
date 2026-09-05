// ding.c 全真剑-定阳针
// updated by jpei for xiantian-gong busy

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    object weapon;
    int damage, xtg_ynxf;
    string msg;
    string *jm = ({"手少阴心经","手少阳三焦经","足太阴脾经","足阳明胃经"});

    if ( !target ) target = offensive_target(me);

    if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「定阳针」只能对战斗中的对手使用。\n");

    if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword" )
        return notify_fail("你需要装备 sword 类武器才能使用定阳针的绝招。\n");

    if ( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

    if ( me->query_skill("quanzhen-jian", 1) < 50 )
        return notify_fail("你的全真剑法不够娴熟，不能使用定阳针。\n");

    if (me->query("neili", 1) < 150)
        return notify_fail("你现在内力太弱，不能使用定阳针。\n");

    msg = HIC "$N脚下左弓右箭，神气完足如雷霆五岳，一式「定阳针」斜斜刺出。\n"NOR;

    xtg_ynxf = (me->query_skill("force", "xiantian-gong") > me->query_skill("force", "yunu-xinfa")) ?
       me->query_skill("force", "xiantian-gong") : me->query_skill("force", "yunu-xinfa");
    if (F_KUNGFU->hit_rate(xtg_ynxf, target->query_skill("force"), 9, me, target))
    {
        me->start_busy(2);
        damage = me->query_skill("quanzhen-jian", 1) + me->query_skill("force", 1);
        damage = damage / 2 + random(damage / 2);
        F_KUNGFU->hit_wound("qi", damage, 0, me, target);
        F_KUNGFU->hit_busy("jiemai", 4 + (int)me->query_skill("xiantian-gong", 1) / 30, target);
        me->set_temp("apply/cant_busy_confuse", 1);
        me->set_temp("active_buffer/family", "全真派");
        me->set_temp("active_buffer/quanzhen-jian.ding/name", "定阳针");                      //buff名称
        me->set_temp("active_buffer/quanzhen-jian.ding/last_time", time() + 4 + (int)me->query_skill("xiantian-gong", 1) / 400);   //持续时间
        me->set_temp("active_buffer/quanzhen-jian.ding/effect1", "压制免疫");                   //效果描述1
        call_out("remove_effect", 4 + (int)me->query_skill("xiantian-gong", 1) / 400, me);
        me->add("neili", -300);
        msg += HIR"顿时一股真气透过剑锋冲击$n"HIR"的" + jm[random(4)] + "，$n"HIR"再也无力招架$N"HIR"的剑招！\n"NOR;
    }
    else
    {
        me->start_busy(3);
        msg += CYN"可是$p看破了$P的企图，斜跃避开。\n"NOR;
    }
    message_vision(msg, me, target);
    COMBAT_D->report_status(target);
    return 1;
}

void remove_effect(object me)
{
    if (!me)
        return;
    me->delete_temp("apply/cant_busy_confuse");
    me->delete_temp("active_buffer/quanzhen-jian.ding");
    tell_object(me, HIC"\n你深吸一口气，将内力收回丹田。\n"NOR);
}

