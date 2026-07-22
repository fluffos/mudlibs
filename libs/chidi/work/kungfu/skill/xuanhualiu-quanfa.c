// 青云(diabio)编于2001年版权所有
// xuanhualiu-quanfa.c 喧哗流拳法
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N怒吼一声，双拳以双风灌耳之势轰向$n的脑部",
        "dodge": 30,
        "force": 240,
        "damage": (int)this_player()->query_skill("xuanhualiu-quanfa",1),
        "damage_type": "瘀伤"
]),
([      "action": "$N虚晃一招，揪住$n的头发照准面部狠狠的一拳打了下去",
        "dodge": 10,
        "force": 340,
        "damage": (int)this_player()->query_skill("xuanhualiu-quanfa",1),
        "damage_type": "瘀伤"
]),
([	"action": "$N一拳打向$n的面部，乘他忙于招架时右拳乘机打向$n的$l",
	"dodge": -20,
	"force": 440,
	"damage": (int)this_player()->query_skill("xuanhualiu-quanfa",1),
	"damage_type": "瘀伤"
]),
([	"action": "$N怒叫一声：打架篇第二章，$N左手拿向$n的肩头，右拳打向$n的胸口",
	"dodge": 10,
	"force": 540,
	"damage": (int)this_player()->query_skill("xuanhualiu-quanfa",1),
	"damage_type": "内伤"
]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

mapping query_action(object me, object weapon)
{
	int i, level;
    level   = (int) me->query_skill("xuanhualiu-quanfa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练喧哗流拳法必须空手。\n");
	if ((int)me->query_skill("shayi-xinfa", 1) < 101)
		return notify_fail("你的杀意心法火候不够，无法练喧哗流拳法。\n");
	if ((int)me->query("max_neili") < 60)
		return notify_fail("你的内力太弱，无法练喧哗流拳法");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 8)
		return notify_fail("你的内力不够练喧哗流拳法。\n");
	if (me->query_skill("xuanhualiu-quanfa", 1) < 50)
		me->receive_damage("qi", 20);
	else
		me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( damage_bonus < 100 ) return 0;
	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 100) / 2 );
		return HIR "你一拳未完第二拳又打了下去，正是喧哗流奥意"HIW"[二重劲]"NOR""HIR"只见"+victim->name()+"狂喷一口鲜血身不由己的向后倒飞了出去！\n" NOR;
	}

//        if( me->query_skill("shayi-xinfa") > 10 ) {
//           victim->apply_condition("xhlq_poison", (me->query_skill("xuanhualiu-quanfa")/10) + 1 +
//            victim->query_condition("xhlq_poison"));
//        }
	
}
string perform_action_file(string action)
{
	return __DIR__"xuanhualiu-quanfa/" + action;
}

