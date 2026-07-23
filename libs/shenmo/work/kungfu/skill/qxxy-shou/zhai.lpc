// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define ZHAI "「" HIC "摘星式" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp,clv;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHAI "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHAI "只能空手施展。\n");

        if (clv = (int)me->query_skill("qxxy-shou", 1) < 80)
                return notify_fail("你的七星星移手修为有限，难以施展" ZHAI "。\n");

      //  if (me->query_skill_prepared("cuff") != "qxxy-shou")
      //          return notify_fail("你没有准备七星拳法，难以施展" ZHAI "。\n");

        if (me->query_skill("force") < 80)
                return notify_fail("你的内功修为不够，难以施展" ZHAI "。\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("你现在的真气不够，难以施展" ZHAI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        ap = me->query_skill("cuff") * 3 / 2 + me->query("level") * 20 + 
             me->query_skill("force", 1);
        dp = target->query_skill("parry") + target->query("level") * 20 + 
             target->query_skill("force", 1);

        msg = HIW "$N" HIW "双拳挥出，施出绝招「" HIC "摘星式"
              HIW "」，刚劲有力，部位极准，分袭$n" HIW "面"
              "门和胸口。\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("qxxy-shou", 1);
                damage += random(damage / 2);
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "$N" HIR "出手既快，方位又奇，$n"
                                           HIR "闪避不及，闷哼一声，已然中拳。\n" NOR;  

                me->add("neili", -100);
                me->start_busy(2 + random(2));                                         
        } else
        {
                msg += CYN "$n" CYN "不慌不忙，以快打快，将$N"
                       CYN "这招化去。\n" NOR;

                me->add("neili", -30);
                me->start_busy(2 );
        }
        message_combatd(msg, me, target);
if ((int)me->query_skill("qxxy-shou", 1)> 300)
{
        msg = MAG "$N默运神元神功，将内力聚于手指，平平淡淡毫无花俏地点向$n的膻中穴" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = YEL "$N两掌竖合，掌心微虚，如莲花之开放，接着双手食指轻轻一弹，两股指风同时袭向$n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = WHT "$N凌空虚点数指，数道指风合成一股剑气，直向$n攻去"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =RED "$N缓缓举手，五指先是箕张，再缓缓拢指合拳，霎时生出气凝河岳般的剑气狂扬" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR "$N指风犀利，似一道无形剑气，将$n笼罩于内，$n只觉胸口一痛，全身真气狂泻而出" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}

        return 1;
}

