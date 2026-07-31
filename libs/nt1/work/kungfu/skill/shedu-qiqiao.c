// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// shedu-qiqiao.c

inherit SKILL;

string *action_msg = ({
        "$N左指挥出，一式「青蛇挺身」，削向$n的掌缘",
        "$N全身之力聚于一指，一式「银蛇吐信」，指向$n的胸前",
        "$N左掌贴于神道穴，右手一式「金蛇摆尾」，向$n的$l划过",
        "$N双目怒视，一式「蝮蛇捕食」，双指拂向$n的额、颈、肩、臂、胸、背",
        "$N一式「待机而行」，左掌掌心向外，右指蓄势点向$n的$l",
        "$N右手伸出，十指叉开，一式「猛蛇出洞」，小指拂向$n的太渊穴",
        "$N双迸出无数道劲气，一式「千蛇缠身」射向$n的全身",
});

int valid_enable(string usage) { return usage=="finger" || usage=="poison"; }

int valid_combine(string combo) { return combo == "lingshe-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练蛇毒奇巧必须空手。\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("你的内功火候不够，无法学蛇毒奇巧。\n");

        if ((int)me->query("max_neili") < 350)
                return notify_fail("你的内力太弱，无法练蛇毒奇巧。\n");

        if ((int)me->query_skill("poison", 1) < 30)
                return notify_fail("你的基本毒技火候不够，无法学蛇毒奇巧。\n");

        if ((int)me->query_skill("poison", 1) < (int)me->query_skill("shedu-qiqiao", 1))
                return notify_fail("你的基本毒技水平有限，无法领会更高深的蛇毒奇巧。\n");

        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("shedu-qiqiao", 1))
                return notify_fail("你的基本指法水平有限，无法领会更高深的蛇毒奇巧。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(30), 
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
                return notify_fail("你的内力不够练蛇毒奇巧。\n");

        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"shedu-qiqiao/" + action;
}
