// yuenv-jian.c 越女剑术

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w轻轻点向$n的$l，迅疾无比",
	"force"  : 70,
	"dodge"  : 60,
	"parry"  : 12,
	"damage" : 50,
	"lvl"    : 0,
	"damage_type" : "刺伤"
]),
([      "action" : "$N长跃而起，手中的$w挽了一个剑花，猛然刺向$n",
	"force"  : 90,
	"dodge"  : 65,
	"parry"  : 15,
	"damage" : 54,
	"lvl"    : 20,
	"damage_type" : "刺伤"
]),
([      "action" : "$N使出回身侧步，手中的$w斜刺$n的$l",
	"force"  : 100,
	"dodge"  : 70,
	"parry"  : 10,
	"damage" : 60,
	"lvl"    : 50,
	"damage_type" : "内伤"
]),
([      "action" : "$N却身提步，手中的$w似挡飞挡，似进非进，忽的直刺$n",
	"force"  : 120,
	"dodge"  : 78,
	"parry"  : 10,
	"damage" : 80,
	"lvl"    : 75,
	"damage_type" : "刺伤"
]),
([      "action" : "$N手中$w颤动的极快，只幌得$n眼花撩乱，浑不知从何攻来",
	"force"  : 130,
	"dodge"  : 85,
	"parry"  : 12,
	"damage" : 95,
	"lvl"    : 100,
	"damage_type" : "内伤"
]),
([      "action" : "$N剑柄提起，剑尖下指，有如提壶斟酒，直挥$n的$l",
	"force"  : 150,
	"dodge"  : 90,
	"parry"  : 18,
	"damage" : 100,
	"lvl"    : 130,
	"damage_type" : "刺伤"
]),
([      "action" : "$N手中$w由内自外一刺，没有任何花巧，然而来势快得不可思议",
	"force"  : 180,
	"dodge"  : 95,
	"parry"  : 15,
	"damage" : 110,
	"lvl"    : 160,
	"damage_type" : "刺伤"
]),
([      "action" : "$N轻叹一声，手中的$w化作一道长弧点向$n",
	"force"  : 200,
	"dodge"  : 100,
	"parry"  : 22,
	"damage" : 120,
	"lvl"    : 200,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一抖手中的$w，挽出数个剑花，笼罩了$n",
	"force"  : 220,
	"dodge"  : 105,
	"parry"  : 25,
	"damage" : 125,
	"lvl"    : 225,
	"damage_type" : "刺伤"
]),
([  "action" : "$N一声轻笑，手中$w幻化作满天星点，不知刺向$n的何处",
	"force"  : 250,
	"dodge"  : 115,
	"parry"  : 30,
	"damage" : 150,
	"lvl"    : 250,
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功火候不到，无法运用越女剑术。\n");

	if ((int)me->query_skill("sword", 1) < 100)
		return notify_fail("你的剑术功底不行，难以领会越女剑术。\n");

	if ((int)me->query("neili") < 800)
		return notify_fail("你的内力太差，无法学习越女剑术。\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("yuenv-jian", 1))
		return notify_fail("你的基本剑法水平有限，无法领会更高深的越女剑术。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("yuenv-jian", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力不够练越女剑术。\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不足以练越女剑术。\n");

	me->receive_damage("qi", 64);
	me->add("neili", -65);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yuenv-jian/" + action;
}

