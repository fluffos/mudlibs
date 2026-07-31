// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// longcheng-shendao.c 龙城神刀

inherit SKILL;

string *action_msg = ({
        "$N手中$w轻挥，一招「冬去春来」，身形一转，一刀向$n的$l撩去",
        "$N一招「月上西楼」，左脚虚点，$w一收一推，平刃挥向$n的脸部",
        "$N虚步侧身，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
        "$N一招「梦断巫山」，$w自上而下划出一个大弧，笔直劈向$n",    
        "$N侧步拧身，一招「似是而非」，拦腰反切，$w砍向$n的胸口",    
        "$N挥舞$w，使出一招「月挂中天」，幻起片片刀影，齐齐罩向$n",
        "$N一招「日月交辉」，只见漫天刀光闪烁，重重刀影向$n的全身涌去",
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("blade", 1) < 80)
                return notify_fail("你的基本刀法火候不够。\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("longcheng-shendao", 1))
                return notify_fail("你的刀法水平有限，无法领会更高深的龙城神刀。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 120 + random(30), 
                "attack": 70 + random(10),
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage_type" : random(2) ? "挫伤" : "割伤", 
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力不够练龙城神刀。\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练龙城神刀。\n");

        me->receive_damage("qi", 70);
        me->add("neili", -68);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"longcheng-shendao/" + action;
}
