#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage;
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

      msg = HIR "$N双拳连环，瞬息间连出七拳，分击$n全身，正是大金刚拳绝技「七星聚会」。\n" NOR;

        message_vision(msg, me, target);
        me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 3000);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
              msg = HIR "$N一拳既出，身形一转，闪至$n左侧，双拳并举，同时打到。\n" NOR;
        message_vision(msg, me, target);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              
              msg= HIR "$N双拳势若暴风骤雨，连击$n肩、臂、胸、背各个部位，快得难以形容。\n" NOR;
        message_vision(msg, me, target);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -3000);
        
        msg = HIY"$N突然眼睛一闪，猛吸一口气，使出全身的力气出拳向$n击去！\n";
        //me->start_perform(10,"破煞");

	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
	damage=target->query("neili")/2;
	if (damage>30000) damage=30000;
                msg += HIR"$n躲闪不及，正中小腹！$n只觉得一股强极的九阴真气猛向自己丹田冲击！\n";
                msg += HIR"$n只觉得丹田有如刀割，内息直向体外冲出！\n"NOR;
                target->add("max_neili",-(random(me->query_skill("dafumo-quan",1)/20)+5));
                target->add("neili",-damage);
                //target->set("jiali",0);
                me->add("neili", -100);
                //me->set("jiali", 0);
        } 
        else {
                msg += HIG"$n见来势猛烈，连忙避在一旁。\n" NOR;
        }
        message_vision(msg, me, target);
        me->start_busy(2);
 me->add("neili", -100);
        return 1;
}

