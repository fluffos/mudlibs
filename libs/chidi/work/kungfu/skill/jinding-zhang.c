// jinding-zhang.c 金顶绵掌
// create by host nov,27

inherit SKILL;

mapping *action = ({
([	"action" : "$N使一式「三阳开泰」，双掌如刀般大开大合，齐齐击向$n的$l",
	"force" : 50,
        "dodge" : 5,
        "parry" : 10,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "三阳开泰",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形飘然移动，一式「五气程祥」，幻出漫天掌影罩向$n的全身",
	"force" : 100,
        "dodge" : 30,
        "parry" : 15,
	"damage": 30,
	"lvl" : 10,
	"skill_name" : "五气程祥",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N运起全身劲力,使一式「罡风推云」，双掌一前一后, 快速向$n的$l击去",
	"force" : 150,
        "dodge" : 30,
        "parry" : 20,
	"damage": 40,
	"lvl" : 20,
	"skill_name" : "罡风推云",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「逆流捧沙」，身形凝立不动，掌似爪形，向$n横击过去",
	"force" : 200,
        "dodge" : 15,
        "parry" : 20,
	"damage": 50,
	"lvl" : 30,
	"skill_name" : "逆流捧沙",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形拔地而起，使出一式「雷洞霹雳」，双掌带着风雷声，由上而下的击向$n的$l",
	"force" : 250,
        "dodge" : 30,
        "parry" : 20,
	"damage": 65,
	"lvl" : 50,
	"skill_name" : "雷洞霹雳",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N微微一笑，使出一式「金顶佛光」，掌中幻出万道金光,直射向$n的$l",
	"force" : 280,
        "dodge" : 10,
        "parry" : 40,
	"damage": 75,
	"lvl" : 70,
	"skill_name" : "金顶佛光",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N口喧一声佛号，使一式「梵心降魔」，双掌挟狂风暴雪之势，猛地劈向$n的$l",
	"force" : 320,
        "dodge" : 40,
        "parry" : 5,
	"damage": 95,
	"lvl" : 90,
	"skill_name" : "梵心降魔",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「法尊八荒」，身行骤然化作一道白光,出现在$n四面八方,击向$n全身",
	"force" : 380,
        "dodge" : 50,
        "parry" : 20,
	"damage": 105,
	"lvl" : 110,
	"skill_name" : "法尊八荒",
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" ;
}
int valid_combine(string combo) { return combo=="tiangang-zhi"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
          return notify_fail("练金顶绵掌必须空手。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
           return notify_fail("你的「临济十二庄」火候不够，无法学金顶绵掌。\n");
/*        if ((int)me->query_skill("yugalism", 1) < 20)
           return notify_fail("你的「大乘涅磐功」火候太浅。\n"); */
	if ((int)me->query("max_neili") < 100)
            return notify_fail("你的内力太弱，无法练金顶绵掌。\n");
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
        level   = (int) me->query_skill("jinding-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 40)
                return notify_fail("你的内力不够练金顶绵掌。\n");

	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


string perform_action_file(string action)
{
        return __DIR__"jinding-zhang/"+ action;
}
