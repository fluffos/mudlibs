// yunlong-bian.c 云龙鞭法
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([  "action":       "$N单手一扬，一招「"+YEL+"开天辟地"+NOR+"」，手中$w抖得笔直，对准$n当头罩下",
    "force":        100,
    "lvl" : 0,
    "skill_name" : YEL "开天辟地" NOR,
    "damage_type":  "劈伤"
]),
([  "action":       "$N身形一转，一招「"+RED+"龙腾四海"+NOR+"」，手中$w如矫龙般腾空一卷，猛地击向$n太阳穴",
    "force":        150,
    "lvl" : 10,
    "skill_name" : RED "龙腾四海" NOR,
    "damage_type":  "劈伤"
]),
([  "action":       "$N唰的一抖长鞭，一招「"+YEL+"矫龙出水"+NOR+"」，手中$w抖得笔直，刺向$n双眼",
    "force":        200,
    "lvl" : 20,
    "skill_name" : YEL "矫龙出水" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N力贯鞭梢，一招「"+BLU+"破云见日"+NOR+"」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
    "force":        200,
    "lvl" : 30,
    "skill_name" : BLU "破云见日" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N运气于腕，一招「"+MAG+"开山裂石"+NOR+"」，手中$w象一根铜棍般直击向$n",
    "force":        250,
    "lvl" : 40,
    "skill_name" : MAG "开山裂石" NOR,
    "damage_type":  "内伤"
]),
([  "action":       "$N单臂一挥，一招「"+HIC+"玉带围腰"+NOR+"」，手中$w直击向$n腰肋",
    "force":        300,
    "lvl" : 50,
    "skill_name" : HIC "玉带围腰" NOR,
    "damage_type":  "内伤"
]),
([  "action":       "$N高高跃起，一招「"+YEL+"大漠孤烟"+NOR+"」，手中$w笔直向$n当头罩下",
    "force":        350,
    "lvl" : 60,
    "skill_name" : YEL "大漠孤烟" NOR,
    "damage_type":  "内伤"
])
});
int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    object weapon;
    if( (int)me->query("max_neili") < 200 )
        return notify_fail("你的内力不足，没有办法练云龙鞭法, 多练些内力再来吧。\n");
    if ((int)me->query_skill("force", 1) < 40)
        return notify_fail("你的基本内功火候太浅。\n");
    if ( !objectp(weapon = me->query_temp("weapon"))
    || ( string)weapon->query("skill_type") != "whip" )
    if ( !objectp(weapon = me->query_temp("secondary_weapon"))
    || ( string)weapon->query("skill_type") != "whip" )
        return notify_fail("你必须先找一条鞭子才能练鞭法。\n");
    if (me->query_skill("whip", 1) <=me->query_skill("yunlong-bian", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
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
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("yunlong-bian",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level/2;
    return a_action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "whip")
    if ( !objectp(weapon = me->query_temp("secondary_weapon"))
    || ( string)weapon->query("skill_type") != "whip" )
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练云龙鞭法。\n");
    me->receive_damage("qi", 5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yunlong-bian/" + action;
}
