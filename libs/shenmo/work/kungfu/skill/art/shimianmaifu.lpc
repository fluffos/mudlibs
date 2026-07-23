// newpfm.c 昆仑琴音扰敌

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
int lev;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[十面埋伏]只能对战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
                
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你的内力不足!\n");

        if( (int)me->query_skill("art", 1) < 100 )
                return notify_fail("你的琴技不足以弹奏如此高深的曲子\n");

        msg = HIW "$N催动内力,一曲[十面埋伏]缓缓奏出,企图瓦解$n的攻势。\n";
lev=(int)me->query_skill("art", 1);
me->add("neili",-140);
     if (random(me->query("combat_exp"))+(lev*300) > target->query("combat_exp") / 2 )               
{
                msg += GRN " 结果$p被$P琴音所惑,只觉进也不是,退也不是,处处埋伏,顿时方寸大乱\n" NOR;
                target->start_busy( (int)me->query_skill("art",1) / 50 + 2 );
        } else {
                msg += HIR"可是$p内力深厚,不为$P的琴声所动,全神应对自如。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}

