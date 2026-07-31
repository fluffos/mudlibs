//Cracked by Kafei
//shenghuo-quan.c 圣火拳

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      
"action" : "$N使一招「凤凰长吟」，双手上下翻飞，击向$n的$l",        
"force" : 80,        
"dodge" : 30,        
"skill_name" : "凤凰长吟",        
"damage_type" : "瘀伤"
]),
([      
"action" : "$N左手护住胸前，右手使一招「困虎云啸」，向$n的$l插去",        
"force" : 150,        
"dodge" : 25,        
"skill_name" : "困虎云啸",        
"damage_type" : "瘀伤"
]),
([      
"action" : "$N默运内力，全身骨骼暴响，一招「卧龙天翔」打向$n的$l",        
"force" : 200,        
"dodge" : 20,        
"skill_name" : "卧龙天翔",        
"damage_type" : "瘀伤"
]),
([      
"action" : "$N左右手同时使出「卧龙天翔」,发出一道真气击向$n的$l",        
"force" : 300,        
"dodge" : 5,        
"skill_name" : "双飞龙",        
"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="riyue-shenzhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练圣火拳必须空手。\n");
	if ((int)me->query_skill("shenghuo-xuanming", 1) < 25)
		return notify_fail("你的圣火玄冥功火候不够，无法练圣火拳。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练仁セ鹑);
        return 1;
}


int practice_skill(object me)
{

        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("你的内力不够练圣火拳。\n");

        if (me->query_skill("shenghuo-quan", 1) < 50)
                me->receive_damage("jingli", 20, "精力透支过度死了。");
        else
                me->receive_damage("jingli", 25, "精力透支过度死了。");
        me->add("neili", -5);
        return 1;
}

mapping query_action(object me, object weapon) 
{
        return action[random(sizeof(action))];
}

