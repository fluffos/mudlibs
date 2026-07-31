// muyeyingyang.c 牧野鹰扬

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("牧野鹰扬只能对战斗中的对手使用。\n");

        if((int)me->query_str() < 30)
                return notify_fail("你臂力不够,不能使用牧野鹰扬！\n");

        if((int)me->query_skill("sougu",1) < 150)
                return notify_fail("你的搜骨鹰爪功修为不够,目前还不能使用牧野鹰扬！\n");

        if((int)me->query("neili") < 800)
                return notify_fail("你内力现在不够, 不能使用牧野鹰扬！\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        msg = HIY "$N使出搜骨鹰爪功绝技「牧野鹰扬」，双爪蓦地抓向$n的全身要穴。\n";
        message_vision(msg, me, target);

if ((int)me->query_skill("jiuyang-shengong",1) > 50)
{

        extra = me->query_skill("jiuyang-shengong",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg =  HIW "第一爪\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "第二爪\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "第三爪\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);    
        me->add_temp("apply/damage", -extra);

}
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg = "结果$p被$P点中要穴，立时动弹不得！\n" NOR;
                target->start_busy( (int)me->query_skill("sougu",1) / 50 + 3);
                me->start_busy(2);
                me->add("neili", -150);
        } else {
                msg = HIG "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

