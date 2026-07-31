// douzhan-shengjing.c 斗战圣经
// By Vin 2000

#include <ansi.h>

inherit SHAOLIN_SKILL;
 
mapping *action = ({
([      "action": "$N身形稍退，一招「大闹地府」，手中$w迎风一抖，朝着$n劈头盖脸地砸将下",
	"dodge" : 350,
	"attack": 350,
	"force" : 350,
	"damage": 350,
	"parry" : 350,
	"lvl" : 0,
	"damage_type": "砸伤"
]),
([      "action": "$N仰天长笑，看也不看，一招「败退天兵」，随手一棒向$n当头砸下",
	"dodge" : 450,
	"attack": 450,
	"force" : 450,
	"damage": 450,
	"parry" : 450,
	"lvl" : 25,
	"damage_type": "砸伤"
]),
([      "action": "$N一个虎跳，越过$n头顶，一招「勇斗神将」，手中$w抡个大圆，砸向$n$l",
	"dodge" : 550,
	"attack": 550,
	"force" : 550,
	"damage": 550,
	"parry" : 550,
	"lvl" : 50,
	"damage_type": "砸伤"
]),
([      "action": "$N一声巨喝，一招「百炼成精」！$n一愣之间，$N手中$w已呼啸而至，扫向$n的$l",
	"dodge" : 650,
	"attack": 650,
	"force" : 650,
	"damage": 650,
	"parry" : 650,
	"lvl" : 75,
	"damage_type": "砸伤"
]),
([      "action": "$N身形稍退，一招「大闹天宫」，手中$w迎风一抖，朝着$n劈头盖脸地砸将下",
	"dodge" : 750,
	"attack": 750,
	"force" : 750,
	"damage": 750,
	"parry" : 750,
	"lvl" : 100,
	"damage_type": "砸伤"
]),
([      "action": "$N使出「醉闹天会」，脚步跄踉，左一棒，右一棒，打得$n手忙脚乱，招架不迭",
	"dodge" : 850,
	"attack": 850,
	"force" : 850,
	"damage": 850,
	"parry" : 850,
	"lvl" : 130,
	"damage_type": "砸伤"
]),
([      "action": "$N连翻几个筋斗，使出「三打白骨」，手中$w转得如风车一般，一连三棒直击$n顶门",
	"dodge" : 950,
	"attack": 950,
	"force" : 950,
	"damage": 950,
	"parry" : 950,
	"lvl" : 160,
	"damage_type": "砸伤"
]),
([      "action": "$N一招「神通齐天」，手中$w化为万道霞光，乘$n目眩之时，$w已到了$n的$l",
	"dodge" : 1050,
	"attack": 1050,
	"force" : 1050,
	"damage": 1050,
	"parry" : 1050,
	"lvl" : 200,
	"damage_type": "砸伤"
]),
});


int valid_enable(string usage) { return  (usage =="parry")|| (usage =="club"); }

int valid_learn(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "club")
		return notify_fail("你必须先找一根棍子才能练斗战圣经。\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力不足，没有办法练斗战圣经，多练些内力再来吧。\n");

	if ((int)me->query_skill("force") < 600)
		return notify_fail("你的内功火候太浅，没有办法练斗战圣经。\n");

	if ((int)me->query_skill("club", 1) < 600)
		return notify_fail("你的基本棍法火候太浅，没有办法练斗战圣经。\n");

	if ((int)me->query_skill("club", 1) < (int)me->query_skill("douzhan-shengjing", 1))
		return notify_fail("你的基本棍法水平还不够，无法领会更高深的斗战圣经。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action) - 1; i >= 0; i--)
		if (level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("douzhan-shengjing", 1);

	if (random(me->query_skill("douzhan-shengjing", 1)) > 120 &&
	     me->query_skill("force") > 100 &&
	     me->query("neili") > 1000 &&
	     random(10) > 6)
	{
		me->add("neili", -100);
		return ([
		"action": HIY "$N" HIY "将手中" + me->query_temp("weapon")->query("name")
			  + HIY "迎风一挥，使出必杀绝技「" NOR + HIR "我命由我 "
			  "不由天" NOR + HIY "」。"
			  + me->query_temp("weapon")->query("name") + HIY "登时幻出"
			  "万千虚\n影，对准$n的脑门直劈而下。这一下要是打中，恐怕连大"
			  "罗金仙也难逃一命" NOR,
		"force" : 2000,
		"attack": 2000,
		"damage": 2000,
		"dodge" : -50,
		"damage_type": "砸伤"]);
	}

	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 50, level *15 /1)];
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 500)
		return notify_fail("你的体力不够练斗战圣经。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的内力不够练斗战圣经。\n");

	me->receive_damage("qi", 500);
	me->add("neili", -500);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"douzhan-shengjing/" + action;
}

