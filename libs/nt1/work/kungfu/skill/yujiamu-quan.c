// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yujiamu-quan 金刚瑜珈母拳

inherit SKILL;

mapping *action_msg = ({
        "$N单拳「灌顶」，迳直向$n的天灵盖劈下",
        "$N双手摆「解苦」式，握拳侧置于身，眼望右上方，忽的跃起口中暴喝，一拳捣向$n的$l",
        "$N收脸「颦眉」，左手虚掩，右拳穿出，拳势如焰吡啪爆响地击往$n$l",
        "$N吟无主咒，一式「嗔恚」，收拳出拐，磕向$n的$l",
        "$N作「静寂」式，低伏在地，猛然翻身跳起，双手双脚齐出，将$n笼罩在拳风下",
        "$N左臂微抬，心念「妙音」，握拳如钩，击向$n的$l",
        "$N脚踏空行步，使出一招「明心」，绕到$n身侧，双拳张开，插向$n的$l",
        "$N双拳置于身后，微笑中后退两步，趁$n迟疑间豁然冲上，一招「制胜」双拳贯向$n两耳",
});

int valid_enable(string usage) { return  usage == "cuff" || usage == "parry"; }

int valid_combine(string combo) { return combo == "dashou-yin"; } 

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练金刚瑜珈母拳法必须空手。\n");
        if ((int)me->query_skill("longxiang-gong", 1) < 10
        &&  (int)me->query_skill("xuehai-mogong", 1) < 10)
        {
                return notify_fail("你的内功修为火候不够，无法学金刚瑜珈母拳法。\n");
        }
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练金刚瑜珈母拳法。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(50), 
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
                return notify_fail("你的内力不够练金刚瑜珈母拳法。\n");
        me->receive_damage("qi", 40);
        me->add("neili", -40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yujiamu-quan/" + action;
}

