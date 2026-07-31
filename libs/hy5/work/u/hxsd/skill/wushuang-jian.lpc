// wushuang-jian.c 无双剑

inherit SKILL;

mapping *action = ({
([      "action":"\n$N使一式「浮世无缘」，手中$w嗡嗡微振，幻成一条白光刺向$n的$l",
	"force" : 120,
	"dodge" : -10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "浮世无缘",
	"damage_type":  "刺伤"
]),
([      "action":"\n$N错步上前，使出「情难到老」，剑意若有若无，$w淡淡地向$n的$l挥去",
	"force" : 140,
	"dodge" : -10,
	"damage": 20,
	"lvl" : 8,
	"skill_name" : "情难到老",
	"damage_type":  "割伤"
]),
([      "action":"\n$N一式「倾城泣别」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
	"force" : 160,
	"dodge" : 5,
	"damage": 30,
	"lvl" : 15,
	"skill_name" : "倾城泣别",
	"damage_type":  "刺伤"
]),
([      "action":"$N纵身轻轻跃起，一式「两皆失声」，剑光如水，一泻千里，洒向$n全身",
	"force" : 180,
	"dodge" : 10,
	"damage": 35,
	"lvl" : 20,
	"skill_name" : "两皆失声",
	"damage_type":  "割伤"
]),
([      "action":"$N手中$w中宫直进，一式「怨天不公」，无声无息地对准$n的$l刺出一剑",
	"force" : 220,
	"dodge" : 15,
	"damage": 40,
	"lvl" : 30,
	"skill_name" : "怨天不公",
	"damage_type":  "刺伤"
]),
([      "action":"$N手中$w一沉，一式「恨爱无缘」，无声无息地滑向$n的$l",
	"force" : 250,
	"dodge" : 15,
	"damage": 40,
	"lvl" : 40,
	"skill_name" : "恨爱无缘",
	"damage_type":  "割伤"
]),
([      "action":"\n$N手中$w斜指苍天，剑芒吞吐，一式「万法归宗」，对准$n的$l斜斜击出",
	"force" : 280,
	"dodge" : 25,
	"damage": 45,
	"lvl" : 50,
	"skill_name" : "万法归宗",
	"damage_type":  "刺伤"
]),
([      "action":"$N随风轻轻飘落，一式「万物归地」，手中$w平指，缓缓拍向$n脸颊",
	"force" : 450,
	"dodge" : 15,
	"damage": 80,
	"lvl" : 90,
	"skill_name" : "万物归地",
	"damage_type":  "内伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("force", 1) < 40)
		return notify_fail("你的基本内功火候太浅。\n");
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
	level   = (int) me->query_skill("wushuang-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"wushuang-jian/" + action;
}
