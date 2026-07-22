// murong-daofa.c 慕容刀法
// by Lonely

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N突然大喝一声「看招」，一招「"HIC"劈天盖地满壮志"NOR"」，刀锋自上而下向$n的$l挥去",
        "$N移形换步一招「"HIR"弯刀逆转倒乾坤"NOR"」，手中$w在空中急速转动数圈，划向$n的$l",
        "$N猛一挫身，一招「"HIW"遥看万疆千里雪"NOR"」,$w从不可思仪的方向冲$n的颈中斩去",
        "$N身法轻盈无比，一招「"HIY"壮志豪气满江湖"NOR"」，无数刀尖化作点点繁星，向$n的$l挑去",
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }


int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 10)
                return notify_fail("你的神元功火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 90 + random(20),
                "attack": 40 + random(10),
                "dodge" : 40 + random(10),
                "parry" : 40 + random(10),
                "damage_type" : random(2)?"挫伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力不够练慕容刀法。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够。\n");
        me->add("neili", -10);        
        me->receive_damage("qi", 20);
        return 1;
}
           
string perform_action_file(string action)
{
        return __DIR__"murong-daofa/" + action;
}

