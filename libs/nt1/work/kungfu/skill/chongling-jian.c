// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chongling-jian.c 冲灵剑法

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「青梅如豆」，手中$w豆粒般刺向$n的$l",
        "damage" : 105,
        "parry"  : 40,
        "dodge"  : 45,
        "attack" : 47,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「柳叶似眉」，手中$w飘忽不定，刺向$n的$l",
        "damage" : 130,
        "parry"  : 40,
        "dodge"  : 45,
        "attack" : 47,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「雾中初见」，$w化成千百剑影，向$n劈砍下去",
        "parry"  : 40,
        "dodge"  : 45,
        "attack" : 47,
        "damage" : 115,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，手中$w使出「雨后乍逢」直刺$n的$l",
        "parry"  : 49,
        "dodge"  : 48,
        "attack" : 42,
        "damage" : 120,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w一晃，迸出无数道劲气，使出「同生共死」直刺$n的周身大穴",
        "parry"  : 40,
        "dodge"  : 45,
        "attack" : 50,
        "damage" : 135,
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("zixia-shengong", 1) < 20)
                return notify_fail("你的紫霞神功火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("chongling-jian",1);
        for( i = sizeof(action); i > 0; i-- )
                if( level > action[i-1]["lvl"] )
                {
                        return action[NewRandom(i, 20, level/5)];
                }
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练冲灵剑法。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够。\n");
        me->receive_damage("qi", 40);
        me->add("neili", -40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"chongling-jian/" + action;
}


