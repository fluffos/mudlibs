// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit SKILL;

string *action_msg = ({
        "$N施展出一招「雷风指」，右手拇指直刺$n$l处的要穴所在",
        "$N使一招「山泽指」，左手轻轻一挥，右手刺向$n的檀中大穴",
        "$N双掌翻飞，一招「乾坤指」，暗藏玄机，中指戳向$n的$l",
        "$N一声大喝，一式「太阴指」，双指齐出，攻向$n的胸口和$l",
        "$N连上数步，一招「少阳指」，左掌劈向$n，右手却暗袭$n的$l",
        "$N双手不住晃动，缓缓逼近$n，一招「少阴指」，笼罩了$n的$l",
        "$N一招「太阳指」，手指不住晃动，不离$n的$l方寸之间",
});

int valid_enable(string usage)
{
        return usage == "finger" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练乾天指法必须空手。\n");

        if ((int)me->query("neili") < 250)
                return notify_fail("你的内力不够，无法学乾天指法。\n");

        if ((int)me->query_skill("force") < 40)
                return notify_fail("你的内功火候不够，无法学乾天指法。\n");

        if ((int)me->query_skill("finger") < 20)
                return notify_fail("你的基本指法太浅，无法学乾天指法。\n");

        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("qiantian-zhi", 1))
                return notify_fail("你的基本指法水平有限，无法领会更高深的乾天指法。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 260 + random(120),
                "attack": 50 + random(10),
                "dodge" : 50 + random(10),
                "parry" : 50 + random(10),
                "damage_type" : "刺伤",
        ]);        
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练习乾天指法。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"qiantian-zhi/" + action;
}
