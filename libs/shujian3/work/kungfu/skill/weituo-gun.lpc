// weituo-gun.c -韦陀棍

inherit SKILL;

mapping *action = ({
([
	"action":"$N一招「黄石纳履」，手中$w如蜻蜓点水般，招招向$n的下盘要害点去",
	"lvl" : 0,
	"skill_name" : "黄石纳履",
	"damage_type":"挫伤"
]),
([
	"action":"$N把$w平提胸口，一拧身，一招「勒马停锋」，$w猛地撩向$n的颈部",
	"lvl" : 8,
	"skill_name" : "勒马停锋",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「平地龙飞」，全身滴溜溜地在地上打个大转，举棍向$n的胸腹间戳去",
	"lvl" : 16,
	"skill_name" : "平地龙飞",
	"damage_type":"挫伤"
]),
([
	"action":"$N伏地一个滚翻，一招「伏虎听风」，$w挟呼呼风声迅猛扫向$n的足胫",
	"lvl" : 25,
	"skill_name" : "伏虎听风",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「流星赶月」，身棍合一，棍端逼成一条直线，流星般向顶向$n的$l",
	"lvl" : 35,
	"skill_name" : "流星赶月",
	"damage_type":"挫伤"
]),
([
	"action":"$N双手持棍划了个天地大圈，一招「红霞贯日」，一棍从圆心正中击出，撞向$n的胸口",
	"lvl" : 44,
	"skill_name" : "红霞贯日",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「投鞭断流」，$w高举，以雷霆万钧之势对准$n的天灵当头劈下",
	"lvl" : 52,
	"skill_name" : "投鞭断流",
	"damage_type":"挫伤"
]),
([
	"action":"$N潜运真力，一招「苍龙归海」，$w顿时长了数丈，矫龙般直射$n的胸口",
	"lvl" : 60,
	"skill_name" : "苍龙归海",
	"damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return  (usage == "club") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("yijin-jing", 1) < 20)
		return notify_fail("你的易筋经内功火候太浅。\n");
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
	level   = (int) me->query_skill("weituo-gun",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 100 + random(250),
				"dodge": random(20)-10,
				"damage": 40 + random(60),
				"parry": random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("weituo-gun", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("你的体力不够练韦陀棍。\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}
