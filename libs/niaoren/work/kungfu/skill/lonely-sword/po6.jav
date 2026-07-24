// poqi.c 破氣式

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-sword",1);

        if( !(me->is_fighting() ))
            return notify_fail("「破氣式」只能對戰斗中的對手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不對。\n");

        if( skill < 90)
            return notify_fail("你的獨孤九劍等級不夠, 不能使用「破氣式」！\n");

        if( me->query("neili") < 150 )
            return notify_fail("你的內力不夠，無法運用「破氣式」！\n");

        msg = HIC "$N潛運獨孤九劍「破氣式」，運氣貫劍使其由利返鈍，毫無花
俏地直刺$n的丹田。\n";
        message_vision(msg, me, target);

        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("force") / 2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-150);
            msg = "$N運起「破氣式」, $n頓時覺得眼前一花，氣海穴上微微一痛，\n";
            msg += "全身真氣狂泄而出！\n" NOR;
            neili_wound = 300 + random(skill);
            if(neili_wound > target->query("neili"))
                 neili_wound = target->query("neili");
            qi_wound = neili_wound / 5;
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi");

            target->add("neili", -neili_wound);
            target->add("qi", -qi_wound);
            target->add("eff_qi", -qi_wound);
            target->start_busy(2);
            me->start_busy(random(2));
        }
        else
        {
            if(userp(me))
                 me->add("neili",-100);
            msg = "可是$n看破了$N的企圖，立刻守緊門戶，几經艱難終于還招擋
開。\n"NOR;
            me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}
