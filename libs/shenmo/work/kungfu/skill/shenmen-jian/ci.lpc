// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit F_SSERVER;


int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp;


        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        skill = me->query_skill("shenmen-jian", 1);

        if( !(me->is_fighting() ))
                return notify_fail("神门刺只能对战斗中的对手使用。\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("对方没有使用兵器，你用了神门刺也没用。\n");

        if( skill < 160)
                return notify_fail("你的神门十三剑等级不够, 无法施展神门刺。\n");

        if( me->query("neili") < 200 )
                return notify_fail("你的内力不够，无法施展神门刺！\n");

        msg = HIY "突然$N" HIY "一声冷哼，手中" +weapon->name()+ NOR + HIY
                  "中攻直进，直刺$n拿着的" +weapon2->name()+ NOR + HIY"的"
                  "手腕。\n" NOR;
        message_combatd(msg, me, target);

        ap = (int)me->query_skill("sword", 1);
        dp = (int)target->query_skill("parry",1);

        if( ap / 2 + random(ap) > dp || random(8)==0)
        {
                if (userp(me))
                me->add("neili", -120);
                msg = HIR "$n只觉手腕一阵刺痛，手中" +weapon2->name()+ NOR + HIR
                      "再也捉拿不住，脱手而飞！\n" NOR;
                me->start_busy(2);
                if (! target->is_busy())
                target->start_busy(5);
                weapon2->move(environment(target));
        }
        else
        {
                if(userp(me))
                me->add("neili", -40);
                msg = CYN "可是$n看破了$N的企图，将手中兵刃挥舞得密不透风，挡开了$N" CYN 
                      "的兵器。\n"NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
        return 1;
}
