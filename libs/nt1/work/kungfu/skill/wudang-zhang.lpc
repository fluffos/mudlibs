// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wudang-zhang 武当掌法
// 与太极拳法互备

inherit SKILL;

string *action_msg = ({
        "$N一招「苍松迎客」，单掌平推，拍向$n的$l",
        "$N使一招「峰回路转」，右手划了一个圈子，左手挥出，劈向$n的$l",
        "$N右手由钩变掌，使一招「奇峰突现」，横扫$n的$l",
        "$N双手划弧，右手向上，左手向下，使一招「白鹤亮翅」，分击$n的面门和$l",
        "$N左手划了一个大圈，使一招「五行柳变」，击向$n的$l",
        "$N双手合掌，使一招「灵猴采桃」，双掌分别向$n的$l打去",
        "$N左手横于胸前，右掌直击$n的$l，正是一招「仙人指路」",
        "$N左脚前踏半步，双掌猛然齐出,一招「釜底抽薪」，向$n的$l拍去",
        "$N双手翻飞，化作无数掌影，一招「漫天花舞」，直逼$n",
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo)
{
        return combo == "taiji-quan" || combo == "paiyun-shou";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练武当掌法必须空手。\n");

	if ((int)me->query_skill("force") < 30)
		return notify_fail("你的内功火候不够，无法学武当掌法。\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练武当掌法。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 210 + random(60), 
                "attack": 40 + random(10), 
                "dodge" : 40 + random(10), 
                "parry" : 40 + random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练武当掌法。\n");

	me->receive_damage("qi", 40);
	me->add("neili", -40);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wudang-zhang/" + action;
}
