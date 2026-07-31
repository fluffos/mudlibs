#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIW "兰剑舞" NOR; } 
string query_name() { return "兰剑舞"; }
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

        if ((int)me->query_skill("lunhui-sword", 1) < 600)
                return notify_fail("你的六道轮回剑不够娴熟，难以施展" + name() + "。\n");

        if( me->query("neili")<3000 )
                return notify_fail("你的真气不够，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("sword") != "lunhui-sword")
                return notify_fail("你没有激发六道轮回剑，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIG "$N" HIG "轻舞手中" + weapon->name() + HIG "，剑光四射间，漫天兰花洒落，犹如仙境般美妙 ……\n" NOR;

        ap = me->query_skill("sword"); 
        dp = target->query_skill("dodge"); 

        attack_time = 6;
        count = ap / 10;
        
        if (me->query_skill("lunhui-sword", 1) >= 800)
                count *= 2;

        if (me->query_skill("lunhui-sword", 1) >= 1600)
                count *= 2;
                
        me->add_temp("apply/attack", count/2);
        me->add_temp("apply/damage", count);
        
        message_combatd(msg, me, target);

        me->add("neili", -3000);

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
