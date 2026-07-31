//xiantian-qiangjue.c 中平枪法

#include "ansi.h"

inherit SKILL;

mapping *action = ({
([	"action": "$N双手一别，尽力前伸，使出一招「破空」，手中$w平平直出，刺向$n的$l",
	"force" : 100,
	"dodge": -5,
	"damage": 1000,
	"skill_name" : "破空",
	"damage_type": "神伤"
]),
([	"action": "$N手中$w盘旋回转，风响阵阵，屈身下蹲，反手一招「溟陨」自下向$n的$l刺去",
	"force" : 200,
	"dodge": -10,
	"damage": 2000,
	"skill_name" : "溟陨",
	"damage_type": "神伤"
]),
([	"action": "$N举起$w，抖出一朵枪花，一招「王怒」向$n胸前扎去",
	"force" : 300,
	"dodge": -15,
	"damage": 3000,
	"skill_name" : "王怒",
	"damage_type": "神伤"
]),
([	"action": "$N一招「神威」，手中$w划个小圈消去$n的后招，而后$w微抬，指向$n的$l",
	"force" : 400,
	"dodge": -25,
	"damage": 4000,
	"skill_name" : "神威",
	"damage_type": "神伤"
]),
});

int valid_enable(string usage) { return usage=="spear" ||  usage=="parry"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "spear")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力不够练先天枪诀。\n");

	me->receive_damage("qi", 50);
	return 1;
}
