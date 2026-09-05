//左右互搏
//modified by whuan@pkuxkx

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    string msg;
    int damage;
    object weapon;

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
         !me->query("zuoyou-hubo"))
        return notify_fail("你所使用的外功中没有这项功能");

    if (!target) target = offensive_target(me);

    if (!objectp(target) || !target->is_character() || !me->is_fighting(target))
        return notify_fail("「左右互搏」只能对战斗中的对手使用。\n");

    if ( me->query_temp("can_zyhb") )
        return notify_fail("你已经在施展「左右互搏」了。\n");

    if ((int)me->query_skill("kongming-quan", 1) < 150)
        return notify_fail("你的空明拳火候不足, 怎能分心互博？\n");

    if (me->query_skill_mapped("cuff") != "kongming-quan")
        return notify_fail("你必须使空明拳才能施展「左右互搏」。\n");

    if ( me->check_hand()>=1 )
        return notify_fail("你必须双手空手才能施展「左右互搏」。\n");

    if ((int)me->query("neili") < 500)
        return notify_fail("你的内力不够，无法施展「左右互搏」。\n");

    msg = HIR "$N" + HIR"默运玄功，灵台顿时一片空明，使出「左右互搏」，两手各使一招空明拳，闪电般攻向$n"HIR"！\n" NOR;
    me->set_temp("can_zyhb", 1);
    call_out("remove_effect", me->query_con(), me);
    me->set_temp("active_buffer/family", "全真派");
    me->set_temp("active_buffer/kongming-quan.hubo/name", "左右互搏");                      //buff名称
    me->set_temp("active_buffer/kongming-quan.hubo/last_time", time() + me->query_con());   //持续时间
    me->set_temp("active_buffer/kongming-quan.hubo/effect1", "左右互搏");                   //效果描述1
    damage = me->query_skill("kongming-quan", 1) * 2;
//命中率级别B-
    if (F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target))
    {
        msg += MAG "$N拳出如风，$n霎时间眼中尽是$N的拳影，不觉已身中数拳，“哇”的一声喷出一口鲜血！\n"NOR;
        me->start_busy(1 + random(2));
        F_KUNGFU->hit_wound("qi", damage, damage / 2, me, target);
    }
    else
    {
        me->start_busy(3);
        msg += HIG "可是$n看破了$N的企图，轻松闪开。\n" NOR;
        me->add("neili", -100);
    }
    message_vision(msg, me, target);
    COMBAT_D->report_status(target);
    return 1;
}


void remove_effect(object me)
{
    if (!me) return;
    me->delete_temp("can_zyhb");
    me->delete_temp("active_buffer/kongming-quan.hubo");
    if ( sizeof(me->query_temp("active_buffer"))==1 )
        me->delete_temp("active_buffer");
    tell_object(me, HIC"\n你深吸一口气，将内力收回丹田。\n"NOR);
}

