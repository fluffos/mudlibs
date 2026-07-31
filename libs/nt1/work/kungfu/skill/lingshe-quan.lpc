// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// lingshe-quan 灵蛇拳

inherit SKILL;
string *action_msg = ({
        "$N左掌护胸，右臂微举作蛇形，续而向外疾伸，一式「灵蛇出洞」攻向$n的$l",
        "$N使出「画蛇添足」，双手向$n抓去，同时又无声无息地一脚踢向$n的$l",
        "只见$N跌扑于地，突然反蹦起使出一招「杯弓蛇影」，恶狠狠的抓向$n的$l",
        "$N一式「蛇鹰互搏」，双手带着嘶嘶破空之声，猛烈迅速地尽往$n上身要害攻击",
        "$N双手徊旋中幻出万道蛇影，一招「万蛇汹涌」，诡异奇玄、铺天盖地推向$n",
        "$N出其不意地使一式「白蛇吐信」，右手食中两指微分，闪电般地往$n的$l猛捅",
        "突见$N双臂柔若无骨地伸缩着，使出「蛇磐青竹」缠住$n，右臂却悄悄地从不可思议处抹到$n的$l",
        "$N双臂一绞，出其不意地使一式「巴蛇吞象」，双手匪夷所思的一扭，缠向$n的$l",
        "$N手脚不抬，使出一式「腾蛇起雾」，身形凌空拔起，飞身撞向$n的$l",
});

int valid_enable(string usage) { return usage == "cuff" ||  usage == "parry"; }
int valid_combine(string combo) { return combo == "shedu-qiqiao"; }

int valid_learn(object me)
{ 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练灵蛇拳必须空手。\n");

        if ((int)me->query_skill("hamagong", 1) < 50)
                return notify_fail("你的蛤蟆功火候不够，无法学灵蛇拳。\n");

        if ((int)me->query("max_neili") < 20)
                return notify_fail("你的内力太弱，无法练灵蛇拳。\n"); 
                
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 240 + random(60), 
                "attack": 50 + random(10), 
                "dodge" : 50 + random(10), 
                "parry" : 50 + random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练灵蛇拳。\n");
        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"lingshe-quan/" + action;
}

