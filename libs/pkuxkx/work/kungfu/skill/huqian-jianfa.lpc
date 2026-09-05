// huqian-jianfa 虎钤剑法
#include <ansi.h>
inherit SKILL;

mapping *action = ({
    ([      "action" : "$N握紧手中$w，不带任何花哨，缓缓刺向$n的$l",
     "force" : 50,
     "dodge" : 40,
     "damage" : 20,
     "lvl"    : 0,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "$N因势利导，一剑紧跟一剑，直向$n逼去",
     "force" : 70,
     "dodge" : 10,
     "damage" : 30,
     "lvl"    : 20,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "$N向前跨上一步，手中$w直刺$n的喉部",
     "force" : 90,
     "dodge" : 80,
     "damage" : 60,
     "lvl"    : 40,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "$N剑化刀诀，大开大阖，直劈向$n",
     "force" : 90,
     "dodge" : 80,
     "damage" : 80,
     "lvl"    : 60,
     "damage_type" : "劈伤"
     ]),
    ([      "action" : "只见$N抡起手中的$w，不管不顾地劈向$n",
     "force" : 90,
     "dodge" : 70,
     "damage" : 100,
     "lvl"    : 80,
     "damage_type" : "劈伤"
     ]),
    ([      "action" : "$N舞起手中的$w，连续几剑刺向$n",
     "force" : 120,
     "dodge" : 60,
     "damage" : 140,
     "lvl"    : 100,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "$N简单一个转身，反身刺向$n",
     "force" : 200,
     "dodge" : 100,
     "damage" : 130,
     "lvl"    : 120,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : "$N东一剑，西一剑，却吸引了$n的注意力，破中宫刺向$n",
     "force" : 200,
     "dodge" : 200,
     "damage" : 150,
     "lvl"    : 140,
     "damage_type" : "刺伤"
     ]),
    ([      "action" : HIR"$N将剑插回剑鞘，化人成剑，刺向$n"NOR,
     "force" : 300,
     "dodge" : 400,
     "damage" : 200,
     "lvl"    : 160,
     "damage_type" : "刺伤"
     ]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_combine(string combo) { return combo=="pojun-daofa"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("bixue-xinfa", 1) < 150)
        return notify_fail("学习虎钤剑法需要碧血心法 150 级。\n");
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
    level   = (int) me->query_skill("huqian-jianfa",1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];

}
int practice_skill(object me)
{
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练「虎钤剑法」。\n");
    if ((int)me->query("neili") < 50)
        return notify_fail("你的内力不够练「虎钤剑法」。\n");
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
        return HIR "你听到「唰」一声轻响好像凉一阵风吹过，忽然间$n"HIR"身上冒出几道伤口，已被$N"HIR"剑气所伤！\n" NOR;
    }
}


