// jinshe-jian.c

#include <ansi.h>
inherit SKILL;

mapping *action = ({
	([	"name":		"金光蛇影",
		"action":	"$N使一招「金光蛇影」，手中的$w在一弹指间已向$n的$l连刺数剑",
		"dodge":	50,
		"parry" :	100,
		"force":	170,
		"damage" :	350,
		"damage_type":	"刺伤"
	]),
	([	"name":		"蛇影万道",
		"action":	"$N使一招「蛇影万道」，手中$w狂风骤雨般地向$n的$l连攻数剑",
		"dodge":	100,
		"parry" :	200,
		"force" : 	200,
		"damage":	370,
		"damage_type":	"刺伤"
	]),
	([	"name":		"雪地飞蛇",
		"action":	"$N身形一转，陡地贴地跃起，手中$w灵动夭跃，一招「雪地飞蛇」疾刺$n的$l",
                "dodge":	100,
                "parry" :	200,
		"force":	170,
		"damage" :	350,
		"damage_type":	"刺伤"
	]),
	([	"name":		"金蛇吞信",
		"action":	"$N身形一转，一招「金蛇吞信」，手中的$w从左肋下向$n的$l戳了过去",
		"dodge":	100,
		"parry" :	200,
		"force" : 	200,
		"damage":	320,
		"damage_type":	"刺伤"
	]),
	([	"name":		"金蛇狂舞",
		"action":	"$N手腕一抖，一招「金蛇狂舞」，$w挟著闪闪剑光，变幻无方逼向$n的$l",
		"dodge":	100,
		"parry" :	200,
		"force" : 	300,
		"damage":	350,
		"damage_type":	"刺伤"
	]),
	([	"name":		"灵蛇电闪",
		"action":	"$N心念电闪手腕疾振处，一招「灵蛇电闪」，$w以无法形容的速度直射$n的$l",
		"dodge":	100,
		"parry" :	200,
		"force" : 	250,
		"damage":	300,
		"damage_type":	"刺伤"
	]),
	([	"name":		"蛇困愁城",
		"action":	"$N身形一矮，一招「蛇困愁城」，手中的$w由下往上刺向$n的$l",
		"dodge":	100,
		"parry" :	200,
		"force" : 	300,
		"damage":	300,
		"damage_type":	"刺伤"
	]),
	([	"name":		"金蛇化龙",
		"action":	"$N手中$w剑光暴长，一招「金蛇化龙」，如千年蛇蝎往$n$l咬去",
		"dodge":	100,
		"parry" :	200,
		"force" : 	300,
		"damage":	400,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力不够，没有办法练金蛇剑法。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

        return notify_fail("金蛇剑法没法教授。\n");

}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 15 )
		return notify_fail("你的内力或气不够，没有办法练习金蛇剑法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -15);
	
	if ((int)me->query("qi") < 350)
		return notify_fail("你的体力不够练金蛇剑法。\n");
	if ((int)me->query("jing") < 300)
		return notify_fail("你的精力不够练金蛇剑法。\n");
	me->receive_damage("qi", 300);
	me->receive_damage("jing", 100);

	//write("你按著所学练了一遍金蛇剑法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

int effective_level() { return 25;}

string *parry_msg = ({
        "$n不退反进，气走周天，手中的$v狠狠磕开了$N的$w。\n",
	"$n回剑自守，架住了$N的$w。\n",
	"$n手中的$v化作千百把，护住了全身。\n",
	"$n手中的$v自上削下，几乎将$N的$w削成两段。\n",
});

string *unarmed_parry_msg = ({
        "$n使动$v，在身前布起了一道铜墙铁壁，封住了$N的攻势。\n",
	"$n一抖手中的$v，护住了全身。\n",
	"$n将$v往地上一刺，$v反弹起来，刚好直刺$N的双臂。\n",
	"$n举剑静立，一股内力从剑梢透出，逼开了$N。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
        return __DIR__"jinshe-jian/" + action;
}


