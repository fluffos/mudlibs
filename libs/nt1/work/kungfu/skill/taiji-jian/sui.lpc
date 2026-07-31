// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// sui.c 随字诀

#include <ansi.h>

#define PFM_NAME        "随字诀"

inherit F_SSERVER;

void remove_effect(object me, int a_amount, int d_amount);

int perform(object me, object target)
{
        object weapon;
        int skill;
        string msg;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/taiji-jian/sui"))
                return notify_fail("你还没有受过高人指点，无法施展「" PFM_NAME "」。\n");
                
        if (! target || ! me->is_fighting(target))
                return notify_fail("「" + PFM_NAME + "」只能对战斗中的对手使用。\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("必须拿剑才能施展「" + PFM_NAME + "」。\n");

        if ((int)me->query_skill("taiji-jian", 1) < 100)
                return notify_fail("你的太极剑法不够娴熟，不会使用「" + PFM_NAME + "」。\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 80)
                return notify_fail("你的太极神功火候不够，难以施展「" + PFM_NAME + "」。\n");

        if ((int)me->query("neili") < (int)me->query("max_neili") / 50)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_temp("tjj_sui")) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("taiji-jian");
        msg = HIC "$N使出太极剑法「随」字诀，剑圈逐渐缩小，手中" + weapon->name() +
              HIC "幻出道道光环，将周身护住。\n" NOR;
        message_combatd(msg, me, target);

        me->add_temp("apply/attack", -skill/6);
        me->add_temp("apply/defense", skill);
        me->set_temp("tjj_sui", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill/6, skill :), skill);

        me->add("neili", -(int)me->query("max_neili") / 50);
        if(me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
        me->add_temp("apply/attack", a_amount);
        me->add_temp("apply/defense", - d_amount);
        me->delete_temp("tjj_sui");
        tell_object(me, HIG "你的「" + PFM_NAME + "」运行完毕，将内力收回丹田。\n" NOR);
}

