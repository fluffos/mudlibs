#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("破煞只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("dafumo-quan", 1) < 200 )
                return notify_fail("你的大伏魔拳不够娴熟，无法使用破煞。\n");
        if( (int)me->query_skill("jiuyin-zhengong", 1) < 200 )
                return notify_fail("你的九阴真功不够娴熟，无法使用破煞。\n");

        if ( (int)me->query("max_neili") < 6000)
                return notify_fail("你的真气不够，无法使用破煞。\n");

        if ( (int)me->query("neili") < 10000)
                return notify_fail("你的内力不够，无法使用破煞。\n");

        msg = HIY"$N突然眼睛一闪，猛吸一口气，使出全身的力气出拳向$n击去！\n";
        me->start_perform(10,"破煞");
	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
                msg += HIR"$n躲闪不及，正中小腹！$n只觉得一股强极的九阴真气猛向自己丹田冲击！\n";
                msg += HIR"$n只觉得丹田有如刀割，内息直向体外冲出！\n"NOR;
                target->add("max_neili",-(random(me->query_skill("dafumo-quan",1)/20)+5));
                target->set("neili",0);
                target->set("jiali",0);
                me->set("neili", 0);
                me->set("jiali", 0);
        } 
        else {
                msg += HIG"$n见来势猛烈，连忙避在一旁。\n" NOR;
        }
        message_vision(msg, me, target);
        me->start_busy(3+random(3));
}else
{
        if( random(me->query("combat_exp")) > target->query("combat_exp")/3 ) {
                msg += HIR"$n躲闪不及，正中小腹！$n只觉得一股强极的九阴真气猛向自己丹田冲击！\n";
                msg += HIR"$n只觉得丹田有如刀割，内息直向体外冲出！\n"NOR;
                target->add("max_neili",-(random(me->query_skill("dafumo-quan",1)/20)+5));
                target->set("neili",0);
                target->set("jiali",0);
                me->set("neili", 0);
                me->set("jiali", 0);
        } 
        else {
                msg += HIG"$n见来势猛烈，连忙避在一旁。\n" NOR;
        }
        message_vision(msg, me, target);
        me->start_busy(3+random(3));
}
        return 1;
}

