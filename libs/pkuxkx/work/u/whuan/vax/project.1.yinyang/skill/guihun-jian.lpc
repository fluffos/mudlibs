// guihun-jian.c

inherit SKILL;

mapping *action = ({
([	"action":"$N使一式「残叶溅血」，手中$w幻成一缕蓝霭，忽聚忽散的刺向$n的$l",
	"force" : 160,
        "dodge" : -10,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "残叶溅血",
	"damage_type":	"刺伤"
]),
([	"action":"$N错步上前，使出「死神唇笑」，$w扬起遮天的怨气向$n的$l劈去",
	"force" : 200,
        "dodge" : -10,
	"damage": 20,
	"lvl" : 9,
	"skill_name" : "死神唇笑",
	"damage_type":	"割伤"
]),
([	"action":"$N一式「征尘迷眼」，仰天长啸一声，似笑还哭，手中$w遥摇指向$n的$l",
	"force" : 220,
        "dodge" : 5,
	"damage" : 20,
	"lvl" : 18,
	"skill_name" : "征尘迷眼",
	"damage_type":	"割伤"
]),
([	"action":"$N将手中$w挥成一个圆圈，凛冽的杀气源源吐出，正是「奈何回首」，剑光如轮疾转，\n向$n的$l狂劈过去",
	"force" : 260,
        "dodge" : 10,
	"damage": 35,
	"lvl" : 27,
	"skill_name" : "奈何回首",
	"damage_type":	"割伤"
]),
([	"action":"$N使出一招[黄泉饮恨],$w呜咽着冽冽的风声，看似缓慢的从$n头顶划下",
	"force" : 300,
        "dodge" : 15,
	"damage": 40,
	"lvl" : 36,
	"skill_name" : "黄泉饮恨",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w斜指苍天，一式[剑挑落辉],无限凄惨的刺向$n的$l",
	"force" : 320,
        "dodge" : 5,
	"damage": 45,
	"lvl" : 44,
	"skill_name" : "剑挑落辉",
	"damage_type":	"刺伤"
]),
([	"action":"$N大呼一声,手中$w猛然向前刺出，斜身发出一招[怒发冲冠]",
	"force" : 360,
        "dodge" : 5,
	"damage": 90,
	"lvl" : 52,
	"skill_name" : "怒发冲冠",
	"damage_type":	"刺伤"
]),
([	"action":"$N身形暴长，$w直指青天，[河山属谁]!!",
	"force" : 400,
        "dodge" : 5,
	"damage": 100,
	"lvl" : 60,
	"skill_name" : "河山属谁",
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }



int valid_learn(object me)
{
        if ((int)me->query("pkscore") < 5000)
                return notify_fail("这本归魂秘籍想来不是靠你自己的真本事得来的吧。\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("chuforce", 1) < 70)
		return notify_fail("你的楚家气功火候太浅。\n");
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
	level   = (int) me->query_skill("guihun-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
/*
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练归魂剑法。\n");
	me->receive_damage("qi", 25);
*/
    return notify_fail("归魂剑法只能靠读书提高。\n");
}
string perform_action_file(string action)
{
	return __DIR__"guihun-jian/" + action;
}

string query_yinyang()
{
	return "太阴";
}