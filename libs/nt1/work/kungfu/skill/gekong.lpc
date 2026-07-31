// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// nianhua-zhi.c 拈花指

inherit SHAOLIN_SKILL;

string *action_msg = ({
        "$N侧身抬臂，右指划了个半圈，一式「瓶花落砚」击向$n的$l",
        "$N左掌虚托，一式「寒梅吐蕊」，右指穿腋疾出，指向$n的胸前",
        "$N俯身斜倚，左手半推，右手一式「初杏问酒」，向$n的$l划过",
        "$N双目微睁，一式「露草斜阳」，双手幻化出千百个指影，拂向$n的$l",
        "$N一式「仰月承霖」，左掌护住丹田，右手斜指苍天，蓄势点向$n的$l",
        "$N双掌平托胸前，十指叉开，一式「叶底留莲」，指向$n的周身大穴",
        "$N双掌翻飞，一式「清风拂桂」，指端迸出无数道劲气，射向$n的全身",
        "$N一式「菊圃秋霜」，并指如刃，一束束锐利无俦的刀气，凌虚向$n的$l砍去",
        "$N一式「伽叶微笑」，双手食指交叉，指端射出一缕罡气，穿过$n的$l",
        "$N左掌竖立胸前，一式「佛祖拈花」，右手食指扣住拇指，轻轻对着$n一弹",
});

int valid_enable(string usage) { return usage == "finger" || usage == "unarmed"; }

int valid_combine(string combo) { return combo == "sanhua-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练拈花指必须空手。\n");

        if ((int)me->query_skill("force") < 60)
                return notify_fail("你的内功火候不够，无法学拈花指。\n");

        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力太弱，无法练拈花指。\n");

        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("nianhua-zhi", 1))
                return notify_fail("你的基本指法水平有限，无法领会更高深的拈花指。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 320 + random(120),
                "attack": 60 + random(10),
                "dodge" : 60 + random(10),
                "parry" : 60 + random(10),
                "damage_type" : "刺伤",
        ]);        
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够练拈花指。\n");

        if( (int)me->query_skill("jingang-quan", 1) < 120 )
                return notify_fail("你的大金刚拳修为还不够。\n");

        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"gekong/" + action;
}

int query_effect_finger(object attacker, object me)
{
        int lvl;

        if (objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("gekong", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

