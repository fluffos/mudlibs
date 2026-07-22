// qingzhua-shou.c 鹰爪擒拿手

inherit SKILL;

mapping *action = ({
([
	"action" : "$N一式「金针渡线」，右手抬起，左手暗藏，突然拍向$n的$l",
	"lvl" : 0,
	"skill_name" : "金针渡线",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N侧身一晃，一式「双阳沓手」，左手拿向$n的肩头，右拳打向$n的胸口",
	"lvl" : 10,
	"skill_name" : "双阳沓手",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N一式「飞鹰现爪」，双手环拢成爪，左手护体，右手扣向$n的$l",
	"lvl" : 20,
	"skill_name" : "飞鹰现爪",
	"damage_type" : "抓伤"
]),
([
	"action" : "$N身形住回一撤，一个斜身塌式，一式「大鹏展翅」，右掌向$n扫下",
	"lvl" : 30,
	"skill_name" : "大鹏展翅",
	"damage_type" : "抓伤"
]),
([
	"action" : "$N使一式「孔雀剔翎」，一个闪身，左脚飞起，向$n的裆部踹去",
	"lvl" : 40,
	"skill_name" : "孔雀剔翎",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N右手一伸，一式「猿猴摆手」，手臂突然长了数倍，在$n的$l一拂",
	"lvl" : 50,
	"skill_name" : "猿猴摆手",
	"damage_type" : "抓伤"
]),
([
	"action" : "$N双手抱拳，一式「自在飞花」，左手慢慢的拍出，飘逸绝纶的拍向$n的$l",
	"lvl" : 60,
	"skill_name" : "自在飞花",
	"damage_type" : "内伤"
]),
([
	"action" : "$N一式「雨打飞花」，整个身体歪歪斜斜，右手斜斜的拍向$n的$l",
	"lvl" : 70,
	"skill_name" : "雨打飞花",
	"damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练鹰爪擒拿手必须空手。\n");
	if ( !me->query_skill("jiuyang-shengong", 1))
	if ( me->query_skill("shenghuo-shengong", 1) < 20)
		return notify_fail("你的圣火神功火候不够，无法学练鹰爪擒拿手。\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练鹰爪擒拿手。\n");
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
	level   = (int) me->query_skill("yingzhua-shou",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 150 +random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("yingzhua-shou", 1);
	int i = sizeof(action);
	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练鹰爪擒拿手。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
