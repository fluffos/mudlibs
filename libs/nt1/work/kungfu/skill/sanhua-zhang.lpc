// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// sanhua-zhang.c -散花掌

#include <ansi.h>

inherit SHAOLIN_SKILL;

string *action_msg = ({
        "$N合掌抱球，一式「"HIG"春深芳草尽"NOR"」，双掌变幻吞吐，缓缓推向$n的$l",
        "$N五指绽开，一式「"HIC"夏闲独兰馨"NOR"」，左右掌穿插翻飞，疾向$n的$l拍去",
        "$N使一式「"HIY"秋酣菊霜清"NOR"」，左掌虚托，右掌乍伸乍合，猛地插往$n的$l",
        "$N双掌血红，一式「"HIW"冬卧听梅吟"NOR"」，幻成漫天梅花朵朵，雨点般向$n击去",
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo) { return combo == "nianhua-zhi"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练散花掌必须空手。\n");

        if ((int)me->query_skill("force", 1) < 60)
                return notify_fail("你的内功火候不够，无法学散花掌。\n");

        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力太弱，无法练散花掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("sanhua-zhang", 1))
                return notify_fail("你的基本掌法火候水平有限，无法领会更高深的散花掌。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 340 + random(60), 
                "attack": 60 + random(10), 
                "dodge" : 60 + random(10), 
                "parry" : 60 + random(10), 
                "damage_type" : random(2)?"内伤":"瘀伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够练散花掌。\n");

        if ((int)me->query_skill("weituo-gun", 1) < 60
        &&  (int)me->query_skill("cibei-dao", 1) < 60
        &&  (int)me->query_skill("pudu-zhang", 1) < 60
        &&  (int)me->query_skill("fengyun-shou", 1) < 60)
                return notify_fail("你必须在韦陀棍，慈悲刀，普渡杖，和风云手中任选一门练到一定境界才能练散花掌。\n");

        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"sanhua-zhang/" + action;
}


