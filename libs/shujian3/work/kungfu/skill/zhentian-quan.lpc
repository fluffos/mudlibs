//震天拳
//cool 981010
inherit SKILL;

mapping *action = ({
([
	"action" : "$N马步一立，身子微曲，暗喝一声，一招「望月拜天」，一拳直捅$n的$l",
	"lvl" : 0,
	"skill_name" : "望月拜天",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N“哈哈”一笑，左拳由下至上，右拳平平击出，一招「跨日向天」，交替打向$n",
	"lvl" : 15,
	"skill_name" : "跨日向天",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N对$n一声大喝，使一招「长虹经天」，左拳击出，随即右拳跟上，两重力道打向$n的$l",
	"lvl" : 30,
	"skill_name" : "长虹经天",
	"damage_type" : "震伤"
]),
([
	"action" : "$N闷喝一声，双拳向上分开，一记「举火烧天」，拳划弧线，左右同时击向$n的$l",
	"lvl" : 45,
	"skill_name" : "举火烧天",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N使出「一臂擎天」，一声大吼，一拳凌空打出，拳风直逼$n的$l",
	"lvl" : 60,
	"skill_name" : "一臂擎天",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N一声长啸，双拳交错击出，一招「石破天惊」，拳风密布$n的前后左右",
	"lvl" : 70,
	"skill_name" : "石破天惊",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N怒吼一声，凌空飞起，一式「天崩地裂」，双拳居高临下，齐齐捶向$n",
	"lvl" : 80,
	"skill_name" : "天崩地裂",
	"damage_type" : "内伤"
]),
([
	"action" : "$N仰天大笑，势若疯狂，衣袍飞舞，一招「无法无天」，拳风凌厉，如雨点般向$n打去",
	"lvl" : 90,
	"skill_name" : "无法无天",
	"damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练「震天拳」必须空手。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 25)
		return notify_fail("你的「玄天无极功」火候不够，无法学「震天拳」。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练「震天拳」。\n");
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
	if( me->query_skill("cuff", 1) >= 120 
	 && me->query_skill("zhentian-quan", 1) >= 120 
	 && me->query_skill("leg",1) >= 120
	 && me->query_skill("chuanyun-tui",1) >= 120
	 && me->query("neili") >= 500
	 && me->query_skill_mapped("leg") == "chuanyun-tui"
	 && me->query_skill_mapped("parry") != "zhentian-quan"
	 && !random(6)) {
		return ([
			"action": "$N手中招式突然加快，一招“拳腿双绝”，隔空向$n击出一拳，随即双腿连环踢出",
			"parry": random(15),
			"dodge": random(20)-5,
			"force": 350,
			"damage_type": "内伤"
		]);
	}
	level   = (int) me->query_skill("zhentian-quan",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 100 +random(250),
				"dodge": random(20)-10,
				"parry": random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("zhentian-quan", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ( me->query("neili") < 10)
		return notify_fail("你的内力不够练「震天拳」。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zhentian-quan/" + action;
}
