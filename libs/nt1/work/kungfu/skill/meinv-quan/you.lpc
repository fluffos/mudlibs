// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// you.c 古墓幽居

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int damage, ap, dp;
        string msg;
        string pmsg;

        if (userp(me) && ! me->query("can_perform/meinv-quan/you"))
                return notify_fail("你未得高人指点，不知该如何施展古墓幽居。\n");
                
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("古墓幽居只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("你的美女拳级别不够，不会使用古墓幽居。\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("你的内功还未娴熟，不能利用神功伤敌。\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("你现在真气不够，不能使用古墓幽居。\n");

        if (me->query_skill_mapped("unarmed") != "meinv-quan")
                return notify_fail("你没有激发美女拳法，不能施展古墓幽居。\n");

        msg = HIW "$N" HIW "右手支颐，左袖轻轻挥出，长叹一声，使"
              "出「古墓幽居」，一脸尽现寂寥之意。\n" NOR;

        ap = ap_power(me, "unarmed"); 
        dp = dp_power(target, "parry"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(random(3));

                damage = da_power(me, "unarmed");

                me->add("neili", -100);

                if (damage < 30)
                        pmsg = HIY "结果$n" HIY "被$N袍"
                               HIY "袖一拂，闷哼一声。\n" NOR;
                else if(damage < 55)
                        pmsg = HIY "结果$n" HIY "被$N"
                               HIY "以袍袖一拂，「腾腾」地退出几步。\n" NOR;
                else if (damage < 80)
                        pmsg = HIR "结果$n" HIR "被$N"
                               HIR "以袍袖一拂，胸口有如受到一记重"
                               "锤，气血为之一窒！\n" NOR;
                else
                        pmsg = RED "结果$n" RED "被$N" RED
                               "的袍袖一拂，眼前一黑，浑身气血翻腾，"
                               "竟如身入洪炉一般！\n" NOR;
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 70, pmsg);
        } else
        {
                me->start_busy(3);
                msg += CYN "可是$p" CYN "看破了$P" CYN
                       "的企图，稳如泰山，抬手一架格开了$P"
                       CYN "这一拳。\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
