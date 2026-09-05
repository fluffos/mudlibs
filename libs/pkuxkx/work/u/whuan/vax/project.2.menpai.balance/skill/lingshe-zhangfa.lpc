//lingshe_zhangfa.c 灵蛇杖法
#include "ansi.h"
inherit SKILL;
mapping *action = ({
([      "action": "$N使出一招「灵蛇出洞」，手中$w大开大阖扫向$n的$l",
        "force" : 200,
        "dodge": -3,
        "damage": 110,
        "lvl" : 10,
        "skill_name" : "灵蛇出洞",
        "damage_type": "挫伤"
]),
([      "action": "$N手中$w阵阵风响，一招「摇头摆尾」向$n的$l攻去",
        "force" : 240,
        "dodge": -5,
        "damage": 120,
        "lvl" : 20,
        "skill_name" : "摇头摆尾",
        "damage_type": "挫伤"
]),
([      "action": "$N举起$w，居高临下使一招「灵蛇下涧」砸向$n的$l",
        "force" : 280,
        "dodge": -10,
        "damage": 130,
        "lvl" : 30,
        "skill_name" : "灵蛇下涧",
        "damage_type": "挫伤"
]),
([      "action": "$N一招「灵蛇挺身」，手中$w猛烈扫向$n的$l",
        "force" : 240,
        "dodge": -5,
        "damage": 130,
        "lvl" : 40,
        "skill_name" : "灵蛇挺身",
        "damage_type": "挫伤"
]),
([      "action": "$N使出一招「蛇游蟒走」，$w左右迂回向$n的$l扫去",
        "force" : 260,
        "dodge": -3,
        "damage": 140,
        "lvl" : 50,
        "skill_name" : "蛇游蟒走",
        "damage_type": "挫伤"
]),
([      "action": "$N手中$w一挥，使出一招「蛇缠左右」，忽左忽右扫向$n的$l",
        "force" : 300,
        "dodge": -5,
        "damage": 120,
        "lvl" : 60,
        "skill_name" : "蛇缠左右",
        "damage_type": "挫伤"
]),
([      "action": "$N使出一招「巨蟒下山」，高举手中$w，劈头砸向$n的$l",
        "force" : 340,
        "dodge": -10,
        "damage": 140,
        "lvl" : 80,
        "skill_name" : "巨蟒下山",
        "damage_type": "挫伤"
]),
([      "action": "$N使出一招「灵蛇出洞」，手中$w猛一探，直扫$n的$l",
        "force" : 380,
        "dodge": -3,
        "damage": 160,
        "lvl" : 100,
        "skill_name" : "灵蛇出洞",
        "damage_type": "挫伤"
]),
});
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
        level   = (int) me->query_skill("lingshe-zhangfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
//      return action[random(sizeof(action))];
}
int valid_enable(string usage) { return (usage == "staff") || (usage == "parry")
; }
int valid_learn(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query_skill("hamagong", 1) < 20)
                return notify_fail("你的蛤蟆功火候不够，无法练灵蛇杖法。\n");
        if ((int)me->query("max_neili") < 70)
                return notify_fail("你的内力不够。\n");
        return 1;
}
int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练灵蛇杖法。\n");
        me->receive_damage("qi", 20);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object weapon;
	 int poison;
        weapon = me->query_temp("weapon"); 
        if( (random(me->query_skill("poison",1)) > 50 ) && ((string)weapon->query("id") == "she zhang") )
        {
        victim->apply_condition("snake_poison", random(me->query_skill("poison")/20) + 1 +
        victim->query_condition("snake_poison"));
        tell_object(victim, HIG "你觉得被击中的地方一阵麻木！\n" NOR );
        tell_object(victim, HIG "原来是被杖头窜出的毒蛇咬了一口！\n" NOR );
        }
        if( random(me->query_skill("poison",1)) > 80 && (string)weapon->query("id") == "guai shezhang" )
        {
			if (weapon->query("snake") == 1)
			{
				poison = random(me->query_skill("poison",1)/20) + 1 ;
			 victim->apply_condition("bt_poison", poison+ victim->query_condition("bt_poison"));
             tell_object(victim, HIC "只见"+weapon->query("name")+HIC"上突然蹿出一条怪蛇向你一口咬来。\n" NOR );
             tell_object(victim, HIC "结果你躲闪不及被杖头窜出的怪蛇咬了一口！\n" NOR );
			 if (wizardp(me))
				 tell_object(me,"snake poison : " + poison);
			 }
			if (weapon->query("snake") == 2)
					{
				poison = random(me->query_skill("poison",1)/12) + 1 ;
			 victim->apply_condition("bt_poison", poison+ victim->query_condition("bt_poison") );
             tell_object(victim, HIC "只见"+weapon->query("name")+HIC"上突然蹿出两条怪蛇向你咬来。\n" NOR );
             tell_object(victim, HIC "结果你躲闪不及被杖头窜出的怪蛇咬了一口！\n" NOR );
			 if (wizardp(me))
				 tell_object(me,"snake poison: " + poison);
			}
		}
}
string  perform_action_file(string action)
{
        return __DIR__"lingshe-zhangfa/" + action;
}

string query_yinyang()
{
	return "少阴";
}