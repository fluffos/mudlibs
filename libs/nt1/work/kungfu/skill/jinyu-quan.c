// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jinyu-quan.c 金玉拳

inherit SKILL;

string *action_msg = ({
        "$N一招「金光灿烂」，双拳一上一下, 向$n挥去",
        "$N一招「其利断金」，幻出一片拳影，气势如虹，击向$n的头部",
        "$N身影向上飘起，脸浮微笑，一招「蓝田美玉」，轻轻拍向$n的$l",
        "$N一招「金玉其外」，双拳一合，$n只觉到处是$N的拳影",
        "$N绕着$n一转，满场游走，拳出如风，不绝击向$n，正是一招「金玉满堂」",
        "$N一式「点石成金」，脚步一阵加快，猛的绕到$n的侧面，双拳用力砸向$n$l",
        "$N一招「众口铄金」，扑向$n，似乎$n的全身都被拳影笼罩",
});

int valid_enable(string usage) { return usage == "cuff" || usage == "parry"; }

int valid_combine(string combo) { return combo == "wuluo-zhang"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("kurong-changong",1) < 20)
                return notify_fail("你的枯荣禅功火候不够，无法练金玉拳。\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练金玉拳必须空手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练金玉拳。\n");
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
                "damage_type" : random(2)?"内伤":"瘀伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够练金玉拳。\n");
        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinyu-quan/" + action;
}

