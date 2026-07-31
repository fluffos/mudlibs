// liujue-dao.c 六绝刀法

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w斜指，一招「当真一绝」，反身一顿，一刀向$n的$l撩去",
	"force" : 120,
	"dodge" : -10,
	"damage" : 10,
	"lvl" : 0,
	"skill_name" : "当真一绝",
	"damage_type" : "割伤"
]),
([      "action" : "$N一招「绝处逢生」，身形向后一纵，$w一提一收，平刃挥向$n的颈部",
	"force" : 140,
	"dodge" : -10,
	"damage" : 20,
	"lvl" : 20,
	"skill_name" : "绝处逢生",
	"damage_type" : "割伤"
]),
([      "action" : "$N展身虚步，提腰跃落，一招「天无绝人之路」，刀锋化作两股斩向$n",
	"force" : 160,
	"dodge" : -5,
	"damage" : 30,
	"lvl" : 40,
	"skill_name" : "天无绝人之路",
	"damage_type" : "割伤"
]),
([      "action" : "$N贴地滑行，一招「绝子绝孙」，手中$w直撩去$n的裆部",
	"force" : 180,
	"dodge" : 5,
	"damage" : 40,
	"lvl" : 60,
	"skill_name" : "绝子绝孙",
	"damage_type" : "割伤"
]),
([      "action" : "$N手中$w一沉，一招「凶前绝后」，双手持刃拦腰反切，两股刀锋砍向$n的前胸和后背",
	"force" : 200,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 80,
	"skill_name" : "凶前绝后",
	"damage_type" : "割伤"
]),
([      "action" : "$N挥舞$w，使出一招「绝望」，上劈下撩，左挡右开，齐齐罩向$n",
	"force" : 250,
	"dodge" : 15,
	"damage" : 60,
	"lvl" : 100,
	"skill_name" : "绝望",
	"damage_type" : "割伤"
])
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
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
	int i, level;
	level   = (int) me->query_skill("liujue-dao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

        	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liujue-dao/" + action;
}
