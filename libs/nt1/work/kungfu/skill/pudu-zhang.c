// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// pudu-zhang.c 普渡杖法

inherit SHAOLIN_SKILL;

string *action_msg = ({
        "$N使一招「黄牛转角」，手中$w自下而上，沉猛无比地向$n的小腹挑去。",
        "$N快步跨出，一招「野马追风」，左手平托$w，右掌猛推杖端，顶向$n的胸口。",
        "$N高举$w，一招「猛虎跳涧」，全身跃起，手中$w搂头盖顶地向$n击去。",
        "$N一招「狮子摇头」，双手持杖如橹，对准$n猛地一搅，如同平地刮起一阵旋风。",
        "$N横持$w，一招「苍龙摆尾」，杖端化出无数个圆圈，凝滞沉重，把$n缠在其中。",
        "$N全身滚倒，$w盘地横飞，突出一招「大蟒翻身」，杖影把$n裹了起来",
        "$N双手和十，躬身一招「胡僧托钵」，$w自肘弯飞出，拦腰向$n撞去。",
        "$N一招「慈航普渡」，$w如飞龙般自掌中跃出，直向$n的胸口穿入。",
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力不够，无法学习普渡杖法。\n");

        if ((int)me->query_skill("force") < 60)
                return notify_fail("你的内功火候太浅，无法学习普渡杖法。\n");

        if ((int)me->query_skill("staff", 1) < (int)me->query_skill("pudu-zhang", 1))
                return notify_fail("你的基本杖法水平有限，无法领会更高深的普渡杖法。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 120 + random(30), 
                "attack": 50 + random(10),
                "dodge" : 50 + random(10),
                "parry" : 50 + random(10),
                "damage_type": "挫伤", 
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if (me->query_str() < 20)
                return notify_fail("你的臂力不够练普渡杖法。\n");
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力不够练普渡杖法。\n");
        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("luohan-quan", 1) < 30)
                return notify_fail("你的罗汉拳修为还不够。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pudu-zhang/" + action;
}
