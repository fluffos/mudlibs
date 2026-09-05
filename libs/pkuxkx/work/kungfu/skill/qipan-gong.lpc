// qipan-gong 玄铁棋盘功

inherit SKILL;
mapping *action = ({
([	"action" : "$N一招「大飞」，手中$w轻轻颤动，连绵不绝地拍向$n的$l",
	"force" : 180,
	"dodge" : 20,
	"damage" : 30,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出一式「双活」,$w迅捷无比的拍向$n的$l",
	"force" : 100,
	"dodge" : 15,
	"damage" : 40,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「长生」，手中$w轻颤，，平平地向$n的$l横飞过去",
	"force" : 120,
	"dodge" : 15,
	"damage" : 50,
        "lvl" : 9,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「收气」，手中$w化出的重重牌影合而为一，一气呵成地攻向$n的$l",
	"force" : 130,
	"dodge" : 10,
	"damage" : 60,
        "lvl" : 29,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出「打劫」，$w划出无数的光圈，缠住了$n的$l",
	"force" : 140,
	"dodge" : 5,
	"damage" : 70,
        "lvl" : 39,
	"damage_type" : "割伤"
]),
([	"action" : "$N左脚踏实，右脚虚点，一招「反扑」，右手一翻$w，左掌画了个圆弧，一齐逼向$n",
	"force" : 150,
	"dodge" : 5,
	"damage" : 80,
        "lvl" : 59,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「倒脱靴」，手中$w一沉，紧接着突然上撩，刺向$n的$l",
	"force" : 200,
	"dodge" : -5,
	"damage" : 90,
        "lvl" : 79,
	"damage_type" : "刺伤"
]),
([	"action" : "$N右脚微一点地，跃入半空，一招「推秤」，俯冲而下，直指$n的$l",
	"force" : 200,
	"dodge" : -5,
	"damage" : 100,
        "lvl" : 99,
	"damage_type" : "刺伤"
])
});
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("riyue-shengong", 1) < 20)
		return notify_fail("你的日月神功火候太浅。\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("qipan-gong",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练玄铁棋秤功。\n");
	me->receive_damage("qi", 30);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"qipan-gong/" + action;
}
