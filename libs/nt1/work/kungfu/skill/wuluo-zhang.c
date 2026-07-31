// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wuluo-zhang.c 五罗轻烟掌

inherit SKILL;

string *action_msg = ({
        "$N屏息静气，手起一掌「轻烟袅袅」，轻轻柔柔地拍向$n",
        "$N轻轻浅笑，绕到$n身后，左手做势温柔轻拥$n腰间。$n蹙眉急躲，$N右手一招「烟雾缭绕」，无声无息向$n的$l拍到",
        "$N一招「烟海云涛」，双掌幻化出一片掌影，如一阵轻烟，将$n细细密密地笼罩于内",
        "$N返身越出圈外，回首一招「云烟渺渺」，远远地向$n的$l轻轻拍出两掌，掌风刮到，陡然变盛直让$n呼不出气来",
        "$N左掌从右掌内围翻出，轻飘飘地向$n拍去，看到$n起手招架，右掌却自胸口疾速圈出，\n一招「烟雾弥漫」，赶超左掌，拍向$n的$l",
        "$N双掌齐推，振起一阵劲风，一招「烟消云散」在一丈开外击向$n",
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo) { return combo == "jinyu-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练五罗轻烟掌必须空手。\n");
        if ((int)me->query_skill("kurong-changong", 1) < 20)
                return notify_fail("你的枯荣禅功太弱，无法练五罗轻烟掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练五罗轻烟掌。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(30), 
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
                return notify_fail("你的内力不够练五罗轻烟掌。\n");
        me->receive_damage("qi", 40);
        me->add("neili", -40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuluo-zhang/" + action;
}


