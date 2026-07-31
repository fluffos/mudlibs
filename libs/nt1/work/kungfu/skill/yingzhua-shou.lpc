// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yingzhua-shou.c 搜骨鹰爪功

inherit SKILL;

string *action_msg = ({
        "$N双臂一拢，左爪直攻$n下盘，右爪却挟风雷之势推向$n腰间，一虚一实，正是一招「推爪式」",
        "$N身形陡起，如雄鹰击日般“倏”地从$n头顶越过，使一招「盖爪式」双爪疾向$n脑后击下",
        "$N就地一滚，突然到了$n身前，使一招「掏爪式」，右爪直奔$n小腹",
        "$N左爪护胸，右爪凝劲后发，一招「托爪式」，缓缓托向$n的$l",
        "$N身形诡异，疾速前扑，使一招「撩爪式」，直撩$n裆部",
        "$N身形飘忽，陡然转到$n身后，一招「锁爪式」，双爪直向$n咽喉插下",
        "$N一声厉啸，身形拔起，使出「千爪式」，由半空盘旋下击，$n顿觉漫天爪影，罩向全身死穴",
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_combine(string combo) { return combo == "hanbing-mianzhang"; }  

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练鹰抓擒拿手必须空手。\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法学鹰抓擒拿手。\n");
                
        if ((int)me->query_str() < 24)
                return notify_fail("你的臂力太差，无法学鹰抓擒拿手。\n");
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
                "damage_type" : random(2)?"抓伤":"内伤",
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够练鹰抓擒拿手。\n");
        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yingzhua-shou/" + action;
}

