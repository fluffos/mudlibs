#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w一转，回身一剑，刺向$n$l，正是一招「惊雷」",
        "force"  : 100,
        "dodge"  : 100,
        "parry"  : 100,
        "attack" : 100,
        "damage" : 1250,
        "lvl"    : 0,
        "damage_type" : "异伤",
        "skill_name"  : "惊雷",
]),
([      "action" :  "只见$N身法陡然加快，施展出「狂风」，剑风荡漾，$w瞬间已至$n$l",
        "force"  : 150,
        "dodge"  : 150,
        "parry"  : 150,
        "attack" : 150,
        "damage" : 1250,
        "lvl"    : 25,
        "damage_type" : "异伤",
        "skill_name"  : "狂风",
]),
([      "action" : "$N纵身跃起，使出一招「晴空万里」，陡见$w从半空直指$N$l",
        "force"  : 200,
        "dodge"  : 200,
        "parry"  : 200,
        "attack" : 200,
        "damage" : 1250,
        "lvl"    : 50,
        "damage_type" : "刺伤",
        "skill_name"  : "晴空万里",
]),
([      "action" : "$N腾空而起，一招「暴雨」来势又准又快，手中$w已到$n$l",
        "force"  : 300,
        "dodge"  : 300,
        "parry"  : 300,
        "attack" : 300,
        "damage" : 1250,
        "lvl"    : 75,
        "damage_type" : "异伤",
        "skill_name"  : "暴雨",
]),
([      "action" : "$N剑峰忽转，一剑笔直地向$n$l刺来，内劲十足，正是一招「天晴」",
        "force"  : 400,
        "dodge"  : 400,
        "parry"  : 400,
        "attack" : 400,
        "damage" : 1250,
        "lvl"    : 100,
        "damage_type" : "异伤",
        "skill_name"  : "天晴",
]),
([      "action" : "$N手中$w猛然回撤，紧接着一剑，气势磅礴，剑气纵横，正是「无垠」",
        "force"  : 500,
        "dodge"  : 500,
        "parry"  : 500,
        "attack" : 500,
        "damage" : 1250,
        "lvl"    : 120,
        "damage_type" : "异伤",
        "skill_name"  : "无垠",
]),
});

int valid_learn(object me)
{
        object ob;

        if( !(ob=me->query_temp("weapon") )
            || ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        if( me->query("max_neili")<10000 )
                return notify_fail("你的内力修为不够，无法学习无垠剑经。\n");

        if ((int)me->query_skill("force") < 600)
                return notify_fail("你的内功火候太浅，无法学习无垠剑经。\n");

        if ((int)me->query_skill("sword", 1) < 600)
                return notify_fail("你的基本剑法火候不够，无法学习无垠剑经。\n");

        if (me->query_skill("sword", 1) < me->query_skill("wuyin-jianjing", 1))
                return notify_fail("你的基本剑法火候有限，无法领会更高深的无垠剑经。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int) me->query_skill("wuyin-jianjing", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
       object weapon;

       if( !objectp(weapon=me->query_temp("weapon") )
           || weapon->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对。\n");

       if( me->query("neili")<1000 )
                   return notify_fail("你的内力不足，没有办法练习无垠剑经。\n");

       if( me->query("qi")<50 )
                   return notify_fail("你的体力不够练无垠剑经。\n");

       me->receive_damage("qi", 50);
       me->add("neili", -1000);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuyin-jianjing/" + action;
}
