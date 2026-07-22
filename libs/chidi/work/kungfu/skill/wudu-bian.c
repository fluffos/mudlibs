// wudu-bian.c 五毒鞭法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":		"$N轻抖手腕，一招「青蛇吐芯」，手中$w抖得笔直，直向$n卷去",
	"force":		60,
	"dodge":		30,
	"damage":		30,
	"lvl" : 0,
	"skill_name" : "青蛇吐芯",
	"damage_type":	"劈伤"
]),
([	"action":		"$N身形一转，一招「毒蝎反尾」，$w在空中转了个圈，以怪异的角度劈向$n",
	"force":		150,
	"dodge":		20,
	"damage":		50,
	"lvl" : 10,
	"skill_name" : "毒蝎反尾",
	"damage_type":	"劈伤"
]),
([	"action":		"$N一抖长鞭，一招「黑蛛吐丝」，手中$w化做无数幻影，罩向$n",
	"force":		200,
	"dodge":		30,
	"damage":		60,
	"lvl" : 20,
	"skill_name" : "黑蛛吐丝",
	"damage_type":	"刺伤"
]),
([	"action":		"$N力贯鞭梢，一招「蟾蜍出洞」，手中$w忽左忽右，直劈向$n胸口",
	"force":		300,
	"dodge":		10,
	"damage":		80,
	"lvl" : 30,
	"skill_name" : "蟾蜍出洞",
	"damage_type":	"刺伤"
]),
([	"action":		"$N运气于腕，一招「蜈蚣翻身」，手中$w转起无数个圈圈，带着一股阴风，直向$n扑去",
	"force":		500,
	"dodge":		-20,
	"damage":		150,
	"lvl" : 40,
	"skill_name" : "蜈蚣翻身",
	"damage_type":	"内伤"
])

});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query_skill("wudu-xinfa") < 30 )
		return notify_fail("你的五毒心法太低，不能练五毒鞭。\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

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
	level   = (int) me->query_skill("wudu-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练五毒鞭法。\n");
	me->receive_damage("qi", 5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wudu-bian/" + action;
}
