// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// shenlong-bashi 神龙八式

inherit SKILL;

string *action_msg = ({
        "$N使一招「疏影横斜」，左手轻轻一抹，向$n的$l拍去",
        "$N鼓气大喝，双掌使一招「五丁开山」，推向$n的$l",
        "$N顺势使一招「风行草偃」，移肩转身，左掌护面，右掌直击$n",
        "$N退后几步，突然反手一掌，一招「神龙摆尾」，无比怪异地击向$n",
        "$N使一式「风卷残云」，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
        "$N忽的使出「乾坤倒旋」，以手支地，双腿翻飞踢向$n",
        "$N大吼一声，使出「同归于尽」，不顾一切般扑向$n",
        "$N深吸一口气，身体涨成球状，猛然流星赶月般直撞向$n",
});

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }

int valid_combine(string combo) { return combo == "huagu-mianzhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练神龙八式必须空手。\n");
        if ((int)me->query_skill("shenlong-xinfa", 1) < 25)
                return notify_fail("你的神龙心法火候不够，无法学神龙八式.\n");
        if ((int)me->query_skill("force", 1) < 25)
                return notify_fail("你的基本内功火候不够，无法学神龙八式。\n");
        if ((int)me->query("max_neili") < 150)
                return notify_fail("你的内力太弱，无法练神龙八式。\n");
        if (2*(int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shenlong-bashi",1))
                return notify_fail("你的神龙心法火候不够，无法继续学神龙八式。\n");
        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("shenlong-bashi", 1))
                return notify_fail("你的基本手法水平有限，无法学习更高深的神龙八式。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force" : 320 + random(60),
                "attack": 50 + random(10), 
                "dodge" : 50 + random(10), 
                "parry" : 50 + random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练神龙八式。\n");
        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"shenlong-bashi/" + action;
}


