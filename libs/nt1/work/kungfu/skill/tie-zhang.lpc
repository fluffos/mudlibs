// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N右掌一拂而起，施出「推窗望月」自侧面连消带打，登时将$n力道带斜",
        "$N施出「分水擒龙」，左掌陡然沿着伸长的右臂一削而出，斩向$n的$l",
        "$N一招「白云幻舞」，双臂如旋风一般一阵狂舞，刮起一阵旋转的气浪",
        "$N陡然一招「掌内乾坤」，侧过身来，右臂自左肋下翻出，直拍向$n而去",
        "$N一招「落日赶月」，伸掌一拍一收，顿时一股阴柔无比的力道向$n迸去",
        "$N身行暴起，一式「蛰雷为动」，双掌横横向$n切出，呜呜呼啸之声狂作",
        "$N一招「天罗地网」，左掌大圈而出，右掌小圈而发，两股力道同时击向$n",
        "$N施一招「五指幻山」，单掌有如推门，另一掌却是迅疾无比的一推即收",
        "$N突然大吼一声，一招「铁掌神威」，身行疾飞而起，再猛向$n直扑而下",
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

int valid_learn(object me)
{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练铁掌掌法必须空手。\n");

        if (me->query("str") < 32)
                return notify_fail("你的先天臂力孱弱，难以修炼铁掌掌法。\n");

        if (me->query("con") < 32)
                return notify_fail("你的先天根骨孱弱，难以修炼铁掌掌法。\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("你的内力修为太弱，难以修炼铁掌掌法。\n");

        if ((int)me->query_skill("force") < 230)
                return notify_fail("你的内功火候不足，难以修炼铁掌掌法。\n");

        if ((int)me->query_skill("strike", 1) < 150)
                return notify_fail("你的基本掌法火候不够，难以修炼铁掌掌法。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("tie-zhang", 1))
                return notify_fail("你的基本掌法水平有限，无法领会更高深的铁掌掌法。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(120), 
                "attack": 80 + random(10), 
                "dodge" : 80 + random(10), 
                "parry" : 80 + random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int practice_skill(object me)
{
        int cost;
        
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练铁掌掌法必须空手。\n");

        if ((int)me->query("qi") < 90)
                return notify_fail("你的体力太低了。\n");

        cost = me->query_skill("tie-zhang", 1) / 5 + 80;

        if ((int)me->query("neili") < cost)
                return notify_fail("你的内力不够练铁掌掌法。\n");

        me->receive_damage("qi", 80);
        me->add("neili", -cost);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("tie-zhang", 1);

        if (damage_bonus < 150 || lvl < 150)
                return 0;

        if (damage_bonus / 6 > victim->query_con()
            && random(2) == 1)
        {
                victim->receive_wound("qi", (damage_bonus - 95) / 3, me);

                return random(2) ? HIR "只听$n" HIR "前胸「咔嚓」一声脆响，竟像是"
                                   "肋骨断折的声音。\n" NOR:

                                   HIR "$n" HIR "一声惨叫，胸前「咔嚓咔嚓」几声脆"
                                   "响，口中鲜血狂喷。\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"tie-zhang/" + action;
}

