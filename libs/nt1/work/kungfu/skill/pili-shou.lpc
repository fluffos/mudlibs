// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// pili-shou.c 混元霹雳手

inherit SKILL;

string *action_msg = ({
        "$N一式「五指连心」，右掌直取$n的$l",
        "$N大喝一声，一式「火上心头」，双掌掌力雄浑无比，连连拍向$n的$l",
        "$N使一式「混元无际」，左掌虚出，右掌猛然跟进，直取$n的$l",
        "$N两掌一分，一式「晴空霹雳」，隐隐带有风雷之势，向$n劈去",
        "$N身形一转，使出一式「混元刀」，但见$N右掌犹如一把利刀直下，劈向$n",
        "$N突然飞身而起，使出一式「霹雳雨」，双掌连连而出，犹如暴雨般拍向$n全身",
        "$N使一式「晴空万里」，双掌一分，猛地劈向$n的$l",
        "$N一招「烈炎飞空」，双掌带着萧瑟的烈炎之气，拍向$n的$l",
        "$N身法陡然一变，使出一式「混阳式」，掌影千变万幻，令$n无法躲闪",
        "$N清啸一声，一式「雄心万里」，双掌挥舞，气势非凡，击向$n的$l",
});

int valid_enable(string usage)
{
        return usage == "hand" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练混元霹雳手必须空手。\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("你的内功火候不够，无法练混元霹雳手。\n");

        if ((int)me->query("max_neili") < 900)
                return notify_fail("你的内力太弱，无法练混元霹雳手。\n");

        if ((int)me->query_skill("hand", 1) < 80)
                return notify_fail("你的基本手法火候不够，无法练混元霹雳手。\n");

        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("pili-shou", 1))
                return notify_fail("你的基本手法水平有限，无法领会更高深的混元霹雳手。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 320 + random(60),
                "attack": 60 + random(10),
                "dodge" : 60 + random(10),
                "parry" : 60 + random(10),
                "damage_type" : random(2)?"瘀伤":"内伤",
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够练混元霹雳手。\n");

        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pili-shou/" + action;
}

