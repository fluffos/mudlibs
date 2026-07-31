// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// xumishan-zhang.c 须弥山掌

inherit SHAOLIN_SKILL;

string *action_msg = ({
        "$N前腿踢出，后腿脚尖点地，一式「五丁开山」，双掌直击$n的面门",
        "$N左掌划一半圆，一式「壁立千刃」，右掌斜穿而出，疾拍$n的胸前大穴",
        "$N使一式「云断秦岭」，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
        "$N左掌护胸，右掌凝劲后发，一式「日坠苍山」，缓缓推向$n的$l",
        "$N使一式「山高云淡」，身行一纵，双掌一前一后，猛地击向$n的头顶百汇大穴",
        "$N双掌合十，深吸一口气，一式「蒙蒙群山」，双掌骤然化出一片掌影，击向$n的前胸",
        "$N向上高高跃起，一式「高山流水」，居高临下，掌力笼罩$n的全身",
        "$N使一式「峰回路转」，劲气弥漫，双掌如轮，一掌强过一掌的向$n劈去",
        "$N两掌上下护胸，一式「山穷水尽」，骤然化为满天掌雨，攻向$n",
        "$N一式「排山倒海」，双掌一圈，全身内力如巨浪般汹涌而出，$n顿觉避无可避",
});

int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }

int valid_combine(string combo) { return combo == "jingang-zhi"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练须弥山掌必须空手。\n");

        if ((int)me->query_skill("force", 1) < 300)
                return notify_fail("你的基本内功火候不够，无法学须弥山掌。\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("你的内力太弱，无法练须弥山掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("xumishan-zhang", 1))
                return notify_fail("你的基本掌法水平有限，无法领会更高深的须弥山掌。\n"); 

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(120), 
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
                return notify_fail("你的内力不够练须弥山掌。\n");

        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action) 
{ 
        return __DIR__"xumishan-zhang/" + action; 
} 
