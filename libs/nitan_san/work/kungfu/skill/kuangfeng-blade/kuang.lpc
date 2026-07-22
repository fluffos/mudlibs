// kuang.c -「狂风二十一式」
// by Lonely

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int ap, dp, damage;
        string msg;
        
        if( !target ) target = offensive_target(me);
        if( !target||!target->is_character()||!me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用「狂风二十一式」。\n");
        if( (int)me->query_skill("kuangfeng-blade",1) < 70)
                return notify_fail("你目前功力还使不出「狂风二十一式」。\n");
        if( (int)me->query("neili") < 200 )
                return notify_fail("你的内力不够。\n");

        msg = HIC "$N淡然一笑，本就快捷绝伦的刀法骤然变得更加凌厉！就在这一瞬之间，\n"+
              "$N已劈出二十一刀！刀夹杂着风，风里含着刀影！$n只觉得心跳都停止了！\n"NOR;
              
        ap = ap_power(me, "blade");
        dp = dp_power(target, "parry");

        if (ap / 2 + random(ap) > dp) 
        {
                damage = da_power(me, "blade");
                me->add("neili", -100);

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           RED "只见$n" RED "已被$N" RED "切得体无完肤，血如箭般由全身喷射而出！\n" NOR);
                me->start_busy(random(2));
        }
        else
        {
                msg += HIG "只见$n" HIG "急忙抽身，躲过了$N" HIG "的必杀一击！\n" NOR;
                me->add("neili", -100);
                me->start_busy(2 + random(2));
        }
        message_combatd(msg, me, target);

        return 1;
}


