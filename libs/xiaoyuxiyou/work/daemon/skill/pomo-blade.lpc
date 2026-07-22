// Pomo-blade.c 破魔刀
// Cracked by 凌惊雪 4-22-2003

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N握紧手中$w一招「破阵一刀」点向$n的$l",
        "force" : 25,
        "dodge" : -20,
        "parry" : -20,
        "damage" : 25,
        "skill_name" : "破阵一刀", 
        "damage_type" : "割伤"
]),
([      "action" : "$N向前跨上一步，手中$w使出「破魔一刀」砍向$n的喉部",
        "force" : 25,
        "dodge" : -20,
        "parry" : -20,
        "damage" : 30,
        "skill_name" : "破魔一刀",
        "damage_type" : "割伤"
]),
([      "action" : "只见$N抡起手中的$w，使出「破妖一刀」万点金光直劈$n",
        "force" : 25,
        "dodge" : -20,
        "parry" : -20,
        "damage" : 45,
        "skill_name" : "破妖一刀",
        "damage_type" : "劈伤"
]),
([      "action" : "$N使出「破立一刀」，手中$w如刮起狂风一般闪烁不定，割向$n",
        "force" : 25,
        "dodge" : -20,
        "parry" : -20,
        "damage" : 55,
        "skill_name" : "破立一刀",
        "damage_type" : "割伤"
]),
([      "action" : "$N随手使出刀法之奥义「破旧一刀」，手中$w如鬼魅一般铺天盖地的砍向$n",
        "force" : 25,
        "dodge" : -20,
        "parry" : -20,
        "damage" : 65,
        "skill_name" : "「破旧一刀」",
        "damage_type" : "割伤"
]),
([      "action" : HIY"$N使出破魔刀之最终绝技"+HIC"「破势一刀」"HIY+",手中$w"+HIY"犹如蛟龙一般劈向$n"NOR,
        "force" : 130,
        "dodge" : -60,
        "parry" : -60,
        "damage" : 130,
        "skill_name" : "HIY「破势一刀」"NOR,
        "damage_type" : "割伤"
]),
});


int valid_enable(string usage) 
	{ 
		return (usage == "blade") || (usage == "parry"); 
	}

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("你对调理气息的火候不够，无法学「破魔刀」。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「破魔刀」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query("PMD");
	if( !me->query("PMD") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("你的体力不够练「破魔刀」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「破魔刀」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("sanxian") + "/pomo-blade/" + func;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str()/10) {
                victim->receive_wound("kee", damage_bonus / 10 );
                switch(random(2)) {
                        case 0: return HIC "$n骇然发现自己的心力竟然受到$N破势刀的挫伤！\n" NOR;
                        case 1: return HIR "只见$n一个不留神，被$N的刀砍的血肉横飞！\n" NOR;
                }
        }
}

