// fumo-jian.c -伏魔剑

inherit SKILL;

mapping *action = ({
([
	"action" : "$N一式「穿云势」，剑锋平指，剑势如风，一气呵成横扫$n的腰间",
	"lvl" : 0,
	"skill_name" : "穿云势",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N向前跃上一步，左手剑诀，右手$w使出一式「破雾势」直刺$n的$l",
	"lvl" : 10,
	"skill_name" : "破雾势",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N拔步挺腰，一式「推山势」，手中$w沉滞无比，缓缓挥剑撞向$n的$l",
	"lvl" : 20,
	"skill_name" : "推山势",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N一式「搅海势」，$w自左而右划出一个大弧，平平地向$n的$l挥去",
	"lvl" : 30,
	"skill_name" : "搅海势",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N回身拧腰，右手虚抱成圆，一式「开天势」，$w中宫直进，刺向$n的胸口",
	"lvl" : 40,
	"skill_name" : "开天势",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N一式「劈地势」，$w从上至下猛劈，剑锋直出，挟爆裂之声骤然斩向$n的$l",
	"lvl" : 49,
	"skill_name" : "劈地势",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N运气施出「雷针势」，$w剑尖逼出一道青芒，闪电般破空射向$n的$l",
	"lvl" : 57,
	"skill_name" : "雷针势",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N双腿半屈半蹲，一式「龙吞势」，剑尖划出无数圆圈，狂风骤起，笼罩天地",
	"lvl" : 64,
	"skill_name" : "龙吞势",
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("yijin-jing", 1) < 20)
		return notify_fail("你的易筋经火候太浅。\n");
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
	level   = (int) me->query_skill("fumo-jian",1);
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
	int lvl = me->query_skill("fumo-jian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("你的体力不够练伏魔剑。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
