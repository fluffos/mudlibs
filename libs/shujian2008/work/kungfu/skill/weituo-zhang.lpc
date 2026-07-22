// weituo-zhang.c 韦驮掌

inherit SKILL;

mapping *action = ({
([
	"action" : "$N双眼微睁，袍袖微微鼓气，双掌齐推，一招「开天辟地」，一股排山之势压向$n",
	"lvl" : 0,
	"skill_name" : "开天辟地",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N口中阿弥陀佛，一招「即世即空」，左掌击向$n面门，另一掌却按向$n的小腹",
	"lvl" : 15,
	"skill_name" : "即世即空",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N双掌互错，变幻莫测，一招「无相无色」，瞬息之间向$n攻出了三四一十二招",
	"lvl" : 30,
	"skill_name" : "无相无色",
	"damage_type" : "瘀伤",
]),
([
	"action" : "$N呼的一掌，没有半点征兆，一招「佛法无边」，猛地向$n的$l击打过去",
	"lvl" : 40,
	"skill_name" : "佛法无边",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N双掌交错，若有若无，一招「谁入地狱」，带着劲风拍向$n的肩头和前胸",
	"lvl" : 50,
	"skill_name" : "谁入地狱",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N一招「禅心永明」，右手一掌击出，紧接着右掌上一搭，击向$n的$l",
	"lvl" : 60,
	"skill_name" : "禅心永明",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N双手在空中齐划，跟着双掌齐推，一招「我佛慈悲」，一股排山倒海的掌力，直扑$n面门",
	"lvl" : 70,
	"skill_name" : "我佛慈悲",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N突然身行急转，一招「苦海回头」，掌影飞舞，霎时之间将$n四面八方都裹住了",
	"lvl" : 80,
	"skill_name" : "苦海回头",
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="yingzhua-gong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练韦驮掌必须空手。\n");
	if ((int)me->query_skill("yijin-jing", 1) < 10)
		return notify_fail("你的易筋经内功火候不够，无法练韦驮掌。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练韦驮掌。\n");
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
	level   = (int) me->query_skill("weituo-zhang",1);
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
	int lvl = me->query_skill("weituo-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练韦驮掌。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
