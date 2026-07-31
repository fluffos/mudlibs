// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// xiaoyaoyou.c 逍遥游（丐帮）

inherit SKILL;

string *dodge_msg = ({
        "$n一个「蜻蜓点水」，躲过了$N这一招。\n",
        "$n身形向后一纵，使出一招「细胸巧翻云」，避过了$N的攻击。\n",
        "$n使出「虚怀若谷」，恰好躲过了$N的攻势。\n"
        "但是$n身形飘忽，轻轻一纵，早已避开。\n",
        "$n身形微晃，有惊无险地避开了$N这一招。\n"
});

string *action_msg = ({
        "$N一掌轻出，一招「清风斜雨」直袭$n的$l，了无半点痕迹",
        "$N转过身来，一招「垂钓江畔」，左脚轻点，右掌挥向$n的脸部",
        "$N虚步侧身，一招「落叶雅意」，手腕一转，劈向$n",
        "$N一招「归路未晓」，双掌化作无数掌影，轻飘飘的拍向$n",    
        "$N一招「春风拂柳」，左掌手指微微张开，拂向n的手腕",    
        "$N使出一招「逍遥世间」，一掌拍出，仿佛不食半点人间烟火",  
        "$N身形飘忽，一招「我心犹怜」，双掌软绵绵的拍向$n",
});

int valid_enable(string usage)
{
        return usage == "dodge"
            || usage == "parry"
            || usage == "strike";
}

int valid_combine(string combo) { return combo=="jueming-tui"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("学习逍遥游拳法必须空手。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的内功火候不够，无法学逍遥游掌法。\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("你的内力修为太弱，无法练逍遥游掌法。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("xiaoyaoyou", 1))
                return notify_fail("你的基本掌法水平有限，无法领会更高深的逍遥游掌法。\n");

        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("xiaoyaoyou", 1))
                return notify_fail("你的基本轻功水平有限，无法领会更高深的逍遥游掌法。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(50), 
                "attack": 60 + random(10), 
                "dodge" : 60 + random(10), 
                "parry" : 60 + random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太差了，不能练逍遥游拳法。\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力太差了，不能练逍遥游拳法。\n");

        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xiaoyaoyou/" + action;
}

