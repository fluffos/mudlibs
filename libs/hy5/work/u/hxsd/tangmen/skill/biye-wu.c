// biye-wu.c 碧叶随风舞

inherit SKILL;

mapping *action = ({
([	"action" : "$N双手扬起，轻飘飘一式「叶落」，掌若落叶，向$n的$l拍去",
	"force" : 60,
        "damage" : 90,
	"dodge" : 2,
	"skill_name" : "叶落",
	"lvl" : 0,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左脚为轴心，右脚一旋，双手交替挥舞，如竹叶翻飞，正是「叶舞」，向$n的$l拍下",
	"force" : 80,
	"dodge" : 0,
"damage" : 90,
	"skill_name" : "叶舞",
	"lvl" : 20,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身体高高跃起，左手立在胸前，右臂微曲，使一招「叶飘零」，向$n的$l和面门打去",
	"force" : 100,
	"dodge" : -2,
"damage" : 90,
	"skill_name" : "叶飘零",
	"lvl" : 40,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N微一运劲，双掌青筋爆露，一式「枯叶」，将$n浑身上下都笼罩在重重掌影之中",
	"force" : 200,
	"dodge" : -4,
"damage" : 90,
	"skill_name" : "枯叶",
	"lvl" : 60,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双掌平摊，左掌缓缓收至肩，右掌猛向前推出，\n掌风带着破空声，一招「弹枝」，如竹枝反弹，直奔$n心窝而去",
	"force" : 300,
	"dodge" : -6,
"damage" : 100,
	"skill_name" : "弹枝",
	"lvl" : 80,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N突然收掌，由腹部向前向上推出，掌风如涛，一式「叶如潮」，一片劲风直逼$n",
	"force" : 500,
"damage" : 100,
	"dodge" : -8,
	"skill_name" : "叶如潮",
	"lvl" : 100,
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练碧叶随风舞必须空手。\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 30)
		return notify_fail("你的碧云心法火候不够，无法学碧叶随风舞。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练碧叶随风舞。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

///* ----------------
//mapping query_action(object me, object weapon)
//{
//	return action[random(sizeof(action))];
//}
//-------------------*/

mapping query_action(object me, object weapon)
{
	int i, level;
    level   = (int) me->query_skill("biye-wu",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练碧叶随风舞。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"biye-wu/" + action;
}
