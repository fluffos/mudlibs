// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#define JIN "「" HIY "金刚剑气" NOR "」"

inherit F_SSERVER;


string final(object me, object target, int damage);

int perform(object me, object target)
{
        int damage;
        string msg;

        int ap, dp, slv, clv,p;
        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(JIN "只能对战斗中的对手使用。\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("你必须空手才能使用" JIN "。\n");

        if ((int)me->query_skill("canhe-zhi", 1) < 260)
                return notify_fail("你的参合指修为有限，难以施展" JIN "。\n");

        if (me->query_skill_prepared("finger") != "canhe-zhi")
                return notify_fail("你现在没有准备使用参合指，难以施展" JIN "。\n");

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("你的内力修为不足，难以施展" JIN "。\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你的真气不够，难以施展" JIN "。\n");
        if ((int)me->query_skill("murong-jianfa", 1) < 180)
                return notify_fail("你的慕容剑法火候太浅。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 180)
                return notify_fail("你的神元功火候太浅。\n");
        if ((int)me->query_skill("murong-daofa", 1) < 180)
                return notify_fail("你的慕容刀法火候太浅。\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 180)
                return notify_fail("你的燕灵身法火候太浅。\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 180)
                return notify_fail("你的斗转星移掌火候太浅。\n");

        if ((int)me->query_skill("qxxy-shou", 1) < 180)
                return notify_fail("你的七星星移手火候太浅。\n");
        if ((int)me->query_skill("canhe-zhi", 1) < 180)
                return notify_fail("你的参合指火候太浅。\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
                return notify_fail("你的斗转星移火候太浅。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "双手合十，微微一笑，颇得拈花之意。食指并中指"
              "轻轻一弹，顿时一屡罡气电射而出，朝$n" HIY "袭去。\n" NOR;  

        ap = me->query_skill("canhe-zhi", 1) + me->query("level") * 20 + 
             me->query_skill("force") +
             me->query_skill("parry", 1);
        dp = target->query_skill("buddhism", 1) + target->query("level") * 20 + 
             target->query_skill("force") +
             target->query_skill("parry", 1);
        me->start_busy(3);

        if ((int)target->query_skill("buddhism", 1) >= 200
            && random(5) == 1)
        {
                me->add("neili", -400);
                me->start_busy(4);
                msg += HIY "但见$n" HIY "也即脸露笑容，衣袖轻轻一拂，顺势"
                       "裹上，顿将$N" HIY "的指力消逝殆尽。\n" NOR;
        } else
        if (ap * 2 / 3 + random(ap) > dp)
        { 
                damage = me->query_skill("finger");
                me->add("neili", -400);
        target->receive_damage("jing", damage / 6);
        target->receive_wound("jing", damage / 10);
        target->receive_damage("qi", damage*2);
        target->receive_wound("qi", damage);
                msg += HIR "只听“噗嗤”一声，指力竟在$n" HIR
                "胸前穿了一个血肉模糊的大洞，透体而入。\n" NOR;
        } else
        {
                me->add("neili", -200);
                me->start_busy(4);
                msg += CYN "$n" CYN "见$N" CYN "来势汹涌，不敢轻易"
                       "招架，急忙提气跃开。\n" NOR;
        }
        message_combatd(msg, me, target);
       damage = me->query_skill("canhe-zhi");
        slv = target->query_skill("six-finger", 1);

        ap = me->query_skill("finger");
        dp = target->query_skill("dodge");

        msg = HIW "\n只见$N" HIW "十指分摊，霎时破空声骤响，数股剑气至指尖激"
              "射而出，朝$n" HIW "径直奔去！\n" NOR;

        me->start_busy(3);

        if (slv >= 140 
            && random(5) == 0 
            && slv >= clv - 60 // 如果参合指等级比六脉神剑等级高60级以上取消特殊效果
            &&! target->is_busy()
            && target->query_skill_prepared("finger") == "six-finger")
        {
                msg += HIY "\n但见$n" HIY "斜斜一指点出，指出如风，剑气纵横，嗤然"
                       "作响，竟将$N" HIY "的剑气全部折回，反向自己射去！\n" NOR +
                       HIR "你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR;

                me->receive_wound("qi", slv / 3 + random(slv / 4));
                p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
                msg += "( $N" + eff_status_msg(p) + ")\n";

        } else
        if (ap * 2 / 3 + random(ap) > dp)
        { 
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "\n顿时只听“嗤啦”的一声，$n" HIR
                                           "躲闪不及，剑气顿时穿胸而过，带出一蓬"
                                           "血雨。\n" NOR;     
        } else
        {
                msg += CYN "\n$n" CYN "见$N" CYN "来势汹涌，急忙飞身一跃而"
                       "起，避开了这一击。\n" NOR;
        }

        ap = me->query_skill("finger");
        dp = target->query_skill("force");

        if (slv >= 160 
            && random(8) == 0 
            && slv >= clv - 60  // 如果参合指等级比六脉神剑等级高60级以上取消特殊效果
            &&! target->is_busy() 
            && target->query_skill_prepared("finger") == "six-finger")
        {
                msg += HIY "\n忽见$n" HIY "左手小指一伸，一招「少泽剑」至指尖透出"
                       "，真气鼓荡，轻灵迅速，顿将$N" HIY "剑气逼回！\n" NOR + HIR
                       "你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR;

                me->receive_wound("qi", slv / 2 + random(slv / 4));
                p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
                msg += "( $N" + eff_status_msg(p) + ")\n";

        } else
        if (ap * 2 / 3 + random(ap) > dp)
        { 

target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "\n只听$n" HIR "一声惨嚎，被$N" HIR
                                           "的剑气刺中了要害，血肉模糊，鲜血迸流不"
                                           "止。\n" NOR;     

        } else
        {
                msg += CYN "\n$n" CYN "见$N" CYN "来势汹涌，急忙飞身一跃而"
                       "起，避开了这一击。\n" NOR;
        }

        ap = me->query_skill("finger");
        dp = target->query_skill("parry");

        if (slv >= 180 
            && random(10) == 0 
            && slv >= clv - 50  // 如果参合指等级比六脉神剑等级高50级以上取消特殊效果
            &&! target->is_busy()
            && target->query_skill_prepared("finger") == "six-finger")
        {
                msg += HIY "\n可电光火石之间，$n" HIY "猛然翻掌，右手陡然探出，中"
                       "指「中冲剑」向$N" HIY "一竖，登将参合剑气化于无形！\n" NOR
                       + HIR "你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR;

                me->receive_wound("qi", slv / 2 + random(slv / 2));
                p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
                msg += "( $N" + eff_status_msg(p) + ")\n";
                me->start_busy(6);

        } else
        if (ap * 2 / 3 + random(ap) > dp)
        { 
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "\n$n" HIR "奋力招架，仍是不敌，$N"
                                           "的" HIR "无形剑气已透体而入，鲜血飞射"
                                           "，无力再战。\n" NOR;     
        } else
        {
                msg += CYN "\n$n" CYN "见$N" CYN "来势汹涌，急忙飞身一跃而"
                       "起，避开了这一击。\n" NOR;
        }
        me->add("neili", -400 - random(100));
        message_combatd(msg, me, target);
       
       
       msg = HIW "\n最后 $N" HIW "食指伸出，施展出参合指的精妙招式，一道气流袭向$n"
              HIW "的胸前穴位。\n" NOR;

        ap = me->query_skill("force");
        dp =target->query_skill("force");
        
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -100);
                me->start_busy(2);
                damage =  me->query_skill("force");
        target->receive_damage("qi", damage*2);
        target->receive_wound("qi", damage);
                msg += HIR "$n" HIR "躲避不及，顿时觉得顿觉浑身经"
                                           "脉都是一痛，手里不禁一软。\n" NOR;
        } else
        {
                me->add("neili",-40);
                msg += CYN "可是$n" CYN "看破了$N" CYN "的来路，立刻腾挪躲闪，使$N"
                       CYN "的攻击没有起到作用。\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
if ((int)me->query_skill("canhe-zhi", 1)> 350)
{
if (random(3)==0) target->start_busy(3);
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



