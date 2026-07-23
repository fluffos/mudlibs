// po.c 总诀式
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("dugu-jiujian",1);

        if( !(me->is_fighting() ))
                return notify_fail("「破气式」只能对战斗中的对手使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( skill < 150)
                return notify_fail("你的独孤九剑等级不够, 不能使用「破气式」！\n");

        if( me->query("neili") < 1000 )
                return notify_fail("你的内力不够，无法运用「破气式」！\n");
 
        msg = HIC "$N潜运独孤九剑「破气式」，运气贯剑使其由利返钝，毫无花俏地直刺$n的丹田。\n";
        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("force")/2;
        if( dp < 1 )
                dp = 1;
        if( random(ap + 20) > dp ){
                if(userp(me))
                        me->add("neili",-(200+random(200)));
                msg += "$N运起「破气式」, $n顿时觉得眼前一花，气海穴上微微一痛，全身真气狂泄而出！\n" NOR;

                qi_wound = ap+random(ap/2) ;
                neili_wound = random(qi_wound/2);
                if(neili_wound > target->query("neili"))
                        neili_wound = target->query("neili");

                if(qi_wound > target->query("qi"))
                        qi_wound = target->query("qi");
                if(random(2)== 1)
                        target->apply_condition("no_perform", 1+ random(2));
                target->add("neili", -neili_wound);
                target->add("qi", -qi_wound);
                target->add("eff_qi", -qi_wound);
                target->add_busy(2);
                me->start_busy(random(2));
               me->start_perform(5,"破气式");
        }
        else
        {
                if(userp(me))
                        me->add("neili",-200);
                msg += "可是$n看破了$N的企图，立刻守紧门户，几经艰难终于还招挡开。\n"NOR;
                me->start_busy(2);
               me->start_perform(3,"破气式");
        }
        message_vision(msg, me, target);

        return 1;
}
