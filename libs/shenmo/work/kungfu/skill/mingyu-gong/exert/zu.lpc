// zu.c  by sinb

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用明玉功恢复自己的气血。\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("你的真气不够！");

        if ((int)me->query_skill("mingyu-gong", 1) < 160)
                return notify_fail("你的明玉功等级不够。\n");
         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("你的冰雪心法修为不够。\n"); 
        if ((int)me->query_temp("qizu"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("mingyu-gong");

        me->add("neili", -100);

        message_combatd(HIC "$N" HIC "运起「气足」奇功，"
                        "眼中闪过一片青芒，随即恢复正常\n" NOR, me);

        me->set_temp("qizu", 1);

        me->apply_condition("mingyu_qizu", skill / 80);
        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

