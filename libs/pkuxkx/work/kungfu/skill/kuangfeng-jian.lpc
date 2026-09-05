// kuangfeng-jianfa 狂风剑法
#include <ansi.h>
inherit SKILL;

mapping *action = ({
    ([      "action" : "$N握紧手中$w一招[37m「大风起兮」[0m点向$n的$l",
     "force" : 50,
     "dodge" : 40,
     "damage" : 20,
     "skill_name" : "「大风起兮」",
     "lvl"    : 0,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "$N一招[1;34m「天昏地暗」[0m，无数$w上下刺出，直向$n逼去",
     "force" : 70,
     "dodge" : 10,
     "damage" : 30,
     "skill_name" : "「天昏地暗」",
     "lvl"    : 20,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "$N向前跨上一步，手中$w使出[1;33m「剑气封喉」[0m直刺$n的喉部",
     "force" : 90,
     "dodge" : 80,
     "damage" : 60,
     "skill_name" : "「剑气封喉」",
     "lvl"    : 40,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "$N虚恍一步，使出[36m「虚中有实」[0m手中$w直刺$n的喉部",
     "force" : 90,
     "dodge" : 80,
     "damage" : 80,
     "skill_name" : "「虚中有实」",
     "lvl"    : 60,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "只见$N抡起手中的$w，使出[31m「[1;33m光[1;35m芒[35m万[1;31m丈[31m」[0m万点金光直射$n",
     "force" : 90,
     "dodge" : 70,
     "damage" : 100,
     "skill_name" : "「光芒万丈」",
     "lvl"    : 80,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "$N抡起手中的$w，使出[1;35m「狂风乱剑」[0m无数剑光直射$n",
     "force" : 120,
     "dodge" : 60,
     "damage" : 140,
     "skill_name" : "「狂风乱剑」",
     "lvl"    : 100,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "$N使出[37m「乱舞狂风」[0m，手中$w如刮起狂风一般闪烁不定，刺向$n",
     "force" : 200,
     "dodge" : 100,
     "damage" : 130,
     "skill_name" : "「乱舞狂风」",
     "lvl"    : 120,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "$N使出狂风剑法之绝技[37m「狂风肆虐」[0m，手中$w如刮起狂风一般铺天盖地的刺向$n",
     "force" : 200,
     "dodge" : 200,
     "damage" : 150,
     "lvl"    : 140,
     "skill_name" : "「狂风肆虐」",
     "damage_type" : "刺伤"
     ]),
    ([      "action" : HIY"$N使出狂风剑法之最终绝技「人剑合一」，整个人化作一把金剑飞向$n"NOR,
     "force" : 300,
     "dodge" : 400,
     "damage" : 200,
     "lvl"    : 160,
     "skill_name" : HIY"「人剑合一」"NOR,
     "damage_type" : "刺伤"
     ]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_combine(string combo) { return combo=="kuangfeng-dao"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("bixue-xinfa", 1) < 150)
        return notify_fail("学习狂风剑法需要碧血心法 150 级。\n");
    return 1;
}

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
    level   = (int) me->query_skill("kuangfeng-jian",1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];

}
int practice_skill(object me)
{
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练「狂风剑法」。\n");
    if ((int)me->query("neili") < 50)
        return notify_fail("你的内力不够练「狂风剑法」。\n");
    me->receive_damage("qi", 40);
    me->add("neili",-15);
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( damage_bonus < 100 ) return 0;

    if( F_KUNGFU->hit_rate( me->damage_bonus()/2, victim->query_str()*2, 9, me, victim) )
    {
        F_KUNGFU->hit_wound("qi", damage_bonus / 2, 0, me, victim);
        return HIR "你听到「唰」一声轻响好像凉一阵风吹过，忽然间$n"HIR"血冒三丈，被$N"HIR"剑气所伤！\n" NOR;
    }
}


