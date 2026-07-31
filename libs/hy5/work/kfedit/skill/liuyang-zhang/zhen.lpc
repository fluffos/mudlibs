// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhen.c 一掌震天

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int ap, dp, damage;
        string msg, pmsg;
        
        if (! target)
                target = offensive_target(me);

                
        if (! target || ! target->is_character() 
        ||  ! me->is_fighting(target))
                return notify_fail("「一掌震天」只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon"))
                return notify_fail("你必须空手才能使用「一掌震天」之力！\n");

        if (me->query_skill("liuyang-zhang", 1) < 200)
                return notify_fail("你的天山六阳掌不够娴熟，无法使用「一掌震天」之力。\n");

        if (me->query_skill("strike", 1) < 180)
                return notify_fail("你的基本掌法不够娴熟，无法使用「一掌震天」之力。\n");

        if (me->query_skill("force", 1) < 220)
                return notify_fail("你的基本内功修为不足，无法使用「一掌震天」之力。\n");

        if (me->query_skill("bahuang-gong", 1) < 240)
                return notify_fail("你的八荒六合惟我独尊功修为不足，无法使用「一掌震天」之力。\n");

        if (me->query_str() < 38)
                return notify_fail("你的后天膂力不足，无法使用「一掌震天」之力。\n");

        if (me->query_str() < 38)
                return notify_fail("你的后天根骨不足，无法使用「一掌震天」之力。\n");

        if (me->query("neili", 1) < 2000)
                return notify_fail("你现在内力不足，不能使用「一掌震天」。\n");

        if (me->query("max_neili", 1) < 4000)
                return notify_fail("你现在内力修为不足，不能使用「一掌震天」。\n");

        if (me->query("jiali") < 50)
                return notify_fail("你加力这么小，怎么能施展「一掌震天」呢？\n");
       if ((int)me->query_skill("zhougong-jian", 1) < 50)
               return notify_fail("你的周公剑火候不够。\n");
       if ((int)me->query_skill("wuliang-jian", 1) < 50)
               return notify_fail("你的无量剑法火候不够。\n");   

       if ((int)me->query_skill("pidi-shenzhen", 1) < 50)
               return notify_fail("你的辟地神针火候不够。\n");
       if ((int)me->query_skill("wudoumi-shengong", 1) < 50)
               return notify_fail("你的五斗米神功火候不够。\n");

        msg = WHT" \n只见$N" WHT "忽然掌缘隐隐泛出殷红之色，丝丝白气缭绕其间，转瞬间已将$P的手掌包了起来。\n" +
             "待得此时，$n" WHT "已觉不妙，哪知正待闪躲，$N" WHT "这招「" HIY "一掌震天" WHT "」已然推至胸前，来势虽\n" +
             "缓，但$p只觉身周的空气仿佛已经凝结，这一掌之力已将上下左右前后包了起来，实是难\n"+
             "以摆脱。瞬间的空气流动直如一个真空大洞，使得身周的人均觉得一阵气滞！\n\n"NOR;

        ap = me->query_skill("strike") + me->query("con") * 20; 
        dp =  target->query_skill("force") + target->query("con") * 20; 
             
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -500);
 damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                pmsg = HIR "$n" HIR "眼见$N" HIR "一招已至，掌劲如洪，内力澎湃，然而苦于身陷旋涡之中，避无可避，只是\n" +
                       "稍微挪动脚步也已困难之极，结果被$N" HIR "一掌印在胸前，登感一阵痛入骨髓，却是肋骨被\n" +
                       "这一掌之力震断，气血翻涌已然失控，一口鲜血如箭般从口鼻中喷了出来！\n\n" NOR;
 damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "眼见$N" HIR "一招已至，掌劲如洪，内力澎湃，然而苦于身陷旋涡之中，避无可避，只是\n" +
                       "稍微挪动脚步也已困难之极，结果被$N" HIR "一掌印在胸前，登感一阵痛入骨髓，却是肋骨被\n" +
                       "这一掌之力震断，气血翻涌已然失控，一口鲜血如箭般从口鼻中喷了出来！\n\n" NOR;
                //msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65, pmsg);
                
                me->start_busy(3);      
        } else
        {
                msg += HIG "岂料$n" HIG "机敏异常，一眼道破$N" HIG "这招的破绽之处乃是旋涡的中心，其间极为薄弱，于是\n"+
                       "单手成指，竟刺破$N" HIG "的旋涡屏障，接连两指点在$P手心的" HIR "少府"
                       HIG "、" HIR "劳宫" HIG "二穴！结果$N" HIG "穴道被\n" +
                      "封，这内力无处宣泄，竟反蚀其身，震得$P脸如金纸，口唇紫青，查点受了内伤！\n\n" NOR;

                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

