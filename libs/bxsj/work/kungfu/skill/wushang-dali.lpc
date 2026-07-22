// wushang-dali.c 无上大力杵法
// by iceland

inherit SKILL;

mapping *action = ({
([
	"action": "$N高举$w, 凝全身之力，一招「崩天柱」，照着$n劈头盖脸砸了下来，声势惊人！",
	"lvl" : 0,
	"skill_name" : "崩天柱",
	"damage_type": "挫伤"
]),
([
	"action": "$N使出一招「扳山式」,左手握住$w头回拉，右手在$w中间外推，呼的一声$w平扫向$n的$l",
	"lvl" : 30,
	"skill_name" : "扳山式", 
	"damage_type": "挫伤"
]),
([
	"action": "$N奋平生之力，将$w舞的犹如屏风一般，密不透风，一招「荡乾坤」，慢慢向$n挤压过去。",
	"lvl" : 60,
	"skill_name" : "荡乾坤", 
	"damage_type": "瘀伤"
]),
([
	"action": "$N大吼一声“死！”，一招「风卷残云」,双手抱住$w一端，腰间发力抡了起来，将$n淹没在一片金光中。",
	"lvl" : 90,
	"skill_name" : "风卷残云", 
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage)
{
	return usage == "staff" || usage == "parry";
}

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "staff")
		return notify_fail("你练习着无上大力杵法，却感到武器太不对劲。\n");
	if ( me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，不能学习无上大力杵法。\n");
	if ( me->query_str(1) < 25)
		return notify_fail("你的膂力太低，不适合学习无上大力杵法。\n");
	if (me->query_skill("longxiang-boruo", 1) < 35)
		return notify_fail("你的龙象般若功火候太浅。\n");    
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
	level   = (int) me->query_skill("wushang-dali",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":100+random(250),
				"dodge":random(20)-10,
				"damage":40+random(60),
				"parry":random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("wushang-dali", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if( me->query("neili") < 10)
		return notify_fail("你的内力太少了，歇口气再练吧。\n");
	if ( me->query("jingli") < 30)
		return notify_fail("你太累了，歇口气再练吧。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
