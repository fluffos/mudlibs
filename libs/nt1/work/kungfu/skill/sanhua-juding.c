// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// sanhua-juding.c 三花聚顶掌

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N一式「燕抬腮」，右拳斜引，左掌疾出，砰的一响，打向$n腮部",
        "$N左掌虚抬，侧身转向，右掌斜穿而出，使出「猿献果」疾切$n的咽喉",
        "$N使一式「大关门」，转身抬肘，右掌内穿，夹带风雷之声打向$n的$l",
        "$N左掌虚拍，$n向右一躲，$N右掌嘭地打出，这一掌正是「虎门手」",
        "$N使出「揩磨尘垢」，右手倏地穿出，食中二指张开，手腕向内略转，右肘撞向$n对方鼻梁",
        "$N手肘猛地往$n胸口撞去，乘$n疼痛，已借势跃起，反手一推，使的正是一招「无欠无馀」",
        "$N右腿向前弓步，一招「红霞贯日」，左手化拳为掌，劲气十足，闪电般地拍向$n的胸口",
        "$N左掌虚晃，右掌往$n左颊斜劈下去，这一招「紫电穿云」却是极精妙的上乘招数，\n"
        "手掌到了中途，去向突换，明明劈向左颊，掌缘却要斩在敌人右颈",
});

int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }

int valid_combine(string combo) { return combo == "chunyang-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练三花聚顶掌必须空手。\n");
                
        if ((int)me->query_skill("xiantian-gong", 1) < 20)
                return notify_fail("你的玄门先天功火候不够，无法学三花聚顶掌。\n");
                
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练三花聚顶掌。\n");
                
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(70), 
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
                
        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练三花聚顶掌。\n");
                
        me->receive_damage("qi", 60);
        me->add("neili", -50);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"sanhua-juding/" + action;
}


