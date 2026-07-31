// tanzhi.c 弹指神通

inherit SKILL;

mapping *action_finger = ({
([      "action" : "$N右指划了个半圈，一式「划天裂地」自上而下划向$n的全身",
	"force" : 440,
	"attack": 100,
	"parry" : 50,
	"dodge" : 75,
	"damage": 65,
	"skill_name" : "划天裂地",
	"damage_type" : "刺伤"
]),
([      "action" : "$N左掌护胸，一招「我心悠悠」，右指欲举无力指向$n的额头",
	"force" : 410,
	"attack": 90,
	"parry" : 65,
	"dodge" : 90,
	"skill_name" : "我心悠悠",
	"damage_type" : "刺伤"
]),
([      "action" : "$N双手齐出，一式「千夫所指」，疾指向$n的$l",
	"force" : 420,
	"attack": 110,
	"parry" : 65,
	"dodge" : 85,
	"damage": 65,
	"skill_name" : "千夫所指",
	"damage_type" : "刺伤"
]),
([      "action" : "$N仰天一叹，一招「弹指人生」，双手幻出重重指影，点向$n的$l",
	"force" : 400,
	"attack": 100,
	"parry" : 70,
	"dodge" : 95,
	"damage": 70,
	"skill_name" : "弹指人生",
	"damage_type" : "刺伤"
]),
([      "action" : "$N一式「笑指天南」，左掌蓄式，右指弹出一缕指风点向$n的$l",
	"force" : 430,
	"attack": 95,
	"parry" : 45,
	"dodge" : 100,
	"damage": 75,
	"skill_name" : "笑指天南",
	"damage_type" : "刺伤"
]),
([      "action" : "$N用出「擎天一指」，蓄集全身力气，一指点向$n的$l",
	"force" : 450,
	"attack": 105,
	"parry" : 65,
	"dodge" : 90,
	"damage": 80,
	"skill_name" : "擎天一指",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage)
{
	return usage == "finger" ||
	       usage == "parry" ||
	       usage == "throwing";
}

int valid_combine(string combo) { return combo == "lanhua-shou"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，无法学弹指神通。\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练弹指神通。\n");

	if ((int)me->query_skill("finger", 1) < 100)
		return notify_fail("你的基本指法火候不够，无法学弹指神通。\n");

	if ((int)me->query_skill("finger", 1) < (int)me->query_skill("tanzhi-shentong", 1))
		return notify_fail("你的基本指法水平有限，无法领会更高深的弹指神通。\n");

	return 1;
}

string query_skill_name(int level)
{
	return action_finger[random(sizeof(action_finger))]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	return action_finger[random(sizeof(action_finger))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 80)
		return notify_fail("你的体力不够，休息一下再练吧。\n");

	if ((int)me->query("neili") < 80)
		return notify_fail("你的内力不够练弹指神通。\n");

	me->receive_damage("qi", 68);
	me->add("neili", -67);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tanzhi-shentong/" + action;
}
