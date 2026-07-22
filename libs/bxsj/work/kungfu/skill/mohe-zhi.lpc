// moke-zhi.c -摩诃指

inherit SKILL;

mapping *action = ({
([
	"action" : "$N左指挥出，一式「叶不归根」，削向$n的掌缘",
	"lvl" : 0,
	"skill_name" : "叶不归根",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N全身之力聚于一指，一式「我心向佛」，指向$n的胸前",
	"lvl" : 15,
	"skill_name" : "我心向佛",
        "damage_type" : "刺伤"
]),
([
	"action" : "$N左掌贴于神道穴，右手一式「以慈度心」，向$n的$l划过",
	"lvl" : 25,   
        "skill_name" : "以慈渡心",
        "damage_type" : "刺伤"
]),
([
	"action" : "$N双目怒视，一式「三入地狱」，双指拂向$n的额、颈、肩、臂、胸、背",
	"lvl" : 45,
	"skill_name" : "三入地狱",
        "damage_type" : "刺伤"
]),
([
	"action" : "$N一式「天衣无缝」，左掌掌心向外，右指蓄势点向$n的$l",
	"lvl" : 60,
	"skill_name" : "天衣无缝",
        "damage_type" : "刺伤"
]),
([
	"action" : "$N右手伸出，十指叉开，一式「念经诵佛」，小指拂向$n的太渊穴",
	"lvl" : 70,
	"skill_name" : "念经送佛",
        "damage_type" : "刺伤"
]),
([
	"action" : "$N双迸出无数道劲气，一式「我佛慈悲」射向$n的全身",
	"lvl" : 80,
	"skill_name" : "我佛慈悲",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jimie-zhua"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练摩诃指必须空手。\n");
	if ((int)me->query_skill("yijin-jing", 1) < 10)
		return notify_fail("你的易筋经内功火候不够，无法学摩诃指。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练摩诃指。\n");
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
	level   = (int) me->query_skill("mohe-zhi",1);
	for(i = sizeof(action); i > 0; i--){
                if(level > action[i-1]["lvl"]){
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
	int lvl = me->query_skill("mohe-zhi", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练摩诃指。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
