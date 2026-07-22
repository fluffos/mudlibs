// wudang-quan.c 武当长拳

inherit SKILL;

mapping *action = ({
([
	"action" : "$N力灌右臂，一招「七星手」，一拳直出打向$n的$l",
	"lvl" : 0,
	"skill_name" : "七星手",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N身行前探，闪身跨奔$n身侧，一招「推手」，向$n的$l推去",
	"lvl" : 10,
	"skill_name" : "推手",
	"damage_type" : "震伤"
]),
([
	"action" : "$N双臂微曲，身行晃动，一招「一条鞭」守中带攻打向$n的$l",
	"lvl" : 20,
	"skill_name" : "一条鞭",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N马步扎稳，左手虚晃，右手握拳一式「直击」迅猛打向$n的胸口",
	"lvl" : 40,
	"skill_name" : "直击",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N施出「雁回头」，纵身跃向空中，双手同时击向$n的$l",
	"lvl" : 50,
	"skill_name" : "雁回头",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N双臂回环，身行微微后仰，一招「井栏」，缠向$n的双手",
	"lvl" : 60,
	"skill_name" : "井栏",
	"damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练武当长拳必须空手。\n");
	if ((int)me->query_skill("yinyun-ziqi", 1) < 10)
		return notify_fail("你的氤氲紫气火候不够，无法学武当长拳。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练武当长拳。\n");
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
	int i, level, j;
	level   = (int) me->query_skill("wudang-quan",1);
        for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":100+random(250),
				"dodge":random(20)-10,
				"parry":random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("wudang-quan", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练武当长拳。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
