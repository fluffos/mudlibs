//kuangfeng-jian 狂风快剑
// Made by deaner
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N纵身跃起手中$w轻挥，斩向$n后颈",
    "damage" : 150,
    "dodge"  : 20,
    "lvl"   : 0,
    "skill_name" : "风平浪静",
    "damage_type" : "割伤"
]),
([  "action" : "$N手中$w连话三个弧形，向$n的右臂齐肩斩落",
    "damage" : 170,
    "dodge" : 35,
    "force" : 20,
    "lvl"   : 20,
    "skill_name" : "风起云涌",
    "damage_type" : "割伤"
]),
([  "action" : "$N轻吁一声，刷刷刷刷四剑，向$n胸，腹，腰，肩四处连刺",
    "damage" : 190,
    "dodge" : 55,
    "force" : 25,
    "lvl"   : 40,
    "skill_name" : "风卷残云",
    "damage_type" : "割伤"
]),
([  "action" : "$N仰天一声清啸，斜行向前，$w横削直击，迅捷无比，击向$n的$l",
    "damage" : 210,
    "dodge" : 65,
    "force" : 35,
    "lvl"   : 60,
    "skill_name" : "风流云散",
    "damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; } 

int valid_learn(object me)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
    if(!myfam || myfam["master_id"] != "feng buping")
        return notify_fail("你无法向此人学习狂风快剑。\n");
    if ((int)me->query("max_neili") < 300)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("force", 1) < 60)
        return notify_fail("你的内功心法火候太浅。\n");
    if ((int)me->query_skill("dodge", 1) < 60)
        return notify_fail("你的轻功火候太浅。\n");
    if ((int)me->query_dex() < 25)
        return notify_fail("你的身法还不够灵活。\n");
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
    level   = (int) me->query_skill("kuang-jian",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力不够练狂风快剑。\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"kuang-jian/" + action;
}
