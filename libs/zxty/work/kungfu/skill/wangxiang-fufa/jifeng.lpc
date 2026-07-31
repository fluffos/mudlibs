// jifeng.c 疾风斩
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target, weapon2;
        int skill, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("wangxiang-fufa",1);

        if( !(me->is_fighting() ))
                return notify_fail("疾风斩只能对战斗中的对手使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "axe")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query_skill("wangran-xinfa", 1) < 50)
                return notify_fail("你的本门心法火候不够，无法使用。\n");
        if ((int)me->query("shen") < 0) 
                return notify_fail("你的侠义正气太低了，无法集中心志！\n");

        if ((int)me->query_skill("shuiyue", 1) < 50)
                return notify_fail("你的本门轻功火候不够，无法使用。\n");
                       if( skill < 50)
                return notify_fail("你的妄想斧法等级不够, 不能使用疾风斩！\n");

        if( me->query("neili") < 500 )
                return notify_fail("你的内力不够，无法运用疾风斩！\n");
 
        msg = HIW "$N潜运妄想斧法之"HIG"疾风斩"HIW"奋力向$n"HIW"攻去。\n"NOR;
        message_vision(msg, me, target);
 
        ap = me->query_skill("axe") + skill;
        dp = target->query_skill("force") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("neili",-150);
                msg = HIY"结果一击命中, $n"HIY"顿时觉得身上一痛，"HIR"鲜血"NOR""HIY"喷射而出。\n"NOR;
                message_vision(msg, me, target);
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
                me->start_busy(1+random(1));
           
        if  ((me->query("family/family_name") == "痴心妄想门")
&&(random(skill) >= 150) && (objectp(weapon2 = target->query_temp("weapon"))))
                {                weapon2->move(environment(me));
                msg = YEL"$n虎口一麻！手中兵刃不由自主的掉在了地上！\n"NOR;
                message_vision(msg, me, target);
                }
        }
        else
        {
                if(userp(me))
                        me->add("neili",-100);
                msg = RED "可是$n机警地闪开了$N的攻击。\n"NOR;
                message_vision(msg, me, target);
                me->start_busy(4);
        }

        return 1;
}
