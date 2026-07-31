// canhezhi.c 参合指

inherit SKILL;

mapping *action = ({
([      "action": "$N双指并拢，一式「三心焚净」，一指戳向$n的胸腹间",
	"force" : 340,
	"attack": 85,
	"dodge" : 75,
	"parry" : 70,
	"damage": 72,
	"skill_name" : "三心焚净",
	"damage_type" : "刺伤"
]),
([      "action": "$N左掌护胸，一式「顿心自瞭」，右手中指前后划了个半弧，猛地一甩，疾点$n的$l",
	"force" : 370,
	"attack": 65,
	"dodge" : 80,
	"parry" : 85,
	"damage": 65,
	"skill_name" : "顿心自瞭",
	"damage_type" : "刺伤"
]),
([      "action": "$N身形闪动，一式「青叶荷莲」，双手十指同时"
		  "按向$n的全身要穴",
	"force" : 360,
	"attack": 85,
	"dodge" : 70,
	"parry" : 75,
	"damage": 90,
	"skill_name" : "青叶荷莲",
	"damage_type" : "刺伤"
]),
([      "action": "$N一式「清心悟明」，左手握拳托肘，右手拇指直立，遥"
		  "遥对着$n一捺",
	"force" : 380,
	"attack": 95,
	"dodge" : 75,
	"parry" : 85,
	"damage": 70,
	"skill_name" : "清心悟明",
	"damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage == "finger" || usage == "parry"; }

int valid_combine(string combo) { return combo == "qixing-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练参合指必须空手。\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功火候不够，无法学参合指。\n");

	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱，无法练参合指。\n");

	if ((int)me->query_skill("finger", 1) < (int)me->query_skill("canhe-zhi", 1))
		return notify_fail("你的基本指法水平有限，无法领会更高深的参合指。\n");

	return 1;
}

string query_skill_name(int level)
{
	return action[random(sizeof(action))]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 80)
		return notify_fail("你的内力不够练参合指。\n");

	me->receive_damage("qi", 62);
	me->add("neili", -70);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"canhe-zhi/" + action;
}
