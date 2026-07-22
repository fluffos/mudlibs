//lingshe_zhangfa.c 灵蛇杖法
#include "ansi.h"
inherit SKILL;
mapping *action = ({
([  "action": "$N使出一招「"+RED+"灵蛇出洞"+NOR+"」，手中$w大开大阖扫向$n的$l",
    "force" : 100,
    "lvl" : 0,
    "skill_name" : RED "灵蛇出洞" NOR,
    "damage_type": "挫伤"
]),
([  "action": "$N手中$w阵阵风响，一招「"+MAG+"摇头摆尾"+NOR+"」向$n的$l攻去",
    "force" : 140,
    "lvl" : 20,
    "skill_name" : MAG "摇头摆尾" NOR,
    "damage_type": "挫伤"
]),
([  "action": "$N举起$w，居高临下使一招「"+HIW+"灵蛇下"+BLU+"涧"+NOR+"」砸向$n的$l",
    "force" : 180,
    "lvl" : 30,
    "skill_name" : HIW "灵蛇下涧" NOR,
    "damage_type": "挫伤"
]),
([  "action": "$N一招「"+YEL+"灵蛇挺身"+NOR+"」，手中$w猛烈扫向$n的$l",
    "force" : 220,
    "lvl" : 40,
    "skill_name" : YEL "灵蛇挺身" NOR,
    "damage_type": "挫伤"
]),
([  "action": "$N使出一招「"+YEL+"蛇游蟒走"+NOR+"」，$w左右迂回向$n的$l扫去",
    "force" : 260,
    "lvl" : 50,
    "skill_name" : YEL "蛇游蟒走" NOR,
    "damage_type": "挫伤"
]),
([  "action": "$N手中$w一挥，使出一招「"+BLU+"蛇缠左右"+NOR+"」，忽左忽右扫向$n的$l",
    "force" : 300,
    "lvl" : 60,
    "skill_name" : BLU "蛇缠左右" NOR,
    "damage_type": "挫伤"
]),
([  "action": "$N使出一招「"+RED+"巨蟒下"+YEL+"山"+NOR+"」，高举手中$w，劈头砸向$n的$l",
    "force" : 340,
    "lvl" : 80,
    "skill_name" : RED "巨蟒下山" NOR,
    "damage_type": "挫伤"
]),
([  "action": "$N使出一招「"+RED+"灵蛇出"+BLK+"洞"+NOR+"」，手中$w猛一探，直扫$n的$l",
    "force" : 380,
    "lvl" : 100,
    "skill_name" : RED "灵蛇出洞" NOR,
    "damage_type": "挫伤"
]),
});
int practice_level(){   return 100;  }
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("lingshe-zhangfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/2;
    return a_action;

}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 70)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("staff", 1) <=me->query_skill("lingshe-zhangfa", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练灵蛇杖法。\n");
    me->receive_damage("qi", 20);
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("hamagong")) > 10 ) 
    {
    victim->apply_condition("snake_poison", random(me->query_skill("hamagong")/10) + 1 +
    victim->query_condition("snake_poison"));
        tell_object(victim, HIG "你觉得被击中的地方一阵麻木！\n" NOR );
        tell_object(victim, HIG "原来是被杖头窜出的毒蛇咬了一口！\n" NOR );
    }
}
