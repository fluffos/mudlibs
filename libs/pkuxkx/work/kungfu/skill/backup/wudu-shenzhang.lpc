// wudu-shenzhang.c 五毒神掌
// By Kayin@ CuteRabbit Studio 99-4-16 13:34 new
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l",
        "dodge": 30,
        "force": 840,
        "damage": (int)this_player()->query_skill("wudu-shenzhang",1),
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形旋扑向$n，双掌飞舞拍向$n的$l",
        "dodge": 10,
        "force": 840,
        "damage": (int)this_player()->query_skill("wudu-shenzhang",1),
        "damage_type": "瘀伤"
]),
([	"action": "$N将毒质运至右手，阴毒无比地抓向$n的$l",
	"dodge": -20,
	"force": 840,
	"damage": (int)this_player()->query_skill("wudu-shenzhang",1),
	"damage_type": "瘀伤"
]),
([	"action": "$N双掌如风,连环拍向$n的$l",
	"dodge": 10,
	"force": 840,
	"damage": (int)this_player()->query_skill("wudu-shenzhang",1),
	"damage_type": "瘀伤"
]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

mapping query_action(object me, object weapon)
{
	int i, level;
    level   = (int) me->query_skill("wudu-shenzhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练五毒神掌必须空手。\n");
	if ((int)me->query_skill("yunu-xinfa", 1) < 10)
		return notify_fail("你的玉女心法火候不够，无法练星宿毒掌。\n");
	if ((int)me->query("max_neili") < 60)
		return notify_fail("你的内力太弱，无法练五毒神掌");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 8)
		return notify_fail("你的内力不够练五毒神掌。\n");
	if (me->query_skill("wudu-shenzhang", 1) < 50)
		me->receive_damage("qi", 20);
	else
		me->receive_damage("qi", 30);
	me->add("neili", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( damage_bonus < 100 ) return 0;
	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 100) / 2, me);
		return HIB "你听到「砰」一声巨响，"+victim->name()+"像泄气的皮球缓缓的瘫倒！\n" NOR;
	}

        if( me->query_skill("yunu-xinfa") > 10 ) {
            victim->apply_condition("wuduz_poison", (me->query_skill("wudu-shenzhang")/10) + 1 +
            victim->query_condition("wuduz_poison"));
	}
	
}
string perform_action_file(string action)
{
	return __DIR__"wudu-shenzhang/" + action;
}

