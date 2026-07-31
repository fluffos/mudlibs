// taishan-jianfa.c
// Modified by XiaoYao

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "name":    "岱宗如何",
        "action":  "$N右手$w斜指而下，左手五指正在屈指而数，从一数到五，握而成拳，又
将拇指伸出，次而食指，终至五指全展，跟着又屈拇指而屈食指，再屈中
指，然后手中$w剑光暴长，向$n的$l刺去",
        "dodge":    50,
        "damage":  190,
        "damage_type":  "刺伤"
]),
([      "name":    "朗月无云",
        "action":  "$N手中$w一晃，向右滑出三步，一招「朗月无云」，转过身来，身
子微矮，$w向$n斜斜刺去",
        "dodge":   -70,
        "damage":  160,
        "damage_type":  "刺伤"
]),
([      "name":    "峻岭横空",
        "action":  "$N手中$w圈转，一招「峻岭横空」去势奇疾，无数剑光刺向$n的$l",
        "dodge":   -40,
        "damage":   90,
        "damage_type":  "刺伤"
]),
([      "name":    "泰山十八盘",
        "action":  "$N展开剑势，身随剑走，左边一拐，右边一弯，越转越急。猛地
$w剑光暴长，一招「泰山十八盘」往$n$l刺去",
        "dodge":   -40,
        "damage":  210,
        "damage_type":  "刺伤"
]),
([      "name":    "五大夫剑",
        "action":  "$N手中$w倏地刺出，一连五剑，每一剑的剑招皆苍然有古意。招数
古朴，内藏奇变，正是「五大夫剑」",
        "dodge":   60,
        "damage":  280,
        "damage_type":  "刺伤"
]),
([      "name":    "来鹤清泉",
        "action":  "$N手中$w方位陡变，一招「来鹤清泉」巧妙的拆解了$n的招数。",
        "dodge":   90,
        "damage":  120,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
    object ob;
    
    if( (int)me->query("max_neili") < 50 )
        return notify_fail("你的内力不够，没有办法练泰山剑法。\n");

    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对。\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 30
    ||      (int)me->query("neili") < 5 )
        return notify_fail("你的内力或气不够，没有办法练习泰山剑法。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    write("你按著所学练了一遍泰山剑法。\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
        return __DIR__"taishan-jianfa/" + action;
}
