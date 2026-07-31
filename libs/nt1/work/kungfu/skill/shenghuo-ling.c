// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        "$N踏上一步，忽地在地上一坐，已抱住了$n小腿。十指扣向$n小腿上的中都和"
                  "\n筑宾两穴",
        "突然之间，$N身形晃动，同时欺近，手中$w往$n身上划去。脚下不知如何移动，"
                  "\n身形却已早变。右手同时抓向$n的后领",
        "$N欺身直进，左手持$w向$n天灵盖上拍落。便在这一瞬之间，$n滚身向左，已"
                  "\n然一拳打向$n腿部。$n一个踉跄，$N横过$w戳向$n后心",
        "$N忽地放手，手中那柄$w尾端向上弹起，直奔$n手腕。",
        "$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一阵"
                  "\n凉风，只见$N手肘袭来",
        "$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一麻，"
                  "\n$N手中$w急挥横扫，突然连翻三个空心筋斗，$w已到$n右肩",
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
/*
        if (me->query("int") < 32)
                return notify_fail("你先天悟性不足，无法领会圣火令法。\n");
*/

        if (me->query("character") == "光明磊落") 
                return notify_fail("你心中暗想：我为人光明磊落，岂能学习这种武功？\n"); 

        if (me->query("character") == "心狠手辣") 
                return notify_fail("你心中暗想：我虽然不是谦谦君子，但这种损人不利己的武功学来何用？\n"); 

        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("你的内功火候不到，无法学习圣火令法。\n");

        if ((int)me->query_skill("sword", 1) < 200)
                return notify_fail("你的基本剑法火候不到，无法学习圣火令法。\n");

        if (me->query("max_neili") < 2400)
                return notify_fail("你的内功修为不足，无法学习圣火令法。\n");

        if (me->query_str() < 35)
                return notify_fail("你现在膂力太差，无法学习圣火令法。\n");

        if (me->query_int() < 40)
                return notify_fail("你现在无法领悟圣火令法的要诣。\n");

        if (me->query_dex() < 35)
                return notify_fail("你现在身法太差，无法学习圣火令法。\n");

        if (me->query_skill("force", 1) < me->query_skill("shenghuo-ling", 1))
                return notify_fail("你的内功修为不足，无法领会更高深的圣火令法。\n");

        if (me->query_skill("shenghuo-ling", 1) > 200)
        {
                 if (me->query_skill("shenghuo-ling", 1) > 
                     me->query_skill("shenghuo-shengong", 1))
                            return notify_fail("你的圣火神功水平有限，无法领会"
                                               "更高深的圣火令法。\n");
        }

        if (me->query_skill("sword", 1) < me->query_skill("shenghuo-ling", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的圣火令法。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 140 + random(80),
                "attack": 80 + random(10),
                "dodge" : 80 + random(10),
                "parry" : 80 + random(10),
                "damage_type" : random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) || 
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (me->query_skill("shenghuo-ling", 1) < 180)
                return notify_fail("你还没有掌握圣火令法中所有的奥妙，无法"
                                   "通过锻炼获得提升。\n");

        if ((int)me->query("qi") < 90)
                return notify_fail("你的体力不够练圣火令法。\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("你的内力不够练圣火令法。\n");

        me->receive_damage("qi", 80);
        me->add("neili", -80);

        return 1;
}

// 对应perform canxue出现额外的攻击效应。
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (me->query_temp("shenghuo-ling/max_hit"))
        {
                victim->receive_wound("qi", damage_bonus);
                return HIR "只听“噗嗤”一声，一股鲜血至$n" HIR "胸前射出！"
                       "\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"shenghuo-ling/" + action;
}

