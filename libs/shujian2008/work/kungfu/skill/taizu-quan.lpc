// taizu-quan 太祖长拳

inherit SKILL;

mapping *action = ({
([
	"action" : "$N一式「千里横行」，双臂直上直下，猛攻而前，打向$n的$l",
	"lvl" : 0,       
	"damage_type" : "内伤"
]),
([
	"action" : "$N上身前倾，右拳直出呼的一声打向$n，正是一招「冲阵斩将」",
	"lvl" : 10,
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N使招「河朔立威」，右手向上一扬，左手握拳打向$n",
	"lvl" : 20,
	"damage_type" : "内伤"
]),
([
	"action" : "$N双拳呼呼打出，连接三遍，正和「击鼓三通」之意",
	"lvl" : 30,
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N跳起往左旋身一转，左脚落地后双拳齐出，捣向$n的$l，「扬马立威」",
	"lvl" : 40,
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练太祖长拳必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练功。\n");
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
	level   = (int) me->query_skill("taizu-quan",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	100+random(250),
				"dodge":	random(20)-10,
				"parry":	random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练太祖长拳。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taizu-quan/" + action;
}
