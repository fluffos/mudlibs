// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// 逍遥派武功

inherit SKILL;

string *action_msg = ({
        "$N向前斜跨一步，一招「剑气封喉」，手中$w直刺$n的喉部",
        "$N错步上前，一招「明月千里」，剑意若有若无，$w淡淡地向$n的$l挥去",
        "$N一式「怀中抱月」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
        "$N纵身轻轻跃起，一式「大风起兮」，剑光如水，一泻千里，洒向$n全身",
        "$N错步上前，一招「明月千里」，剑意若有若无，$w淡淡地向$n的$l挥去",
        "$N手中$w中宫直进，一式「定天一针」，无声无息地对准$n的$l刺出一剑",
        "$N手中$w一沉，一式「星归月向」，无声无息地滑向$n的$l",
        "$N手中$w斜指苍天，剑芒吞吐，一式「映月无声」，对准$n的$l斜斜击出",
        "$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「情连航慈」刺向$n的咽喉",
        "$N合掌跌坐，一式「影玉徵辉」，$w自怀中跃出，如疾电般射向$n的胸口",
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_skill("force") < 120)
                return notify_fail("你的内功火候不够，不能学习流月剑舞。\n");

        if (me->query_skill("sword", 1) < 80)
                return notify_fail("你的基本剑法火候不够，不能学习流月剑舞。\n");

        if (me->query("max_neili") < 1000)
                return notify_fail("你的内力不够，不能学习流月剑舞。\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("liuyue-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的流月剑舞。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(50),
                "attack": 70 + random(10),
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage_type" : random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力不够练流月剑舞。\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练流月剑舞。\n");

        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liuyue-jian/" + action;
}
