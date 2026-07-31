inherit SKILL;

mapping *action = ({
([      "action": "$N踏上一步，忽地在地上一坐，已抱住了$n小腿。十指扣向$n小腿上的中都和"
		  "筑宾两穴",
	"force" : 180,
	"attack": 70,
	"dodge" : 30,
	"damage": 30,
	"parry" : 70,
	"lvl"   : 0,
	"damage_type": "割伤"
]),
([      "action": "突然之间，$N身形晃动，同时欺近，手中$w往$n身上划去。脚下不知如何移动，"
		  "\n身形却已早变。右手同时抓向$n的后领",
	"force" : 240,
	"attack": 80,
	"dodge" : 33,
	"parry" : 79,
	"damage": 38,
	"lvl"   : 40,
	"damage_type": "割伤"
]),
([      "action": "$N欺身直进，左手持$w向$n天灵盖上拍落。便在这一瞬之间，$n滚身向左，已"
		  "\n然一拳打向$n腿部。$n一个踉跄，$N横过$w戳向$n后心",
	"force" : 260,
	"attack": 90,
	"dodge" : 41,
	"parry" : 85,
	"damage": 52,
	"lvl"   : 80,
	"damage_type": "割伤"
]),
([      "action": "$N忽地放手，手中那柄$w尾端向上弹起，直奔$n手腕。",
	"force" : 280,
	"attack": 95,
	"dodge" : 45,
	"parry" : 92,
	"damage": 60,
	"lvl"   : 120,
	"damage_type": "割伤"
]),
([      "action": "$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一阵"
		  "凉风，只见$N手肘袭来",
	"force" : 320,
	"attack": 97,
	"dodge" : 47,
	"parry" : 99,
	"damage": 72,
	"lvl"   : 160,
	"damage_type": "割伤"
]),
([      "action": "$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一麻，"
		  "\n$N手中$w急挥横扫，突然连翻三个空心筋斗，$w已到$n右肩",
	"force" : 360,
	"attack": 100,
	"dodge" : 50,
	"parry" : 100,
	"damage": 100,
	"lvl"   : 180,
	"damage_type": "割伤"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候不到，无法学习圣火令法。\n");

	if (me->query("max_neili") < 1200)
		return notify_fail("你的内功修为不足，无法学习圣火令法。\n");

	if (me->query_int() < 35)
		return notify_fail("你现在无法领悟圣火令法的要诣。\n");

	if (me->query_dex() < 25)
		return notify_fail("你现在身法太差，无法学习圣火令法。\n");

	if (me->query_skill("sword", 1) < me->query_skill("shenghuo-ling", 1))
		return notify_fail("你的基本剑法水平有限，无法领会更高深的圣火令法。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("shenghuo-ling", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || 
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (me->query_skill("shenghuo-ling", 1) < 180)
		return notify_fail("你还没有掌握圣火令法中所有的奥妙，无法通过锻炼获得提升。\n");

	if ((int)me->query("qi") < 80)
		return notify_fail("你的体力不够练圣火令法。\n");

	if ((int)me->query("neili") < 80)
		return notify_fail("你的内力不够练圣火令法。\n");

	me->receive_damage("qi", 50);
	me->add("neili", -70);

	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"shenghuo-ling/" + action;
}
