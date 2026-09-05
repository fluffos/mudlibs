// 赤炼神掌,神雕李莫愁用的
//  zine
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$N轻巧地攻向$n胸前诸处大穴",
        "force" : 200,
        "dodge" : -5,
        "parry" : 10,
        "lvl" : 0,
        "damage_type" : "抓伤"
]),
([      "action" : "$N片刻不停，又拍向$n后心等处",
        "force" : 240,
        "dodge" : 0,
        "parry" : -5,
        "lvl" : 10,
        "damage_type" : "抓伤"
]),
([      "action" : "$N手上如传花蝴蝶，并不停歇，印向$n必救之处",
        "force" : 280,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 20,
        "damage_type" : "震伤"
]),
([      "action" : "$N拳打脚踢，看似毫无章法，其实已将$n逼入绝境",
        "force" : 280,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 20,
        "damage_type" : "震伤"
]),
([      "action" : HIR+"$N"+HIR"双手一合，平平推向$n"+NOR,
        "force" : 560,
        "dodge" : 20,
        "parry" : 100,
        "lvl" : 100,
        "damage_type" : "震伤"
]),
([      "action" : "$N左掌结印，右掌轻轻拍向$n",
        "force" : 380,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 120,
        "damage_type" : "震伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="sanwu-shou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练赤炼神掌必须空手。\n");
        if ((int)me->query_skill("yunu-xinfa", 1) < 50)
                return notify_fail("你的玉女心法火候不够，不能学赤炼神掌。\n");
        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("你的基本内功火候不够，不能学赤炼神掌。\n");
        if ((int)me->query("neili") < 500)
                return notify_fail("你的内力太弱，练不了赤炼神掌。\n");
        me->add("neili",-20);
                return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("chilian-shenzhang",1);
        
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
        
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练赤炼神掌必须空手。\n");
        if ((int)me->query_skill("yunu-xinfa", 1) < 50)
                return notify_fail("你的玉女心法火候不够，不能学赤炼神掌。\n");
        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("你的基本内功火候不够，不能学赤炼神掌。\n");
        if ((int)me->query("neili") < 3000)
                return notify_fail("你的内力太弱，练不了赤炼神掌。\n");
        if ((int)me->query("qi") < 3000)
                return notify_fail("你的体力太弱，练不了赤炼神掌。\n");
        me->receive_damage("qi", 20);
        me->add("neili",-10);
        return 1;
}
 

string perform_action_file(string action)
{
        return __DIR__"chilian-shenzhang/" + action;
}
