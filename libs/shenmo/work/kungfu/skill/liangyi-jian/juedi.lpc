// juedi.c 绝地逢生
// 1997.9.2   csy

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("绝地逢生只能对战斗中的对手使用。\n");

                
    if( (int)me->query_skill("liangyi-jian",1)<180)
    return notify_fail("你的正两仪剑法不够娴熟，不会使用「绝地逢生」。\n");
     if( (int)me->query_skill("xuantian-wuji",1)<80)
        return notify_fail("你的玄天无极功不够深厚，不会使用「绝地逢生」。\n"); 
                        
    if( (int)me->query("neili",1)<500)
    return notify_fail("你现在内力太弱，不能使用「绝地逢生」。\n");
 if (random(2)==0) target->start_busy(2);
    if( (int)me->query_skill("art", 1) > 120 )
    {
    msg = HIC"$n看到剑光偏左，疾侧身右转，但只这一刹，剑光刹时袭向右首！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$n看到剑光偏右，疾侧身左转，但只这一刹，剑光刹时袭向左首！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$n看到剑光偏上，疾侧身下转，但只这一刹，剑光刹时袭向下身！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$n看到剑光偏下，疾侧身上转，但只这一刹，剑光刹时袭向上身！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -200);
    }
                        
 msg=HIY "$N衣衫无风自动，使出昆仑派两仪剑法中的震山绝技「绝地逢生」。\n"
HIG "刹那间天昏地暗，飞沙走石，无数剑影向$n的全身要害或刺，或砍，或劈而去。\n" NOR;

        if (random(me->query("neili")) > target->query("neili")/3 )
{
        me->start_busy(2);
                target->start_busy(random(4));
                
    damage= (int)me->query_skill("liangyi-jian",1);
         damage = damage + random(damage);
                
        target->receive_damage("qi",random(damage)+200);
        target->receive_wound("qi",damage*2+200);
        me->add("neili",-damage/5);
        if( damage < 20 ) msg += HIY"结果$n被$N刺中了一剑，闷哼一声。\n"NOR;
else
if( damage < 55 ) msg += HIY"结果$n被$N连刺两剑，「啊」地一声退了两步。\n"NOR;
else if( damage < 80 ) msg += RED"结果$n被$N重重的连砍数剑，有如受到数记雷击一般，连退了五六步！\n"NOR;
else msg += HIR"结果$n被$N的「绝地逢生」剑透前心，眼前一黑，身子向后飞出丈许！！\n"NOR;
}
else
{
         me->start_busy(2);
                msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
}
        message_vision(msg, me, target);

        return 1;
}


