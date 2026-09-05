// zhen.c 太极拳「震」字诀

#include <ansi.h>
#include <combat.h>
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

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("神功震敌只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("taiji-quan", 1) < 30 )
                return notify_fail("你的太极拳不够娴熟，不会使用「震」字诀。\n");

        if( (int)me->query_skill("taiji-shengong", 1) < 30 )
                return notify_fail("你的太极神功不够高，不能用来反震伤敌。\n");

        if( (int)me->query("neili", 1) < 100 )
                return notify_fail("你现在内力太弱，不能使用「震」字诀。\n");

        msg = HIC "$N"HIC"默运神功，使出太极拳「震」字诀，企图以内力震伤$n"HIC"。\n"NOR;
//命中率级别C-级别
        if ( F_KUNGFU->hit_rate( me->query_skill("force", "taiji-shengong"), target->query_skill("force"), 9, me, target) ){
                me->start_busy(1);
                damage = (int)me->query_skill("taiji-quan");
                damage += random(damage);
                F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
                me->add("neili", -damage/10);
                if( damage < 60 ) msg += HIY"结果$n"HIY"受到$N"HIY"的内力反震，闷哼一声。\n"NOR;
                else if( damage < 120 ) msg += HIY"结果$n"HIY"被$N"HIY"以内力反震，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 240 ) msg += RED"结果$n"RED"被$N"RED"以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else msg += HIR"结果$n"HIR"被$N"HIR"的内力一震，眼前一黑，身子向后飞出丈许！！\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        } else {
                me->start_busy(1);
                msg += CYN"可是$p"CYN"看破了$P"CYN"的企图，并没有上当。\n"NOR;
                message_vision(msg, me, target);
        }

        return 1;
}

