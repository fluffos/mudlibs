// lingbo.c  洛神凌波
// by Lonely


#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! target->is_character() || ! me->is_fighting(target))
                return notify_fail("你一个人跳甚么？\n");

        if (me->query("gender") == "无性")
                return notify_fail(HIY "一个公公，满场乱跳，羞也不羞？\n" NOR);

        if ((int)me->query_skill("beiming-shengong", 1) < 100)
                return notify_fail(HIY "你的北冥神功修为不够。\n" NOR);

        if ((int)me->query_skill("lingboweibu", 1) < 100)
                return notify_fail(HIY "你的凌波微步不够熟练。\n" NOR);

        if ((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if (me->query("gender") == "男性")
        {
                msg = HIC "$N提起真气，依照先天伏羲六十四卦，不理$n如何出招，自顾自的将"
                      "凌波微步由头到尾迅速无比的走了一次。\n只见$N意态飘逸，影子乱飞，"
                      "$n却是一点皮毛也沾不上。$N真个将逍遥二字发挥得淋漓尽至。\n" NOR;
        }
        else  
        {
                msg = HIG "$N提起真气，依照先天伏羲六十四卦，不理$n如何出招，自顾自的将"
                      "凌波微步由头到尾迅速无比的走了一次。\n$N仿如洛神再生，微步凌波，"
                      "$n却是一点皮毛也沾不上。$N真个将逍遥二字发挥得淋漓尽至。\n" NOR;
        }
        
        ap = me->query_skill("lingboweibu", 1) * 3 / 2 + me->query("level") * 20 + 
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("dodge") + target->query("level") * 20 + 
             target->query_skill("martial-cognize", 1);
                   
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIW "$N犹如神仙下凡，$n跟随着$N的舞步转了个头晕眼花\n" NOR;
                target->start_busy( (int)me->query_skill("lingboweibu",1) / 30);
                me->add("neili", -100);
                // me->start_busy(1);
        } else 
        {
                msg += HIG "可是$n看破了$N的舞步,仪态从容的躲了过去\n" NOR;
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

