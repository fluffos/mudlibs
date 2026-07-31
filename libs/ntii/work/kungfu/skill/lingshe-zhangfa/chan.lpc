// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chan.c 灵蛇缠身

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/lingshe-zhangfa/chan")) 
                return notify_fail("你还没有受过高人指点，无法施展「灵蛇缠身」。\n");  
                 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("「灵蛇缠身」只能对战斗中的对手使用。\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("运用「灵蛇缠身」手中必须持杖！\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("你的内功火候不够！\n");

        if ((int)me->query_skill("staff") < 80)
                return notify_fail("你的杖法还不到家，无法使用「灵蛇缠身」！\n");

        if (target->is_busy())
                return notify_fail("对方正忙着呢，你还是加紧进攻吧！\n");
                
        if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIG "$N" HIG "手中的" + weapon->name() +
              HIG "不住的颤动，活现一条灵蛇，缠向$n" HIG "，难以捉摸。\n" NOR;

        ap = ap_power(me, "staff"); 

        dp = dp_power(target, "dodge"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIY "$n" HIY "仓皇之下只有严守门户，无暇反击！\n" NOR;
                target->start_busy(ap / 100 + 2);
        } else 
        {
                msg += HIC "可是$p" HIC "看破了$N" HIC
                       "的虚招，巧妙的运用身法躲过了$P的攻击！" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

