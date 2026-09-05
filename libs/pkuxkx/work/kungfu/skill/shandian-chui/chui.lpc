#include <ansi.h>
#include <combat.h>

#define CHUI "「" HIG "千斤锤" NOR "」"

inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    int damage;
    string msg;
    int ap, dp;
    object weapon1;
    
    if ( !target ) target = offensive_target(me);

    if ( !objectp(target) || ! me->is_fighting(target) )
        return notify_fail(CHUI "只能对战斗中的对手使用。\n");

    if ( !living(target) )
        return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

    weapon1 = me->query_temp("weapon");

    if ( !objectp(weapon1) || weapon1->query("skill_type") != "hammer" )
        return notify_fail("你必须在使用锤类兵器时才能使"+CHUI+"！\n");
            
    if( me->query_skill("shandian-chui",1) < 80 )
        return notify_fail("你的日月闪电锤级别太低，不够使用"+CHUI+"\n");

    if ( me->query_skill("force") < 80)
        return notify_fail("你的内功修为不够，难以施展" CHUI "。\n");

    if ( (int)me->query("neili") < 300 )
        return notify_fail("你现在的真气不够，难以施展" CHUI "。\n");

    ap = me->query_skill("hammer", "shandian-chui");
    dp = target->query_skill("parry");

    msg = HIC "\n$N" +weapon1->query("name")+HIC "挥出，施一招「" HIG "千斤锤"
          HIC "」，速度奇快，" HIC "直袭$n" HIC "胸口。\n" NOR;
    
    message_vision(msg, me, target);

    if ( F_KUNGFU->hit_rate( ap, 2*dp-ap, 9, me, target) )
    {
        damage = (int)me->query_skill("shandian-chui", 1);
        damage += random(damage / 2);
        damage +=(int)me->query_temp("apply/damage")/2;
        damage +=(int)me->query("jiali")/5;
        if ( me->query("riyuepfm/chui") && me->query("family/family_name")=="日月神教" )
            damage+=(int)me->query("jiali")/4;
        msg = HIR "$N" HIR "出手既快，方位又奇，$n"+HIR "闪避不及，闷哼一声，已然中招。\n" NOR;
        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);                
        me->add("neili", -100);
        me->start_busy(2 + random(2));                                         
    } 
    else
    {
        msg = CYN "$n" CYN "不慌不忙，以快打快，将$N"
              CYN "这招化去。\n" NOR;
        me->add("neili", -30);
        me->start_busy(2 + random(3));
    }
    message_vision(msg, me, target);
    COMBAT_D->report_status(target);
    return 1;
}
