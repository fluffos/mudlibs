// duoming-jinhua.c 夺命金花
// congw


inherit SKILL;

mapping *action = ({
([	"action" : "$N虚步提腰，一招「金光灿烂」，手中$w射向$n的$l",
	"force" : 60,
	"dodge" : 20,
	"parry" : 10,
	"damage" : 45,
        "lvl" : 0,
	"damage_type" : "挫伤"
]),
([	"action" : "$N向前跨上一步，左手虚晃，右手$w使出一式「满天花雨」直设$n的$l",
	"force" : 70,
	"dodge" : 25,
	"parry" : 20,
	"damage" : 60,
        "lvl" : 10,
	"damage_type" : "挫伤"
]),
([	"action" : "$N身形往右一挫，左手显然多了一把$w，使出一式「满天星」射向$n的$l",
	"force" : 80,
	"dodge" : 30,
	"parry" : 30,
	"damage" : 70,
        "lvl" : 20,
	"damage_type" : "刺伤"
]),
([	"action" : "$N双膝下沉，右手$w使出一式「风花雪月」，由下而上疾射$n的$l",
	"force" : 90,
	"dodge" : 45,
	"parry" : 40,
	"damage" : 80,
        "lvl" : 30,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「香飘万里」，$w自空中划出一个大弧，平平地向$n的$l直射过去",
	"force" : 100,
	"dodge" : 55,
	"parry" : 55,
	"damage" : 90,
        "lvl" : 40,
	"damage_type" : "挫伤"
]),
([	"action" : "$N纵身一跃，离地两丈，一招「天女散花」，手中$w化作点点寒星$n的$l疾射过去",
	"force" : 110,
	"dodge" : 65,
	"parry" : 75,
	"damage" : 100,
        "lvl" : 50,
	"damage_type" : "刺伤"
]),

([	"action" : "$N两个转身，手中$w一闪，一招「断肠花」射向$n的$l",
	"force" : 130,
	"dodge" : 100,
	"parry" : 100,
	"damage" : 120,
        "lvl" : 80,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「夺命金花」，$w化作满天飞雨，罩地挥向$n的全身",
	"force" : 200,
	"dodge" : 200,
	"parry" : 200,
	"damage" : 150,
        "lvl" : 100,
	"damage_type" : "刺伤"
]),

});


int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("duoming-jinhua", 1) < 20)
		return notify_fail("你的太极神功火候太浅。\n");
	if ((int)me->query_skill("duoming-jinhua", 1) < 20)
		return notify_fail("你的太极拳火候太浅。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("duoming-jinhua",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练太极剑法。\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"duoming-jinhua/" + action;
}
