// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhougong-jian.c 周公剑

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        "$N纵步上前，手中$w斜斜刺出，不知其来路如何，也不知其刺向何方，$n完全无法招架",
        "$N手中$w猛的反身递出，制敌机先，疾刺$n的$l",
        "$N面不露色，手中的$w向$n直直刺去, 这看似很平凡的一招竟然含着巨大的杀着",
        "$N手中$w随意挥洒，幻出许许剑芒, 逼得$n连连后退",
        "$N手中$w光芒闪烁，在许许剑芒中递出杀着，完全出自$n意料之外",
        "$N手中$w斜斜刺出，虚虚实实，笼罩$n四周，完全封所了$n的退路",
        "$N足尖在地上一点而起，半空中点出千万寒星，分刺$n各处要害",
        "$N飞身跃起，手中$w舞出无数个闪烁的剑花，满天闪落而下，制$n于其中",
        "$N身行晃动不定，手中$w挥洒而出，划出万点迅捷无比的寒星洒向$n",
        "$N随意挥洒手中$w，顿时幻出万般剑芒, 数股剑气从剑芒中递出，直知贯向$n",
        "$N手中$w遥指苍天，剑芒吞吐不定，一式「玉带围腰」，对准$n的$l直贯而去",
        "$N一式「天如穹庐」，只见$w突然从天而降，一股强大的剑气席卷$n全身",
        HIW "$N" HIW "一声爆喝，身法陡然加快，手中剑芒吞吐不定，身外化身，剑外"
        "化剑，手中$w" HIW "如飞龙一般递出！\n" NOR "$n眼见这突如其来的一剑，面"
        "如死灰，完全不知道该如何抵挡，想抽身后退，身后一股强大的剑气\n又云涌而至",
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 1200)
                return notify_fail("你的内力不够，无法学习周公剑。\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("你的内功火候不够，无法学习周公剑。\n");

        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("你的基本剑法火候不够，无法学习周公剑。\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("zhougong-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的周公剑。\n");

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("zhougong-jian", 1))
                return notify_fail("你的基本内功水平有限，无法领会更高深的周公剑。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(50),
                "attack": 80 + random(10),
                "dodge" : 80 + random(10),
                "parry" : 80 + random(10),
                "damage_type" : random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;
        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 90)
                return notify_fail("你的体力不够练周公剑。\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("你的内力不够练周公剑。\n");

        me->receive_damage("qi", 80);
        me->add("neili", -80);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhougong-jian/" + action;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")))
                return 0;
                
        if ((string)weapon->query("skill_type") != "sword") 
                return 0;
                
        lvl = me->query_skill("zhougong-jian", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}
