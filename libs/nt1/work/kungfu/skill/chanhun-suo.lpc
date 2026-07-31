// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        "$N单手一扬，一招「虐目」，手中$w抖得笔直，直点$n的双眼",
        "$N力贯鞭梢，一招「伤肝」，手中$w舞出满天鞭影，横扫$n腰间",
        "$N运气于腕，一招「损心」，手中$w向一根铜棍般直击$n胸部",
        "$N单臂一挥，一招「催胆」，手中$w直击向$n腰肋",
        "$N高高跃起，一招「摄魄」，手中$w笔直向$n当头罩下",
        "$N身形一转，一招「收魂」，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        object weapon;

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("你必须先找一条鞭子才能练习缠魂索。\n");

        if( (int)me->query("max_neili") < 400 )
                return notify_fail("你的内力不足，没有办法练习缠魂索。\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("whip", 1) < 60)
                return notify_fail("你的基本鞭法火候太浅。\n");

        if ((int)me->query_skill("whip", 1) < (int)me->query_skill("chanhun-suo", 1))
                return notify_fail("你的基本鞭法水平有限，无法领会更高深的缠魂索。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 110 + random(20),
                "attack": 50 + random(10),
                "dodge" : 50 + random(10),
                "parry" : 50 + random(10),
                "damage_type" : random(2)?"劈伤":"刺伤", 
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力不够练缠魂索。\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练缠魂索。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"chanhun-suo/" + action;
}

