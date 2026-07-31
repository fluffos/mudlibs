// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define PO "「" HIW "骄阳劈天" NOR "」"
string query_name() { return "骄阳"ZJBR"劈天"; }
inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/jiuyang-shengong/pi"))
                return notify_fail("你还没有受过高人指点，无法施展" PO "。\n");

        if (userp(me) && (me->query_temp("weapon") || me->query_temp("secondary_weapon")))
                return notify_fail( "只能空手施展" PO "。\n");
        
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("jiuyang-shengong", 1) < 220)
                return notify_fail("你的九阳神功不够娴熟，难以施展" PO "。\n");

        if ((int)me->query_skill("force", 1) < 260)
                return notify_fail("你的内功根基不够，难以施展" PO "。\n");

        if (me->query_skill_mapped("unarmed") != "jiuyang-shengong")
                return notify_fail("你现在没有激发九阳神功为拳脚，难以施展" PO "。\n");

        if (me->query_skill_mapped("force") != "jiuyang-shengong")
                return notify_fail("你现在没有激发九阳神功为内功，难以施展" PO "。\n");

        if (me->query_skill_prepared("unarmed") != "jiuyang-shengong")
                return notify_fail("你现在没有准备使用九阳神功，难以施展" PO "。\n");

        if ((int)me->query("max_neili") < 5500)
                return notify_fail("你的内力修为不足，难以施展" PO "。\n");

        if (me->query("neili") < 400)
                return notify_fail("你现在真气不够，难以施展" PO "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "\n$N" HIW "猛然间飞身而起，半空中一声长啸，内力源源不绝地涌"
              "出！" HIW "刹那间白芒夺目，自天而下，双拳奔袭向$n" HIW "！\n" NOR;

        me->add("neili", -150);
        ap = me->query_skill("unarmed") + me->query_skill("force", 1);
        dp = target->query_skill("parry") + target->query_skill("force", 1);

        me->start_busy(2 + random(2));
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("unarmed");
                me->add("neili", -200);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 85 + random(5),
                                           (: final, me, target, damage :));
        } else
        {
                msg += HIC "可是$n" HIC "看透$P" HIC "此招之中的破绽，镇"
                       "定逾恒，全神应对自如。\n" NOR;
        }
        message_sort(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        target->add("neili", -(damage / 4));
        target->add("neili", -(damage / 8));
        return  HIR "$n" HIR "只觉光内力奔涌，正犹豫间拳芒已击中$n" HIR "身体，顿时"
                "鲜血狂涌，内息散乱。\n" NOR;
}


