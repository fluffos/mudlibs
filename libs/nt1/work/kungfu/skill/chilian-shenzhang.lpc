#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N双手一翻，两掌带着淡淡的蓝光，直向$n拍去",
        "$N左掌虚晃，右掌直出，犹如毒蛇一般直迫$n的胸前",
        "$N双掌翻飞，四周迷茫着一股暗淡的雾气，排向$n的全身",
        "$N两掌一分，左掌如蝎，右掌似蛇，同时向$n击过去",
        "$N默运内力，双掌忽然变黑，带着一股阴风只扑$n的全身",
});

int valid_enable(string usage)
{
        return usage == "parry" || usage == "strike";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练赤练神掌必须空手。\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("你的内功火候不够，无法练赤练神掌。\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力太弱，无法练赤练神掌。\n");

        if ((int)me->query_skill("strike", 1) < 80)
                return notify_fail("你的基本掌法火候不够，无法练赤练神掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("chilian-shenzhang", 1))
                return notify_fail("你的基本掌法水平有限，无法领会更高深的赤练神掌。\n");

        return 1;
}

mapping query_action(object me)
{
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(60), 
                "attack": 60 + random(10), 
                "dodge" : 60 + random(10), 
                "parry" : 60 + random(10), 
                "damage_type" : random(2) ? "瘀伤" : "内伤", 
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练赤练神掌。\n");

        me->receive_damage("qi", 61);
        me->add("neili", -53);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"chilian-shenzhang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("chilian-shenzhang", 1);
        flvl = me->query("jiali");
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
            victim->affect_by("poison",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "name"  : "赤练神掌毒",
                                 "duration" : lvl / 100 + random(lvl / 10) ])))
        {
                return HIW "$n" HIW "猛然觉得一阵寒气袭来，身子一晃，头脑微微有些发昏。\n" NOR;
        }
}
