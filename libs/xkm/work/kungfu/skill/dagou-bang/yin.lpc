// dagou-bang yin.c
// liu 2002

/*
黄蓉大怒，提起竹棒迎面直点。
柯镇恶还了一杖，哪知打狗棒法神妙绝伦，数招一过，铁杖已被黄蓉用“引”字诀拖住，
跟着她竹棒挥舞，棒东杖东，棒西杖西，全然不得自由。
*/

#include <ansi.h>

inherit F_SSERVER;

void yin(object me,object target);

int perform(object me, object target)
{
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
		||      !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

        if( me->query_skill_mapped("force") != "huntian-qigong")
                return notify_fail("你所用的内功与打狗棒的气路相悖！\n");

        if( (int)me->query_skill("force") < 180 )
                return notify_fail("你的内功修为不够火候，使用不了「引」字诀。\n");
                
        if( (int)me->query_skill("stick") < 180 )
                return notify_fail("你的打狗棒法不够娴熟，不会使用「引」字诀。\n");

        if( !objectp(target->query_temp("weapon") ) )
                return notify_fail("对手手无兵器，无法使用「引」字诀。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

        if( me->query("neili") <= 400 )
                return notify_fail("你的内力不够！\n");

        if( me->query("jingli") <= 300 )
                return notify_fail("你的精力不够！\n");
        weapon = me->query_temp("weapon");

        message_vision( HIC "\n$N提起"NOR+weapon->name()+HIC"迎面直点，暗用打狗棒法中的「引」字诀，$n竟还了一招！\n"NOR,me,target);

        COMBAT_D->do_attack(target, me, target->query_temp("weapon"));
        me->start_busy(1+random(1));
        me->add("neili", -400);
        me->add("jingli", -300);

        call_out("yin", 1, me, target);
        return 1;
}

void yin(object me,object target)
{
        object weapon,weapon2;
        string msg;
        int exp1,exp2,skill1,skill2;

        weapon = me->query_temp("weapon");
        weapon2 = target->query_temp("weapon");
        
		exp2 = target->query("combat_exp",1)/1000;
        exp1 = me->query("combat_exp",1)/1000;
        skill1 = me->query_skill("stick");
        skill2 = target->query_skill("dodge");

        if( !target || !me->is_fighting(target) ) return;
        if( !living(me) || me->is_ghost() ) return;
        if( !target || environment(me) != environment(target) || !me->is_fighting() ) return;
        if( me->query_skill_mapped("force") != "huntian-qigong" ) return;
        if( !weapon2 || !weapon ) return;

        if( target->query_temp("yin_hit"))
        {
                msg = CYN"可$p刚看$P的用过此招，冷哼一声，并没有上当。\n\n" NOR;
        }
        else if( random(exp1) + skill1 > exp2 + skill2 )
        {
                msg = HIR"\n$n哪知这打狗棒法神妙绝伦，数招一过，"+weapon2->name()+HIR"已被$N用“引”字诀拖住！\n" NOR;
                msg += HIB"$n跟着$N"+weapon->name()+HIB"挥舞，棒东走东，棒西走西，全然不得自由。\n\n"NOR;
                target->start_busy( skill1 /(30+random(10)) );
        }
        else {
                msg = CYN"可是$p看破了$P的企图，并没有上当。\n\n" NOR;
				me->start_busy(1+random(3));
        }
        target->set_temp("yin_hit",1);
        message_vision(msg, me, target);
        return;
}