// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// fengyun-shou.c -风云手

inherit SHAOLIN_SKILL;

string *action_msg = ({
        "$N一式「风满长空」，以掌化爪，五指如钩，直逼$n的膻中要穴",
        "$N左手虚晃，一式「烈火腾云」，右手上下直击，反扣$n的肩井大穴",
        "$N使一式「草深雾泽」，掌指齐出，拍拿并施，拿向$n的三路要害",
        "$N左手鹰抓，右手蛇举，一式「天目昭辉」疾扣$n的中节大脉",
        "$N使一式「雷震四方」，四面八方出现无数掌影，一爪突出，抓向$n的胸口",
        "$N两手环扣，全身关节啪啪作响，一式「水到渠成」，击向$n的$l",
        "$N一式「山高林密」，十指齐伸，遮天蔽日般地笼罩$n的全身要穴",
        "$N岳立霆峙，一式「地老天荒」，在一阵暴雷声中，双手同时拍中$n的七道死穴",
});

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }

int valid_combine(string combo) { return combo == "yingzhua-gong"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练风云手必须空手。\n");

        if ((int)me->query_skill("force") < 40)
                return notify_fail("你的内功火候不够，无法学风云手。\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力太弱，无法练风云手。\n");

        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("fengyun-shou", 1))
                return notify_fail("你的基本手法水平有限，无法领会更高深的风云手。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 240 + random(50), 
                "attack": 40 + random(10), 
                "dodge" : 40 + random(10), 
                "parry" : 40 + random(10), 
                "damage_type" : random(2)?"内伤":"瘀伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练风云手。\n");

        if( (int)me->query_skill("luohan-quan", 1) < 30 )
                return notify_fail("你的罗汉拳修为还不够。\n");

        me->receive_damage("qi", 40);
        me->add("neili", -40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"fengyun-shou/" + action;
}


