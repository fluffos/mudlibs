// chousui-duzhang.c  抽髓掌, based on xianglong-zhang.c
inherit SKILL;

mapping *action = ({
([      "action": "$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l",
	"force" : 180,
	"attack": 49,
	"dodge" : -30,
	"parry" : -37,
	"dmage" : 32,
	"damage_type": "瘀伤"
]),
([      "action": "$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l",
	"force" : 230,
	"attack": 56,
	"dodge" : -22,
	"parry" : -34,
	"dmage" : 47,
	"damage_type": "瘀伤"
]),
([      "action": "$N将毒质运至右手，一招「腐尸毒」阴毒无比地抓向$n的$l",
	"force" : 260,
	"attack": 61,
	"dodge" : -20,
	"parry" : 10,
	"dmage" : 60,
	"damage_type": "瘀伤"
]),
([      "action": "$N双掌挟着一股腥臭之气拍向$n的$l",
	"force" : 380,
	"attack": 79,
	"dodge" : 17,
	"parry" : 36,
	"dmage" : 65,
	"damage_type": "瘀伤"
]),
([      "action": "$N咬破舌尖，口中喷血，聚集全身的力量击向$n",
	"force" : 420,
	"attack": 81,
	"dodge" : 27,
	"parry" : 21,
	"dmage" : 75,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo) { return combo == "sanyin-wugongzhao"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("poison", 1) < 20)
		return notify_fail("你的毒功太差，无法练抽髓掌。\n");

	if ((int)me->query_skill("force") < 30)
		return notify_fail("你的内功火候不够，无法练抽髓掌。\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练抽髓掌。");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("choushui-zhang", 1))
		return notify_fail("你的基本掌法水平有限，无法领会更高深的抽髓掌法。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;

	level = (int) me->query_skill("chousui-zhang", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练抽髓掌。\n");

	if (me->query_skill("chousui-zhang", 1) < 50)
		me->receive_damage("qi", 20);
	else
		me->receive_damage("qi", 35);

	me->add("neili", -32);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"chousui-zhang/" + action;
}
