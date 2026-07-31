#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIW "剑雨" NOR; } 
string query_name() { return "剑雨"; }
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count;
        int i, attack_time;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对，难以施展" + name() + "。\n");

        if ((int)me->query_skill("wushang-jianjingsAA", 1) < 120)
                return notify_fail("你的无上剑经不够娴熟，难以施展" + name() + "。\n");

        if( me->query("neili")<2000 )
                return notify_fail("你的真气不够，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("sword") != "wushang-jianjingsAA")
                return notify_fail("你没有激发无上剑经，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIG "$N" HIG "轻舞手中" + weapon->name() + HIG "，剑光四射间，漫天兰花洒落，犹如仙境般美妙 ……\n" NOR;

        ap = me->query_skill("sword"); 
        dp = target->query_skill("dodge"); 

        attack_time = 6;
        count = ap / 10;
        
        if (me->query_skill("wushang-jianjingsAA", 1) >= 1000)
                count *= 5;

        if (me->query_skill("wushang-jianjingsAA", 1) >= 2000)
                count *= 5;
                
        me->add_temp("apply/attack", count/2);
        me->add_temp("apply/damage", count);
        
        message_combatd(msg, me, target);

        me->add("neili", -2000);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (! target->is_busy()) target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count/2);
        me->add_temp("apply/damage", -count);
        
        me->start_busy(3 + random(2));

        return 1;
}
