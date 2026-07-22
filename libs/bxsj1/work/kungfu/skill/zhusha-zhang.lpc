//shusha-zhang.c 朱砂掌
//written by cool

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「虚步推手」，似掌非掌，双手一挥，直向$n的$l击去",
	"force" : 180,
       "dodge" : 5,
       "parry" : -5,
	"lvl" : 0,
	"skill_name" : "虚步推手",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形一转，一式「双封掌」，左掌斜向外侧，掌心向下，封向$n的$l",
	"force" : 220,
        "dodge" : -10,
        "parry" : 15,
	"lvl" : 20,
	"skill_name" : "双封掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「破风穿云」，身形前冲，双掌向前插出，直取$n的$l",
	"force" : 260,
        "dodge" : 15,
        "parry" : -10,
	"lvl" : 40,
	"skill_name" : "破风穿云",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N两掌一分，一式「引针腰斩」，左掌反擒$n的手部，右掌向$n的腰胁推劈",
	"force" : 300,
        "dodge" : -5,
        "parry" : -10,
	"lvl" : 60,
	"skill_name" : "引针腰斩",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N右掌拍下，一式「反摔掌」，左掌以掌背反摔$n的头部",
	"force" : 340,
        "dodge" : 0,
        "parry" : 10,
	"lvl" : 80,
	"skill_name" : "反摔掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N突然身形一缓，使出一式「偷漏掌」，右脚前扣，右掌向外圈手，又外向里拍向$n的$l",
	"force" : 380,
        "dodge" : -5,
        "parry" : 5,
	"lvl" : 100,
	"skill_name" : "偷漏掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「单臂挑山」，右掌向下伸出，掌心翻转，猛地向上拍向$n的$l",
	"force" : 400,
        "dodge" : -30,
        "parry" : 30,
	"lvl" : 120,
	"skill_name" : "单臂挑山",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一声大喝，一招「开门见山」，招式沉稳，双掌暗红，迎面拍向$n的头部",
	"force" : 450,
        "dodge" : 0,
        "parry" : -5,
	"damage": 35,
	"lvl" : 150,
	"skill_name" : "开门见山",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry" ;
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练朱砂掌必须空手。\n");
	if ((int)me->query_skill("guiyuan-tunafa", 1) < 20)
		return notify_fail("你的归元吐纳法火候不够，无法学朱砂掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练朱砂掌。\n");
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
	level   = (int) me->query_skill("zhusha-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练朱砂掌。\n");
	me->receive_damage("qi", 10);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if( random(me->query_skill("zhusha-zhang")) > 60 && (me->query_condition("warm_poison")<50))
	victim->apply_condition("warm_poison", random(me->query_skill("zhusha-zhang")/20) + 1 + victim->query_condition("warm_poison"));
}

