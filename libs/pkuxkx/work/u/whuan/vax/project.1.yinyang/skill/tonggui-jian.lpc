// tonggui-jian.c 同归剑法

inherit SKILL;

mapping *action = ({
([	"action" : "$N虚步提腰，一招「同归于尽」，势如疯虎，手中$w绽出万点银光，一剑点向$n的$l",
	"force"  : 100,
	"dodge"  : 20,
	"parry"  : 10,
	"damage" : 80,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "紧接着$N一招「以攻为守」，浑不顾$n的攻势，一剑直劈而出",
	"force"  : 90,
	"dodge"  : 15,
	"parry"  : 20,
	"damage" : 90,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「江天一色」，$w自上而下划出一个大弧，平平地向$n的$l刺去",
	"force"  : 110,
	"dodge"  : 15,
	"parry"  : 35,
	"damage" : 110,
        "lvl" : 9,
	"damage_type" : "刺伤"
]),
([	"action" : "$N手拿$w，一招「玉石俱焚」，集聚全身的功力向$n的$l飞速一击",
	"force"  : 105,
	"dodge"  : 10,
	"parry"  : 20,
	"damage" : 130,
        "lvl" : 19,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出「你死我活」，$w剑锋直出，划出无数圆圈，绵绵不断划向$n的$l",
	"force"  : 155,
	"dodge"  : 60,
	"parry"  : 70,
	"damage" : 170,
        "lvl" : 29,
	"damage_type" : "刺伤"
]),
([	"action" : "$N左手捏了个剑诀，一招「虚虚实实」，右手$w挽了个斗大的剑花，逼向$n的$l",
	"force"  : 160,
	"dodge"  : 5,
	"parry"  : 5,
	"damage" : 175,
        "lvl" : 39,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「柳暗花明」，身形高高跃起，$w剑尖颤动，入灵蛇一样扎向$n的$l",
	"force"  : 165,
	"dodge"  : 5,
	"parry"  : 10,
	"damage" : 180,
        "lvl" : 59,
	"damage_type" : "刺伤"
]),
([	"action" : "$N前欺一步，一招「死而后已」，剑锋平扫，转身撩向$n的$l",
	"force"  : 210,
	"dodge"  : 15,
	"parry"  : 20,
	"damage" : 180,
        "lvl" : 79,
	"damage_type" : "刺伤"
]),
([  "action" : "$N左手虚抱，一招「拨云见日」，$w中宫直进，刺向$n的$l",
	"force" : 220,
	"dodge" :  10,
	"parry"  : 5,
	"damage" : 220,
        "lvl" : 99,
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("daoxue-xinfa", 1) < 20)
		return notify_fail("你的道学心法不够，强练会走火入魔的。\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 20)
		return notify_fail("你的先天功火候太浅。\n");
        if ((int)me->query_skill("quanzhen-jian", 1) < 40)
                return notify_fail("你的全真剑法不够. \n");
	return 1;
}
mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("tonggui-jian",1);
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
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力不够练同归剑法。\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tonggui-jian/" + action;
}

string query_yinyang()
{
	return "太阳";
}