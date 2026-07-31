// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// bizhen-qingzhang.c

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        "$N身形急晃，一跃而至$n跟前，右掌带着切骨之劲砍向$n的$l",
        "$N飞身跃起，双掌至上而下斜砍而出，顿时万千道掌寒劲从四面八方席卷$n",
        "$N平掌为刀，斜斜砍出，幻出一道道刚猛的掌劲如飓风般裹向$n的全身",
        "$N反转右掌护住全身，身形猛跃至$n面前，力注左掌，横向$n拦腰砍去",
        "$N右掌后撤，手腕一翻，猛地挥掌砍出，幻出一道无比凌厉的掌劲直斩向$n的$l",
        "$N双手挥舞出，形成一个大圈，一股劲气澎湃汹涌而来，逼得$n踉踉后退",
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练碧针清掌必须空手。\n");

        if ((int)me->query_skill("force") < 250)
                return notify_fail("你的内功火候不够，无法练习碧针清掌。\n");

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("你的内力太弱，无法练习碧针清掌。\n");

        if ((int)me->query_skill("strike", 1) < 180)
                return notify_fail("你的基本掌法火候不够，无法练习碧针清掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("bizhen-qingzhang", 1))
                return notify_fail("你的基本掌法水平有限，无法领会更高深的碧针清掌。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "attack": 70  + random(10),
                "dodge" : 70  + random(10),
                "parry" : 70  + random(10),
                "force" : 340 + random(100),
                "damage_type" : random(2) ? "内伤" : " 瘀伤",
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练碧针清掌。\n");

        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        mixed result;
        
        if (damage_bonus < 100) return 0;

        if (random(me->query_skill("force")) > victim->query_skill("force") / 2)
        {
                result = ([ "damage" : (damage_bonus - 100) / 2 ]);
                result += ([ "msg" : HIR "只听$n"
                                     HIR "前胸“喀嚓”一声，竟像是肋骨碎断的声音！\n" NOR ]);
                return result;
        }
}

string perform_action_file(string action)
{
        return __DIR__"bizhen-qingzhang/" + action;
}
