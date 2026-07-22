// xiuluo-dao.c 修罗刀

inherit SKILL;

mapping *action = ({
([
	"action" : "$N藏刀内收，一招「割肉饲鹰」，刀锋自下而上划了个半弧，向$n的$l挥去",
	"lvl" : 0,
	"skill_name" : "割肉饲鹰",
	"damage_type" : "割伤"
]),
([
	"action" : "$N左掌虚托右肘，一招「投身饿虎」，手中$w笔直划向$n的$l",
	"lvl" : 12,
	"skill_name" : "投身饿虎",
	"damage_type" : "割伤"
]),
([
	"action" : "$N一招「斫头谢天」，$w绕颈而过，刷地一声自上而下向$n猛劈",
	"lvl" : 18,
	"skill_name" : "斫头谢天",
	"damage_type" : "割伤"
]),
([
	"action" : "$N右手反执刀柄，一招「折骨出髓」，猛一挫身，$w直向$n的颈中斩去",
	"lvl" : 24,
	"skill_name" : "折骨出髓",
	"damage_type" : "割伤",
]),
([
	"action" : "$N一招「挑身千灯」，无数刀尖化作点点繁星，向$n的$l挑去",
	"lvl" : 30,
	"skill_name" : "挑身千灯",
	"damage_type" : "割伤"
]),
([
	"action" : "$N双手合执$w，一招「挖眼布施」，拧身急转，刀尖直刺向$n的双眼",
	"lvl" : 36,
	"skill_name" : "挖眼布施",
	"damage_type" : "割伤"
]),
([
	"action" : "$N一招「剥皮书经」，手中$w划出一个大平十字，向$n纵横劈去",
	"lvl" : 42,
	"skill_name" : "剥皮书经",
	"damage_type" : "割伤"
]),
([
	"action" : "$N反转刀尖对准自己，一招「剜心决志」，全身一个翻滚，$w向$n拦腰斩去",
	"lvl" : 48,
	"skill_name" : "剜心决志",
	"damage_type" : "割伤"
]),
([
	"action" : "$N一招「烧身供佛」，$w的刀光仿佛化成一簇簇烈焰，将$n团团围绕",
	"lvl" : 54,
	"skill_name" : "烧身供佛",
	"damage_type" : "割伤"
]),
([
	"action" : "$N刀尖平指，一招「刺血满地」，一片片切骨刀气如飓风般裹向$n的全身",
	"lvl" : 60,
	"skill_name" : "刺血满地",
	"damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("yijin-jing", 1) < 10)
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
	level   = (int) me->query_skill("xiuluo-dao",1);
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
	int lvl = me->query_skill("xiuluo-dao", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("你的体力不够练修罗刀。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
