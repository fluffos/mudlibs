// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// fumo-jian.c 伏魔剑

inherit SHAOLIN_SKILL;

string *action_msg = ({
        "$N一式「穿云势」，剑锋平指，剑势如风，一气呵成横扫$n的腰间",
        "$N向前跃上一步，左手剑诀，右手$w使出一式「破雾势」直刺$n的$l",
        "$N拔步挺腰，一式「推山势」，手中$w沉滞无比，缓缓挥剑撞向$n的$l",
        "$N一式「搅海势」，$w自左而右划出一个大弧，平平地向$n的$l挥去",
        "$N回身拧腰，右手虚抱成圆，一式「开天势」，$w中宫直进，刺向$n的胸口",
        "$N一式「劈地势」，$w从上至下猛劈，剑锋直出，挟爆裂之声骤然斩向$n的$l",
        "$N运气施出「雷针势」，$w剑尖逼出一道青芒，闪电般破空射向$n的$l",
        "$N双腿半屈半蹲，一式「龙吞势」，剑尖划出无数圆圈，狂风骤起，笼罩天地",
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_combine(string combo) { return combo == "cibei-dao"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 250)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 50)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("fumo-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的伏摩剑法。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 120 + random(60), 
                "attack": 70 + random(10),
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage_type": random(2) ? "刺伤" : "割伤", 
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力不够练伏魔剑。\n");
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练伏魔剑。\n");
        if( (int)me->query_skill("qianye-shou", 1) < 100 )
                return notify_fail("你的如来千叶手修为还不够。\n");
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"fumo-jian/" + action;
}


