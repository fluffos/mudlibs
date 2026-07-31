// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N使出倚天屠龙掌中的一式"+HIY"『武林至尊』"NOR+"，一笔"
                   "一划，暗含内劲，击向$n的$l",
        "$N使出倚天屠龙掌中的一式"+HIY"『宝刀屠龙』"NOR+"，“龙"
                   "”字笔划甚多，笔划多的不觉其繁，击向$n的$l",
        "$N使出倚天屠龙掌中的一式"+HIY"『号令天下』"NOR+"，“下"
                   "”字笔划甚少，笔划少的不见其陋，击向$n的$l",
        "$N使出倚天屠龙掌中的一式"+HIY"『莫敢不从』"NOR+"，其缩"
                   "也凝重，似尺蠖之屈，其纵也险劲，如狡兔之脱，击\n向$n的$l",
        "$N使出倚天屠龙掌中的一式"+HIY"『倚天不出』"NOR+"，淋漓"
                   "酣畅，雄浑刚健，俊逸处如风飘，如雪舞，厚重处如\n虎蹲，"
                   "如象步，击向$n的$l",
        "$N使出倚天屠龙掌中的一式"+HIY"『谁与争锋』"NOR+"，长啸"
                   "一声，右掌直划下来，当真是星剑光芒，如矢应机，\n霆不暇"
                   "发，电不及飞，这一直乃是“锋”字的最后一笔，直劈向$n的$l",
});

int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }  

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练倚天屠龙掌必须空手。\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("你的内功火候不够，无法练倚天屠龙掌。\n");
        
        if ((int)me->query("max_neili") < 750)
                return notify_fail("你的内力太弱，无法练倚天屠龙掌。\n");

        if ((int)me->query_skill("strike", 1) < 80)
                return notify_fail("你的基本掌法火候不够，无法练习倚天屠龙掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("yitian-zhang", 1))
                return notify_fail("你的基本掌法水平有限，无法领会更高深的倚天屠龙掌。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 340 + random(60), 
                "attack": 70 + random(10), 
                "dodge" : 70 + random(10), 
                "parry" : 70 + random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练倚天屠龙掌。\n");

        me->receive_damage("qi", 70);
        me->add("neili", -70);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yitian-zhang/" + action;
}

