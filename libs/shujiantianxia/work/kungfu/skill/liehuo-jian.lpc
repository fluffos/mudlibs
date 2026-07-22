// liehuo-jian.c 烈火剑

inherit SKILL;

mapping *action = ({
([
	"action" : "$N一招「四海云飘」，$w似幻出片片白云，四面八方的罩向$n",
	"lvl" : 0,
	"skill_name" : "四海云飘",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N一招「四通八达」，剑锋乱指，攻向$n，$n根本不能分辩$w的来路",
	"lvl" : 10,
	"skill_name" : "四通八达",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N使出「在天一方」，$w幻一条飞练，带着一股寒气划向$n的$l",
	"lvl" : 20,
	"skill_name" : "在天一方",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N身子向上弹起，左手下指，一招「怪蟒翻身」，右手$w带着一团剑花，逼向$n的$l",
	"lvl" : 30,
	"skill_name" : "怪蟒翻身",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N一招「飞瀑倒悬」，左脚跃步落地，右手$w幻成一条雪白的瀑布，扫向$n的$l",
	"lvl" : 40,
	"skill_name" : "飞瀑倒悬",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N右腿半屈般蹲，$w平指，一招「无声无色」，剑尖无声无色的慢慢的刺向$n的$l",
	"lvl" : 50,
	"skill_name" : "无声无色",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N一招「万川归海」，$w在$n的周身飞舞，令$n眼花缭乱，剑身在半空中突然停住刺向$n的$l",
	"lvl" : 60,
	"skill_name" : "万川归海",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if (! me->query_skill("jiuyang-shengong", 1))
	if ( me->query_skill("shenghuo-shengong", 1) < 20)
		return notify_fail("你的圣火神功火侯太浅。\n");
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
        int i, level, j;
        level   = (int) me->query_skill("liehuo-jian",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 100 +random(250),
				"dodge": random(20)-10,
				"parry": random(10),
				"damage": 40 + random(60),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("liehuo-jian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 30 || me->query("neili") < 10 )
		return notify_fail("你的体力不够练烈火剑法。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
