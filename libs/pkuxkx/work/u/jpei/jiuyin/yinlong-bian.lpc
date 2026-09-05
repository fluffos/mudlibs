#include <ansi.h>
inherit SKILL;
mapping *action = ({
([     "action": HIG"$N将$w抖动成圆，一式「圆转如意」，$w已将$n$l缠住"NOR,
       "dodge": 50,
       "damage": 100,
       "force":  300,
       "lvl" : 0,
       "skill_name" : "圆转如意",
       "damage_type":  "拉伤"
]),
([     "action": HIW"$N的$w在$n身旁连连进击，忽然一招「银龙回首」从$n$l处倒卷上来"NOR,
       "dodge": 50,
       "damage": 150,
       "force": 400,
       "lvl" : 60,
       "skill_name" : "银龙回首",
       "damage_type":  "拉伤"
]),
([     "action": HIM"$N运起九阴真气，$w陡然变成笔直，一式「银龙出洞」，向$n直刺过去"NOR,
       "dodge": 50,
       "damage": 180,
       "force": 450,
       "lvl" : 90,
       "skill_name" : "银龙出洞",
       "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
       object weapon;
       if( (int)me->query("max_neili") < 1000 )
               return notify_fail("你的内力修为不足，没有办法练九阴银龙鞭。\n");
        if ((int)me->query_skill("jiuyin-zhengong", 1) <= (int)me->query_skill("yinlong-bian", 1))
               return notify_fail("你的九阴真功火候太浅。\n");
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

mapping query_action(object me)
{
        int i, level;
        level   = (int) me->query_skill("yinlong-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 100)
                return notify_fail("你的体力不够练九阴银龙鞭。\n");
       if ((int)me->query("neili") < 100 )
                return notify_fail("你的内力不够练九阴银龙鞭。\n");
       me->receive_damage("jingli",20);
       me->add("neili",-20);
       return 1;
}

string perform_action_file(string action)
{
               return __DIR__"yinlong-bian/" + action;
}

