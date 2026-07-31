// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhao.c 佛光普照

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/pudu-zhang/zhao"))
                return notify_fail("你还没有受过高人指点，无法施展「佛光普照」。\n");
                 
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("「佛光普照」只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");

        if (me->query_skill("force") < 200)
                return notify_fail("你的内功的修为不够，不能使用这一绝技！\n");

        if (me->query_skill("pudu-zhang", 1) < 135)
                return notify_fail("你的普渡杖法修为不够，目前不能使用佛光普照！\n");

        if (me->query("neili") < 1000)
                return notify_fail("你的真气不够，不能使用佛光普照！\n");

        if (me->query_skill_mapped("staff") != "pudu-zhang")
                return notify_fail("你没有激发普渡杖法，不能使用佛光普照！\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "纵声长笑，挥动手中的" + weapon->name() +
              HIY "，如泰山一般压向$n" + HIY "，令人叹为观止！\n" NOR;

        ap = ap_power(me, "staff") + me->query("max_neili") / 10;
        dp = dp_power(target, "force") + target->query("max_neili") / 10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "staff");
                me->add("neili", -250);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "只见$p" HIR "闷哼一声，连叫都叫"
                                           "不出来，身子飞跌出去，重重的摔倒在地上！\n" NOR);
        } else
        {
                me->add("neili", -60);
                me->start_busy(3);
                msg += CYN "可是$p" CYN "运足内力，奋力挡住了"
                       CYN "$P" CYN "这惊天动地的一击！\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

