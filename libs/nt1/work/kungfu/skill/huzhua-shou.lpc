// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "在呼呼风声中，$N使一招「虎口夺食」，双手如钩如戢，插向$n的$l",
        "$N身形一跃，费神扑上，使出一招「饿虎扑食」，右手直直抓向$n的$l",
        "$N双手平伸，十指微微上下抖动，一招「山崩地裂」打向$n的$l",    
        "$N使出一招「夜黑风高」，悄无声息的游走至$n身前，猛的一爪奋力抓向$n的$l",
        "$N双手平提胸前，左手护住面门，一招「损筋断骨」右手推向$n的$l",
        "$N使出「恶林虎啸」，低喝一声，双手化掌为爪，一前一后抓向$n的$l",
        "$N右腿斜插$n二腿之间，一招「虎爪绝户」，上手取目，下手反勾$n的裆部",
        "$N使出「困兽犹斗」，双爪如狂风骤雨般对准$n的$l连续抓出",
});

int valid_enable(string usage) { return usage == "claw" ||  usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练虎抓绝户手必须空手。\n");

        if ((int)me->query_skill("force") < 50)
                return notify_fail("你的内功火候不够，无法学虎抓绝户手。\n");

        if ((int)me->query("max_neili") < 250)
                return notify_fail("你的内力太弱，无法练虎抓绝户手。\n");

        if ((int)me->query_skill("claw", 1) < (int)me->query_skill("huzhua-shou", 1))
                return notify_fail("你的基本抓法火候水平有限，无法领会更高深的虎抓绝户手。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 320 + random(30),
                "attack": 60 - random(10),
                "dodge" : 60 - random(10),
                "parry" : 60 - random(10),
                "damage_type" : random(2)?"抓伤":"内伤",
        ]);
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") ||
            me->query_temp("secondary_weapon"))
                return notify_fail("你必须空手练习！\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练虎抓绝户手。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huzhua-shou/" + action;
}

