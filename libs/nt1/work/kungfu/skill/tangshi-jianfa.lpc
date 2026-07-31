// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tangshi-jianfa.c

inherit SKILL;

string *action_msg = ({
        "$N向前跨上一步，同时口中大喊一声，一式「哥翁喊上来」直刺$n的$l",
        "$N向前轻跳，一招「马命风小小」，$w向前轻刺$n的$l",
        "$N左手放在耳朵后面，仿佛在倾听什么，一招「忽听喷惊风」，右手中的$w向前刺向$n的$l",
        "$N一式「连山布若逃」，手中$w的剑势像一疋布一样砍向$n的$l",
        "$N$w胸前一横，一招「是横不敢过」，$w横削$n",
        "$N向后一闪，一招「落泥招大姐」，招手让$n过来，$w随即刺出",
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(20),
                "attack": 60 + random(10),
                "dodge" : 60 + random(10),
                "parry" : 60 + random(10),
                "damage_type" : random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
                
        if ((int)me->query("qi") < 70)
                return notify_fail("你的精力不够练躺尸剑法。\n");
        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够练躺尸剑法。\n");
                
        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}


