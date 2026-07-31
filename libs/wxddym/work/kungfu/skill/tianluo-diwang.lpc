// tianluo-diwang 天罗地网势

#include <ansi.h>;

inherit SKILL;

mapping *action = ({
([      "action" : "$N左掌划一半圆，右掌划出另一半圆，呈合拢之势，疾拍$n的胸前大穴",
	"force"  : 160,
	"attack" : 10,
	"parry"  : 10,
	"dodge"  : 10,
	"damage" : 10,
	"lvl"    : 0,
	"damage_type" : "瘀伤",
]),
([      "action" : "$N左掌护胸，右拳凝劲后发，深吸一口气，缓缓推向$n的$l",
	"force"  : 185,
	"attack" : 20,
	"parry"  : 15,
	"dodge"  : 15,
	"damage" : 15,
	"damage_type" : "瘀伤",
	"lvl"    : 30,
]),
([      "action" : "$N纵身向前扑去，一下急冲疾缩，就在两臂将合未合之际，双手抱向$n的$l",
	"force"  : 200,
	"attack" : 30,
	"parry"  : 20,
	"dodge"  : 20,
	"damage" : 22,
	"lvl"    : 60,
	"damage_type" : "瘀伤"
]),
([      "action" : "$N两掌上下护胸，掌势突然一变，骤然化为满天掌雨，攻向$n",
	"force"  : 280,
	"attack" : 40,
	"parry"  : 30,
	"dodge"  : 20,
	"damage" : 30,
	"damage_type" : "瘀伤",
	"lvl"    : 90,     
]),
([      "action" : "$N长袖挥处，两股袖风扑出，$n只觉得密不透风，周身都是掌印，怎么也闪躲不开",
	"force"  : 340,
	"attack" : 50,
	"parry"  : 35,
	"dodge"  : 35, 
	"damage" : 35,
	"lvl"    : 120,	
	"damage_type" : "瘀伤"
]),
([      "action" : "$N双臂飞舞，两只手掌宛似化成了千手千掌，任$n如何跃腾闪躲，始终飞不出只掌所围作的圈圈", 
	"force"  : 350,
	"attack" : 65,
	"parry"  : 40,
	"dodge"  : 40,
	"damage" : 50,
	"lvl"    : 150,
	"damage_type" : "瘀伤"
]), 
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo) { return combo == "meinv-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你必须空手方能练习天罗地网势。\n");

	if ((int)me->query_skill("force") < 80)
		return notify_fail("你的内功基础不够，无法修习天罗地网势。\n");

	if ((int)me->query_skill("strike", 1) < 30)
		return notify_fail("你的基本掌法水平太低，无法研习天罗地网势。\n");

	if ((int)me->query_skill("strike", 1) < me->query_skill("tianluo-diwang", 1))
		return notify_fail("你的基本掌法水平水平有限，无法研习更高深的天罗地网势。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;

	level = (int)me->query_skill("tianluo-diwang", 1);

	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("qi", 40);
	me->add("neili", -25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianluo-diwang/" + action;
}
