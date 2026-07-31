// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit SKILL;

string *action_msg = ({
        "$N身形斜飞，手中$w轻轻点向$n的腕部",
        "$N长跃而起，$w猛然下刺，直打$n腕部的神门穴",
        "$N手中$w自上而下反刺，模拟冰轮横空、清光铺地的光景",
        "$N手中$w颤动，如鲜花招展来回挥削，只幌得$n眼花撩乱，浑不知从何攻来",
        "$N手中$w由内自外一刺，左手虚击而去，身形一晃，$w已搭在了$n的腕部",
        "$N左掌横摆胸前，右手中$w轻轻挥拂，直取$n的神门要穴",
        "$N手中$w中宫直入，携着强大的劲道攻向$n的$l",
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 60)
                return notify_fail("你的内功火候不到，无法学习神门十三剑。\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("你的内力太差，无法学习神门十三剑。\n");

        if (me->query_skill("sword", 1) < me->query_skill("shenmen-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的神门十三剑。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(40),
                "attack": 60 + random(10),
                "dodge" : 60 + random(10),
                "parry" : 60 + random(10),
                "damage_type" : random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力不够练神门十三剑。\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不足以练神门十三剑。\n");

        me->receive_damage("qi", 62);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenmen-jian/" + action;
}


