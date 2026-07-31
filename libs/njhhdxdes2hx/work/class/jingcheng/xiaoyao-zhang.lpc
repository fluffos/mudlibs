// xiaoyao-zhang

inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「仙人拿云」，右手挟着一股劲风，直拿$n的右肩[缺盆穴]。",
	"force" : 100,
	"dodge" : 10,
	"damage": 5,
	"lvl"   : 0,
	"skill_name" : "拿云式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N上前跃出，一招「高人品萧」，左手一伸，架住了$n的招式，右手平划，向
$n的颈根抓去。",
	"force" : 150,
	"dodge" : 5,
	"damage": 10,
	"lvl"   : 10,
	"skill_name" : "品萧式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N双手平伸，十指微微上下抖动，一招「伯伢抚琴」打向$n的$l",
	"force" : 200,
	"dodge" : 10,
	"damage": 20,
	"lvl"   : 25,
	"skill_name" : "抚琴式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N左手上拦，右手内挥，一招「霸王击鼓」击向$n胸口",
	"force" : 250,
	"dodge" : 10,
	"damage": 25,
	"lvl"   : 40,
	"skill_name" : "击鼓式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N前脚着地，一招「夸夫追日」劲气笼罩$n的全身",
	"force" : 350,
	"dodge" : 40,
	"damage": 30,
	"lvl"   : 60,
	"skill_name" : "追日式" ,		
	"damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练逍遥掌必须空手。\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
		return notify_fail("你的九阳神功火候不够，无法学逍遥掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练逍遥掌。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("xiaoyao-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练逍遥掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

