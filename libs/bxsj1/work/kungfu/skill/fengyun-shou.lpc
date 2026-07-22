// fengyun-shou.c -风云手

inherit SKILL;

mapping *action = ({
([
	"action" : "$N一式「风满长空」，以掌化爪，五指如钩，直逼$n的膻中要穴",
	"lvl" : 0,
        "skill_name" : "风满长空",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N左手虚晃，一式「烈火腾云」，右手上下直击，反扣$n的肩井大穴",
	"lvl" : 8,
        "skill_name" : "烈火腾云",
        "damage_type" : "瘀伤"
]),
([
	"action" : "$N使一式「草深雾泽」，掌指齐出，拍拿并施，拿向$n的三路要害",
	"lvl" : 16,
        "skill_name" : "草深雾泽",
        "damage_type" : "瘀伤"
]),
([
	"action" : "$N左手鹰抓，右手蛇举，一式「天目昭辉」疾扣$n的中节大脉",
	"lvl" : 24,
        "skill_name" : "天目昭辉",
        "damage_type" : "瘀伤"
]),
([
	"action" : "$N使一式「雷震四方」，四面八方出现无数掌影，一爪突出，抓向$n的胸口",
	"lvl" : 40,
        "skill_name" : "雷震四方",
        "damage_type" : "内伤"
]),
([
	"action" : "$N两手环扣，全身关节啪啪作响，一式「水到渠成」，击向$n的$l",
	"lvl" : 48,
        "skill_name" : "水到渠成",
        "damage_type" : "内伤"
]),
([
	"action" : "$N一式「山高林密」，十指齐伸，遮天蔽日般地笼罩$n的全身要穴",
	"lvl" : 54,
        "skill_name" : "山高林密",
        "damage_type" : "内伤"
]),
([
	"action" : "$N岳立霆峙，一式「地老天荒」，在一阵暴雷声中，双手同时拍中$n的七道死穴",
	"lvl" : 100,
        "skill_name" : "地老天荒",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="shaolin-tantui"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练风云手必须空手。\n");
	if ((int)me->query_skill("yijin-jing", 1) < 10)
		return notify_fail("你的易筋经内功火候不够，无法学风云手。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练风云手。\n");
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
	level   = (int) me->query_skill("fengyun-shou",1);
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
	int lvl = me->query_skill("fengyun-shou", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练风云手。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
