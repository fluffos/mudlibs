// Qijue-jian.c 凤凰七绝
// Cracked by 凌惊雪 5-20-2003

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N轻抚手中的$w，突然间只见剑光一闪再闪又一闪！\n三道刺骨的寒气已然袭上了$n的$l，正是一招「七绝寒杀」",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//1
([      "action" : "$N轻抚手中的$w，突然间只见剑光一闪再闪又一闪！\n三道刺骨的寒气已然袭上了$n的$l，正是一招「七绝寒杀」",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//2
([      "action" : "只见$N纵身轻轻跃起,一招「七绝夺命」,剑光如水,一泄千里,洒向$n全身",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//3
([      "action" : "只见$N脸色一寒，一招「七绝冰封」使出，$n周身的血液都似被这无尽的笺势冻住，而生命也仿佛要离体而去",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//4
([      "action" : "$N一招「七绝崭魂」，手中的$w划出一道轻妙的圆弧，淡淡的剑光封住了$n的头脸，切断了$n的呼吸",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//5
([      "action" : "$N手中$w自左而右地划了一个大弧，平平刺向$n的$l，正是「七绝鸿飞」",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//6
([      "action" : "$N一式「七绝神屠」，手中$w急转，化为一道道血光，虚幻不定地出现在$n周围",
        "dodge" : -50,
        "parry" : -50,
        "damage" : 100,
        "damage_type" : "刺伤",
]),
//7
([      "action" : "$N手中$w一抖，忽地散出十余道七色霞光，罩住了$n全身，正是一招「七绝魔解」",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//8
([      "action" : HIW"$N飘然而进，手中$w"HIW"微微震颤，刹那间连出九剑，分刺$n全身九个部位，正是「"HIC"凤舞九天"HIW"」"NOR,
        "dodge" : -80,
        "parry" : -80,
        "damage" : 200,
        "force" : 120,
        "damage_type" : "刺伤",
]),
});


int valid_enable(string usage) 
	{ 
		return (usage == "sword") || (usage == "parry"); 
	}

int valid_learn(object me)
{
        if (me->query("chushi/chushi_xueshan") != "yes" )
                return notify_fail("你没有领悟「凤凰七绝」的窍门。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「凤凰七绝」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query_temp("pfm-qijue");
	if( !me->query_temp("pfm-qijue") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        if (me->query("chushi/chushi_xueshan") != "yes" )
                return notify_fail("你没有领悟「凤凰七绝」的窍门。\n");
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「凤凰七绝」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「凤凰七绝」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("chushi") + "/qijue-jian/" + func;
}
