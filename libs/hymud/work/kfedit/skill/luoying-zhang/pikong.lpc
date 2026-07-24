// pikong.c By Darken
// Modified by Numa@Sj 99-11-12 2:46

inherit F_SSERVER;
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h"

int perform(object me, object target)
{
        object ob;
        int damage, p;
        string msg;
        if( !target ) target = offensive_target(me);        
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("劈空掌绝技只能对战斗中的对手使用。\n");
        if(!objectp(ob = present(target, environment(me))))
                return notify_fail("这里没有你想劈的这个人。\n");
        if(ob==me)
                return notify_fail("你不能攻击自己。\n");

        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用劈空掌！\n");   
        if( environment(me)->query("no_fight") )
                return notify_fail("这里不能战斗。\n");
        if( (int)me->query_skill("qimen-wuxing", 1) < 60 )
                return notify_fail("你的奇门八卦不够娴熟，无法施展出奇门玉箫。\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 60)
                return notify_fail("你的碧波神功生功火候不够，无法施展出奇门玉箫。\n");
        if( (int)me->query_skill("luoying-zhang",1) < 120 )
                return notify_fail("你的掌法修为不足，使不出劈空掌。\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("你现在内力太弱，不能打出劈空掌。\n");
        msg = HIB "$N长啸一声，一式劈空掌向$n击到，挟带著澎湃汹涌的碧海潮生功，其势殊不可挡！\n"NOR;
        if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
        {
                me->start_busy(2);
                damage = (int)me->query_skill("bibo-shengong", 1) + (int)me->query_skill("luoying-zhang", 1);
                damage = damage*3+random(damage/2);
if (damage > target->query("qi")/2)
damage=(int)target->query("qi")/2;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                me->add("neili", -damage/3);
                msg += HIG"$n被这凌空掌力一撞，如受大浪冲击，口中鲜血狂喷，身子如同断线风筝般飞出！\n"NOR;
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
        }
        else {
                me->start_busy(1);
                me->add("qi",-150);
                msg += CYN"$n见掌势猛烈，急忙向旁一让，$N这一掌便即落空。\n"NOR;
        }
        message_vision(msg, me, target);
        me->start_perform(1,"劈空掌");
        return 1;
}
