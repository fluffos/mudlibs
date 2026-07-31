//Cracked by Kafei
// hanbing-mianzhang.c, based on xingxiu-duzhang.c
// by Xuanyuan 07/15/2001
#include <ansi.h>
inherit SKILL;
//冰冻三尺。$N往後飘出数丈，双掌在空中一划，带起一阵寒风，向$n的$1拍去
//寒风刺骨。$N突然双手化掌为指，向$n的$1戳下去，
//冰雪连天。$N身形一变，绕着$n飞奔，同时双掌疾拍把$n包裹在掌影只中，
//

mapping *action = ({
([      "action": "$N往後飘出数丈，双掌在空中一划，带起一阵寒风，向$n的$1拍去",
        "dodge": 30,
        "force": 80,
        "lvl" : 0,
        "skill_name" : "冰冻三尺",
        "damage_type": "瘀伤"
]),
([	"action": "$N突然双手化掌为指，向$n的$1戳下去",
	"dodge": -20,
	"force": 130,
	"damage": 25,
        "lvl" : 20,
        "skill_name" : "寒风刺骨",
	"damage_type": "瘀伤"
]),
([	"action": "$N身形一变，绕着$n飞奔，同时双掌疾拍把$n包裹在掌影只中",
	"dodge": 10,
	"force": 180,
	"damage": 40,
        "lvl" : 40,
        "skill_name" : "冰雪连天",
	"damage_type": "瘀伤"
]),
([      "action" : "$N使一式「风雪江山」，双掌挟狂风暴雪之势，猛地劈向$n的$l",
        "force" : 240,
        "dodge" : 30,
        "parry" : 30,
        "damage": 50,
        "lvl" : 60,
        "skill_name" : "风雪江山",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「霜华满地」，双掌带着萧瑟的秋气，拍向$n的$l",
        "force" : 280,
        "dodge" : 30,
        "parry" : 35,
        "damage": 70,
        "lvl" : 70,
        "skill_name" : "霜华满地",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身法陡然一变，使出一式「仙乡冰舸」，掌影千变万幻，令$n无法躲闪",
        "force" : 320,
        "dodge" : 40,
        "parry" : 45,
        "damage": 90,
        "lvl" : 80,
        "skill_name" : "仙乡冰舸",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N清啸一声，一式「冰霜雪雨」，双掌挥舞，如同雪花随风而转，击向$n的$l",
        "force" : 440,
        "dodge" : 45,
        "parry" : 50,
        "damage": 110,
        "lvl" : 90,
        "skill_name" : "冰霜雪雨",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

mapping query_action(object me)
{
        if (random(me->query_skill("strike")) > 120 &&
            me->query_skill("force") > 120 &&
            me->query("neili") > 100 ) {
                me->add("neili", -50);
                return ([
                "action":BLU "突然$N如同「吸血青蝠」，欺近$n的身前，张嘴便向$n的$l咬去。"NOR,
                "force": 500,
		"damage": 100,
                "damage_type": "咬伤"]);
        }
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练寒冰绵掌必须空手。\n");
	if ((int)me->query_skill("shenghuo-xuanming", 1) < 25)
		return notify_fail("你的圣火玄冥功火候不够，无法练寒冰绵掌。\n");
	if ((int)me->query("max_neili") < 60)
		return notify_fail("你的内力太弱，无法练寒冰绵掌");
	return 1;
}


int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 8)
		return notify_fail("你的内力不够练寒冰绵掌。\n");

	if (me->query_skill("hanbing-mianzhang", 1) < 50)
		me->receive_damage("jingli", 20, "精力透支过度死了。");
	else
		me->receive_damage("jingli", 30, "精力透支过度死了。");
	me->add("neili", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("hanbing-mianzhang", 1)) > 30 ) {
		victim->apply_condition("xx_poison", 
		random(me->query_skill("hanbing-mianzhang", 1)) + victim->query_condition("xx_poison"));
	}
}
string perform_action_file(string action)
{
        if ( this_player()->query_skill("hanbing-mianzhang", 1) >= 30 )
                return __DIR__"hanbing-mianzhang/" + action;
}
