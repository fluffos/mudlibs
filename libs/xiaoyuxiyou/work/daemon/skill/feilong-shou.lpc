//飞龙探云手
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action"	: "$N一式「猴子摘桃」，双手一晃，即如闪电朝$n裆下要害勾去。\n",
        "dodge"		: 5,
        "parry"		: 5,
        "damage"	: 10,
        "damage_type"	: "瘀伤"
]),
([      "action"	: "$N招式不变，顺势一式「顺手牵羊」，双手飞快的朝$n$l掏去。\n",
        "dodge"		: 3,
        "parry"		: 3,
        "damage"	: 20,
        "damage_type"	: "瘀伤"
]),
([      "action"	: "$N身形一扭，一式「反手牵猪」，左手飞快的在$n$l一拍。\n",
        "damage"	: 30,
        "damage_type"	: "瘀伤"
]),
([      "action"	: "$N身形灵动，幻作道道人影，一招「凌空摘星」，双手拍出无数掌影朝$n$l打去。\n",
        "dodge"		: -5,
        "parry"		: -5,
        "damage"	: 50,
        "damage_type"	: "瘀伤"
]),

});

int valid_enable(string usage) { return usage=="unarmed"  || usage=="stealing" ; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练飞龙探云手必须空手。\n");
        if ((int)me->query_maxforce() < 100)
                return notify_fail("你的内力太弱，无法练飞龙探云手。\n");
        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 40)
                return notify_fail("你的内力不够练飞龙探云手。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("shushan") +"/feilong-shou/" + action;
}