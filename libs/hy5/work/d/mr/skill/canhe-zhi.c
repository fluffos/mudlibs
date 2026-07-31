// canhe-zhi.c 参合指
inherit SKILL;

mapping *action = ({
([	"action" : "$N劲风激荡，双指错落搭置，一招「目不识丁」凶狠地向$n的面门插去",
	"force" : 170,
	"dodge" : 5,
	"parry" : 5,
	"lvl" : 5,
	"skill_name" : "目不识丁",
	"damage_type" : "刺伤"
]),
([	"action" : "$N大吼一声，十指上下分飞，一招「画龙点睛」，双指直取$n的双目",
	"force" : 230,
	"dodge" : 8,
	"parry" : 10,
	"lvl" : 15,
	"skill_name" : "画龙点睛",
	"damage_type" : "刺伤"
]),
([	"action" : "$N十指互错，虚幻虚实，一招「扑朔迷离」，前后左右，瞬息间向$n攻出了六招",
	"force" : 300,
	"dodge" : 15,
	"parry" : 20,
	"lvl" : 30,
	"skill_name" : "扑朔迷离",
	"damage_type" : "刺伤",
]),
([	"action" : "$N身行腾空而起，一招「受宠若惊」，来势奇快，向$n的命门猛插下去",
	"force" : 280,
	"dodge" : 20,
	"parry" : 25,
	"lvl" : 40,
	"skill_name" : "受宠若惊",
	"damage_type" : "刺伤"
]),
([	"action" : "$N身行一闪，若有若无捱到$n身前，一招「滔滔不绝」，插向$n的$l",
	"force" : 350,
	"dodge" : 25,
	"parry" : 25,
	"lvl" : 50,
	"skill_name" : "滔滔不绝",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「退避三舍」，右手一拳击出，左掌化指，一掌一指凌空击向$n的$l",
	"force" : 410,
	"dodge" : 25,
	"parry" : 30,
	"lvl" : 60,
	"skill_name" : "退避三舍",
	"damage_type" : "刺伤"
]),
([	"action" : "$N双掌化指，指中带掌，双手齐推，一招「卧薪尝胆」，一股排山倒海的内力，直扑$n面门",
	"force" : 480,
	"dodge" : 30,
	"parry" : 35,
	"lvl" : 70,
	"skill_name" : "卧薪尝胆",
	"damage_type" : "刺伤"
]),
([	"action" : "$N突然身行急转，一招「相煎何急」，十指飞舞，霎时之间将$n四面八方都裹住了",
	"force" : 540,
	"dodge" : 45,
	"parry" : 40,
	"lvl" : 80,
	"skill_name" : "相煎何急",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练参合指必须空手。\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 15)
		return notify_fail("你的神元功火候不够，无法学参合指。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练参合指。\n");
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
	level   = (int) me->query_skill("canhe-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练参合指。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -8);
	return 1;
}

