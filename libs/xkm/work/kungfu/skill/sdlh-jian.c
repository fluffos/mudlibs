//不要cut
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : BLU"$N使出三道轮回剑之「一道定前世」"NOR,
        "force" : 200,
        "dodge" : 30,
        "damage" : 200,
        "lvl"    : 0,
        "damage_type" : "刺伤"
]),
([      "action" : BLU"$N使出三道轮回剑之「一道定今生」"NOR,
        "force" : 400,
        "dodge" : 20,
        "damage" : 400,
         "damage_type" : "刺伤"
]),
([      "action" : BLU"$N使出三道轮回剑之「一道定来世」"NOR,
        "force" : 500,
        "dodge" : 10,
        "damage" : 500,
         "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力太弱，无法练「无影剑法」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("sdlh-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/4)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练「无影剑法」。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练「无影剑法」。\n");
        me->receive_damage("qi", 40);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"sdlh-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if ((int)me->query_skill("sdlh-jian", 1) > 201)

        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return HIB "你听到一阵清风吹过，好象千万鬼魂缠绕着$n，$n差点七魂出壳！！！\n"NOR;
        }
}
