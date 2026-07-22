// tiangang-zhang.c 天罡掌

inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「揩磨尘垢」，左拳虚晃右掌斜飞，击向$n的$l",
	"force" : 275,
	"dodge" : 60,
        "lvl" : 0,
	"skill_name" : "揩磨尘垢",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「无欠无余」，斜步扭身，手肘猛地向$n的胸口撞去",
	"force" : 325,
	"dodge" : 50,
        "lvl" : 39,
	"skill_name" : "无欠无余",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左掌斜穿，右手做虎爪。一招「虎门手」打向$n的$l",
	"force" : 450,
	"dodge" : 40,
        "lvl" : 89,
	"skill_name" : "虎门手",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N提步上前，一记「灵光照耀」，双掌缓缓推出，击向$n的前胸",
	"force" : 560,
	"dodge" : 30,
        "lvl" : 119,
	"skill_name" : "灵光照耀",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N脚踩七星方位，双掌翻飞施出「高山流水」，无数掌影击向$n的$l",
	"force" : 685,
	"dodge" : 50,
        "lvl" : 179,
	"skill_name" : "高山流水",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N大喝一声，一招「天地无用」，双掌带着天罡正气，迅捷无比的击向$n的$l",
	"force" : 700,
	"dodge" : 50,
        "lvl" : 200,
	"skill_name" : "天地无用",
        "damage_type" : "瘀伤"
])

});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天罡掌必须空手。\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 20)
		return notify_fail("你的先天功火候不够，无法学天罡掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练天罡掌。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("tiangang-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        int lvl = me->query_skill("tiangang-zhang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练天罡掌。\n");
	me->receive_damage("jingli", 60);
	me->add("neili", -20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tiangang-zhang/" + action;
}
