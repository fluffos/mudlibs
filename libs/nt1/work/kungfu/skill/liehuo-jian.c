// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// liehuo-jian.c 烈火剑

inherit SKILL;

string *action_msg = ({
        "$N一招「四海云飘」，$w似幻出片片白云，四面八方的罩向$n",
        "$N一招「四通八达」，剑锋乱指，攻向$n，$n根本不能分辩$w的来路",
        "$N使出「在天一方」，$w幻一条飞练，带着一股寒气划向$n的$l",
        "$N身子向上弹起，左手下指，一招「怪蟒翻身」，右手$w带着一团剑花，逼向$n的$l",
        "$N一招「飞瀑倒悬」，左脚跃步落地，右手$w幻成一条雪白的瀑布，扫向$n的$l",
        "$N右腿半屈般蹲，$w平指，一招「无声无色」，剑尖无声无色的慢慢的刺向$n的$l",
        "$N一招「万川归海」，$w在$n的周身飞舞，令$n眼花缭乱，剑身在半空中突然停住刺向$n的$l",
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("shenghuo-shengong", 1) < 20)
                return notify_fail("你的圣火神功火侯太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(40),
                "attack": 50 + random(10),
                "dodge" : 50 + random(10),
                "parry" : 50 + random(10),
                "damage_type" : random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力不够练烈火剑法。\n");
        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练烈火剑法。\n");
                
        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liehuo-jian/" + action;
}

