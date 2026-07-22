// tianluo-diwang 天罗地网势
// By River
// Modified by darken@SJ

#include <ansi.h>;
inherit SKILL;
mapping *action = ({
([
	"action" : "$N左掌划一半圆，右掌划出另一半圆，呈合拢之势，疾拍$n的胸前大穴",
	"lvl" : 0,
	"damage_type" : "瘀伤",
]),
([
	"action" : "$N左掌护胸，右拳凝劲后发，深吸一口气，缓缓推向$n的$l",
	"lvl" : 20,
	"damage_type" : "瘀伤",
]),
([
	"action" : "$N纵身向前扑去，一下急冲疾缩，就在两臂将合未合之际，双手抱向$n的$l",
	"lvl" : 30,
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N两掌上下护胸，掌势突然一变，骤然化为满天掌雨，攻向$n的$l",
	"damage_type" : "瘀伤",
	"lvl" : 50,     
]),
([
	"action" : "$N长袖挥处，两股袖风扑出，$n只觉得密不透风，周身都是掌印，怎么也闪躲不开",
	"lvl" : 70,        
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N双臂飞舞，双掌宛似化成了千手千掌，任$n如何跃腾闪躲，始终逃不出所围的圈圈",
	"lvl" : 90,
	"damage_type" : "瘀伤"
]), 
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("空手方能练习天罗地网势。\n");
	if ( me->query_skill("yunu-xinjing", 1) < 10 )
		return notify_fail("你的玉女心经领悟不够，无法修习天罗地网势。\n");
	if ( me->query_skill("hand", 1) < 20)
		return notify_fail("你的基本手法太差，无法研习天罗地网势。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, j, level;
	level = (int)me->query_skill("tianluo-diwang", 1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action" : action[j]["action"],
				"force" : 100+random(250),
				"dodge": random(20)-10,
				"parry": random(10),
				"lvl" : action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
			]);
		}
	}
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 30)
		return notify_fail("你的体力不够练天罗地网势了。\n");
	if ( me->query("neili") < 10)
		return notify_fail("你的内力不够练天罗地网势了。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lvl = me->query_skill("hand");

	if( random(lvl) > 300 && !victim->is_lost() && random(2)) {
		message_vision(HIW"$N一阵紧密的攻击下，$n丝毫无法准确的攻击$N！\n"NOR, me, victim);
		victim->start_lost(1+random(2));
	}
}
