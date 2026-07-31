// jimie-zhua.c 寂灭爪

inherit SKILL;

mapping *action = ({
([
	"action" : "$N全身拔地而起，一式「众生无我」，双爪迅猛地抓向$n的$l",
	"lvl" : 0,
	"skills_name" : "众生无我",
	"damage_type" : "内伤"
]),
([
	"action" : "$N大吼一声，接连发出四抓，一式「苦乐随缘」，双爪抓向$n的头部和胸部",
	"lvl" : 10,
	"skills_name" : "苦乐随缘",
	"damage_type" : "内伤"
]),
([
	"action" : "$N一式「烈火腾云」，双掌化指，霎时间，一股咄咄逼人的内力逼向$n",
	"lvl" : 20,
	"skills_name" : "烈火腾云",
	"damage_type" : "内伤"
]),
([
	"action" : "$N双爪交错，一式「普度众生」，身行上扬，分别袭向$n左右腋空门",
	"lvl" : 30,
	"skills_name" : "普度众生",
	"damage_type" : "内伤"
]),
([
	"action" : "$N一式「七星聚会」，右爪突出，左爪跟进，双爪相叠，抓向$n的胸口",
	"lvl" : 40,
	"skills_name" : "七星聚会",
	"damage_type" : "内伤"
]),
([
	"action" : "$N原地不动，一式「以逸待劳」，只待$n袭来，双爪袭向$n膻中大穴和裆部",
	"lvl" : 50,
	"skills_name" : "以逸待劳",
	"damage_type" : "内伤"
]),
([
	"action" : "$N的双爪无数道劲气破空而出，，一式「天衣无缝」，迅疾无比地击向$n",
	"lvl" : 60,
	"skills_name" : "天衣无缝",
	"damage_type" : "内伤"
]),
([
	"action" : "$N腾空高飞数丈，一式「佛门善地」，一时间空中出现无数$N的身影罩向$n",
	"lvl" : 60,
	"skills_name" : "佛门善地",
	"damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo) { return combo=="mohe-zhi"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练寂灭爪必须空手。\n");
	if ((int)me->query_skill("yijin-jing", 1) < 10)
		return notify_fail("你的易筋经内功火候不够，无法学寂灭爪。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练习寂灭爪。\n");
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
	level   = (int) me->query_skill("jimie-zhua",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 100 + random(250),
				"dodge": random(20)-10,
				"parry": random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("jimie-zhua", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练寂灭爪。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
