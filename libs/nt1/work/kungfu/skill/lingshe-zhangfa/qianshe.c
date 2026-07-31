// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int count;
        int lvl;
        int i, ap, dp;
 
        if (userp(me) && ! me->query("can_perform/lingshe-zhangfa/qianshe"))
                return notify_fail("你不会使用「千蛇出洞」。\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("「千蛇出洞」只能对战斗中的对手使用。\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("你必须手持一把杖才能施展「千蛇出洞」！\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的内功火候不够，难以施展「千蛇出洞」！\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你的真气不够，无法施展「千蛇出洞」！\n");

        if ((lvl = (int)me->query_skill("lingshe-zhangfa", 1)) < 120)
                return notify_fail("你的灵蛇杖法还不到家，无法使用千蛇出洞！\n");

        if (me->query_skill_mapped("staff") != "lingshe-zhangfa")
                return notify_fail("你没有激发灵蛇杖法，无法使用千蛇出洞！\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "大喝一声，扑身上前，手中的" + weapon->name() +
              HIW "化作万道光芒，一齐射向$n" HIW "！\n" NOR;

        ap = ap_power(me, "staff"); 

        dp = dp_power(target, "parry"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIY "$n" HIY "见$N" HIY "把" + weapon->name() +
                       HIY "使得活灵活现，犹如真物一般，实在是难以抵挡，只有后退。\n" NOR;
                count = lvl / 6;
                me->add_temp("apply/attack", count);
        } else
                count = 0;

        message_combatd(msg, me, target);
        me->add("neili", -100);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(2) && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(5));
        return 1;
}

