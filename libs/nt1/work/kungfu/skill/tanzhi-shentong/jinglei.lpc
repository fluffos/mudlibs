// jinglei 弹指惊雷
// by Lonely

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int level, ap, dp, damage;
        string msg, pmsg;
        object weapon, weapon2;

        level   = (int) me->query_skill("tanzhi-shentong",1);

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("弹指惊雷只能对战斗中的对手使用。\n");
                
        if ( objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你使用了武器。\n");

/*
        if( me->query_skill_mapped("force") != "biho-shengong")
                return notify_fail("你所用的内功与「弹指惊雷」心法相悖！\n");
*/

        if( me->query_skill("biho-shengong", 1) < 120 )
                return notify_fail("你的内功修为火候未到，还未领悟「弹指惊雷」！\n");

        if( me->query_skill("finger", 1) < 120 )
                return notify_fail("你基本指法修为还不够，还未领悟「弹指惊雷」！\n");

        if( me->query_skill("tanzhi-shentong", 1) < 120 )
                return notify_fail("你弹指神通修为还不够，还未领悟「弹指惊雷」！\n");
        
        if( me->query("neili") <= 600 )
                return notify_fail("你的内力不够，劲力不足以施展弹指惊雷！\n");
        
        msg = HIC "$N使出弹指神通之「弹指惊雷」, 顿时眼内精光暴射，\n" NOR;

        ap = ap_power(me,"finger");
        dp = dp_power(target,"dodge");
        
        if (ap / 2 + random(ap) > dp) 
        {
                damage = da_power(me, "finger");
                me->add("neili", -200);
                
                pmsg = HIR "$n只觉得眼前一花，气海穴上微微一痛，全身真气狂泄而出！\n" NOR;
                if( objectp(weapon2 = target->query_temp("weapon")) && 
                    me->query("level") > target->query("level") )
                {
                        pmsg += HIR "同时手腕一麻，手中";
                        pmsg += weapon2->name();
                        pmsg += HIR "脱手而出！\n" NOR;
                        weapon2->move(environment(me));
                }

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50, pmsg);

                if ((int)target->query("neili") < damage)
                        damage = target->query("neili");
                target->add("neili", -damage);
                
                if (! target->is_busy()) 
                        target->start_busy(2);
                me->start_busy(2);
        } else 
        {
                me->add("neili", -100); 
                msg += "可是$n的看破了$N的企图，立刻采取守势，使$P的「弹指惊雷」没有起到作用。\n"NOR;
                me->start_busy(3);      
        }

        message_combatd(msg, me, target);
        
        return 1;
}

