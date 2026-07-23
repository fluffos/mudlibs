// poqi.c 破气式

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, force;

//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");
     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("独孤九剑必须配合紫霞神功。\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-sword",1);

        if( !(me->is_fighting() ))
            return notify_fail("「破气式」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

        if( skill < 170)
            return notify_fail("你的独孤九剑等级不够, 不能使用「破气式」！\n");

        if( me->query("neili") < 250 )
            return notify_fail("你的内力不够，无法运用「破气式」！\n");
	 force = target->query("max_neili");

        msg = HIC "$N潜运独孤九剑「破气式」，运气贯剑使其由利返钝，毫无花俏地直
刺$n的丹田。\n"NOR;
        message_combatd(msg, me, target);

        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("dodge") / 2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-150);
            msg = BLU"$n顿时觉得眼前一花，气海穴上微微一痛，全身真气狂泄而出！\n"NOR;
            target->set("neili",force/2 );
//            target->set("neili",);
            me->start_busy(2);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        }
        else
        {
            if(userp(me))
                 
            msg = "可是$n看破了$N的企图，立刻守紧门户，几经艰难终于还招挡
开。\n"NOR;
            me->start_busy(2);
		message_combatd(msg, me, target);
        }

        return 1;
}
