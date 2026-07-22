// riyue-bian.c 日月鞭法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([     "action":               "$N端坐不动，一招「观音降旨」，手中$w抖得笔直，对准$n的胸腹要害连刺数鞭",
       "dodge":                -10,
       "parry":                5,
       "damage":               100,
       "force":                100,
       "lvl" : 0,
       "skill_name" : "观音降旨",
       "damage_type":  "刺伤"
]),
([     "action":               "$N身形一转，一招「花前月下」，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
       "dodge":                -10,
       "parry":                0,
       "damage":               120,
       "force":                150,
       "lvl" : 60,
       "skill_name" : "花前月下",
       "damage_type":  "刺伤"
]),
([     "action":               "$N力贯鞭梢，一招「瑶台归去」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
       "dodge":                -20,
       "parry":                -5,
       "damage":               150,
       "force":                200,
       "lvl" : 90,
       "skill_name" : "瑶台归去",
       "damage_type":  "刺伤"
]),
([     "action":               "$N手臂连晃，一招「雪裹琼苞」，手中$w幻化出无数圆圈，重重叠叠地卷向$n",
       "dodge":                -30,
       "parry":                -10,
       "damage":               180,
       "force":                300,
       "lvl" : 90,
       "skill_name" : "破海式",
       "damage_type":  "刺伤"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
       object weapon;

       if( (int)me->query("max_neili") < 500 )
               return notify_fail("你的内力不足，没有办法练飘渺鞭法, 多练些内力再来吧。\n");

       if ((int)me->query_skill("yijin-jing", 1) < 100)
               return notify_fail("你的易筋经内功火候太浅。\n");

       if ( !objectp(weapon = me->query_temp("weapon"))
       || ( string)weapon->query("skill_type") != "whip" )
               return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

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
       level   = (int) me->query_skill("piaomiao-bianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "whip")
               return notify_fail("你使用的武器不对。\n");
       if ((int)me->query_skill("yijin-jing", 1) < 100)
               return notify_fail("你的易筋经内功火候太浅。\n");
       if ((int)me->query("jingli") < 50)
               return notify_fail("你的体力不够练飘渺鞭法。\n");
       me->receive_damage("jingli", 15);
       return 1;
}
/*
string perform_action_file(string action)
{
               return __DIR__"riyue-bian/" + action;
} 
*/