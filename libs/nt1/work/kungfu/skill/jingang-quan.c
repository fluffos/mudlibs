// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jingang-quan.c -大金刚拳

inherit SHAOLIN_SKILL;

mapping *action_msg = ({
        "$N盘膝而坐，二手合十，一式「莲花座」，双拳蓄势而发，击向$n的$l",
        "$N一式「烈火锥」，双掌轮流下击，拳势如焰，吡啪爆响",
        "$N腾空飞起，一式「八方雨」，双手双腿齐出，令$n无可躲藏",
        "$N双掌虚含，掌缘下沉，一式「掌心雷」，缓缓向$n推出",
        "$N一臂前伸，一臂后指，一式「五指山」，攻向$n的身前身后",
        "$N一式「观音渡」，两手十指虚点$n的全身三十六道要穴",
        "$N两目内视，双手内笼，一式「天龙唱」，四面八方响起震人心魄的龙吟",
        "$N似笑非笑，双拳无形无定，一式「如来笑」，骤然击向$n的前胸",
});

int valid_enable(string usage) { return usage == "cuff" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练大金刚拳必须空手。\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("你的内功火候不够，无法学大金刚拳。\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练大金刚拳。\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("jingang-quan", 1))
                return notify_fail("你的基本拳法水平有限，无法领会更高深的大金刚拳。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "attack": 50 + random(10),
                "dodge" : 50 + random(10),
                "parry" : 50 + random(10),
                "force" : 260 + random(120), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练大金刚拳。\n");

        if( (int)me->query_skill("jingang-quan", 1) < 100 )
                return notify_fail("你的大金刚拳修为还不够。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jingang-quan/" + action;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("jingang-quan", 1) == 150 && ! me->query("sl/str")) 
        {
                me->add("str", 1);
                me->set("sl/str", 1); 
                tell_object(me, "你的大金刚拳学有所成，提高了你的臂力。\n");
        }
}
        

