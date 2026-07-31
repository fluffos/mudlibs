// zhuihun-jian.c 追魂夺命剑

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「四海云飘」，$w似幻出片片白云，四面八方的罩向$n",
	"force"  : 110,
	"attack" : 35,
	"dodge"  : -20,
	"parry"  : -25,
	"damage" : 43,
	"lvl"    : 0,
	"skill_name" : "四海云飘",
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「风起云涌」，剑锋乱指，攻向$n，$n根本不能分辩$w的来路",
	"force"  : 155,
	"attack" : 43,
	"dodge"  : -25,
	"parry"  : -34,
	"damage" : 51,
	"lvl"    : 20,
	"skill_name" : "风起云涌",
	"damage_type" : "刺伤"
]),
([      "action" : "$N使出「在天一方」，$w幻一条飞练，带着一股寒气划向$n的$l",
	"force"  : 178,
	"attack" : 48,
	"dodge"  : -28,
	"parry"  : -24,
	"damage" : 62,
	"lvl"    : 40,
	"skill_name" : "在天一方",
	"damage_type" : "刺伤"
]),
([      "action" : "$N身子向上弹起，左手下指，一招「四方云动」，右手$w带着一团剑花，逼向$n的$l",
	"force"  : 211,
	"attack" : 53,
	"dodge"  : -22,
	"parry"  : -24,
	"damage" : 84,
	"lvl"    : 60,
	"skill_name" : "四方云动",
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「飞瀑倒悬」，左脚跃步落地，右手$w幻成一条雪白的瀑布，扫向$n的$l",
	"force"  : 238,
	"attack" : 69,
	"dodge"  : -28,
	"parry"  : -35,
	"damage" : 95,
	"lvl"    : 80,
	"skill_name" : "飞瀑倒悬",
	"damage_type" : "刺伤"
]),
([      "action" : "$N右腿半屈般蹲，$w平指，一招「无声无色」，剑尖无声无色的慢慢的刺向$n的$l",
	"force"  : 268,
	"attack" : 73,
	"dodge"  : -38,
	"parry"  : -15,
	"damage" : 110,
	"lvl"    : 100,
	"skill_name" : "无声无色",
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「剑气封喉」，剑锋乱指，攻向$n，$n根本不能分辩$w的来路",
	"force"  : 255,
	"attack" : 71,
	"dodge"  : -25,
	"parry"  : -24,
	"damage" : 108,
	"lvl"    : 120,
	"skill_name" : "剑气封喉",
	"damage_type" : "刺伤"
]),
([      "action" : "$N使出「气寒风雪」，$w幻一条飞练，带着一股寒气划向$n的$l",
	"force"  : 270,
	"attack" : 78,
	"dodge"  : -18,
	"parry"  : -19,
	"damage" : 123,
	"lvl"    : 140,
	"skill_name" : "气寒风雪",
	"damage_type" : "刺伤"
]),
([      "action" : "$N身子向上弹起，左手下指，一招「天下浩劫」，右手$w带着一团剑花，逼向$n的$l",
	"force"  : 291,
	"attack" : 103,
	"dodge"  : -23,
	"parry"  : -28,
	"damage" : 141,
	"lvl"    : 160,
	"skill_name" : "天下浩劫",
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「剑划长空」，左脚跃步落地，右手$w幻成一条雪白的瀑布，扫向$n的$l",
	"force"  : 283,
	"attack" : 91,
	"dodge"  : -22,
	"parry"  : -25,
	"damage" : 155,
	"lvl"    : 180,
	"skill_name" : "剑划长空",
	"damage_type" : "刺伤"
]),
([      "action" : "$N右腿半屈般蹲，$w平指，一招「追魂夺命」，剑尖无声无色的慢慢的刺向$n的$l",
	"force"  : 298,
	"attack" : 97,
	"dodge"  : -28,
	"parry"  : -37,
	"damage" : 158,
	"lvl"    : 200,
	"skill_name" : "追魂夺命",
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「人鬼不留」，$w在$n的周身飞舞，令$n眼花缭乱，剑身在半空中突然停住刺向$n的$l",
	"force"  : 328,
	"attack" : 118,
	"dodge"  : -25,
	"parry"  : -27,
	"damage" : 170,
	"lvl"    : 220,
	"skill_name" : "人鬼不留",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功火候太浅。\n");

	if ((int)me->query_skill("sword", 1) < 120)
		return notify_fail("你的基本剑法火候不够，无法学习追魂夺命剑。\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("zhuihun-jian", 1))
		return notify_fail("你的基本剑法水平有限，无法领会更高深的追魂夺命剑。\n");

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
	level   = (int) me->query_skill("zhuihun-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力目前没有办法练习追魂夺命剑。\n");

	if ((int)me->query("neili") < 90)
		return notify_fail("你的内力不够，无法练习追魂夺命剑。\n");
	
	me->add("qi", -50);
	me->add("neili", -82);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zhuihun-jian/" + action;
}


