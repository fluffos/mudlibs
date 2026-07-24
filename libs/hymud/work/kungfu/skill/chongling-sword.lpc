// chongling-sword.c
// Modified by Venus Oct.2000
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "name":    "一见钟情",
        "action":      "$N使一招「一见钟情」，手中$w剑光暴长，向$n的$l刺去",
        "dodge":   50,
        "damage":      170,
        "damage_type":  "刺伤"
]),
([      "name":    "两小无猜",
        "action":      "$N剑随身转，一招「两小无猜」罩向$n的$l",
        "dodge":   -70,
        "damage":      20,
        "damage_type":  "刺伤"
]),
([      "name":    "苍松迎客",
        "action":      "$N舞动$w，一招「苍松迎客」挟著无数剑光刺向$n的$l",
        "dodge":   -40,
        "damage":      90,
        "damage_type":  "刺伤"
]),
([      "name":    "萧史乘龙",
        "action":      "$N手中$w龙吟一声，祭出「萧史乘龙」往$n的$l刺出数剑",
        "dodge":   -40,
        "damage":      40,
        "damage_type":  "刺伤"
]),
([      "name":    "金玉满堂",
        "action":      "$N手中$w剑光暴长，一招「金玉满堂」往$n$l刺去",
        "dodge":   60,
        "damage":      120,
        "damage_type":  "刺伤"
]),
([      "name":    "难舍难分",
        "action":      "$N手中$w化成一道光弧，直指$n$l，一招「难舍难分」发出虎哮龙吟刺去",
        "dodge":   -60,
        "damage":      150,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
    object ob;
//   if( (string)me->query("gender") != "女性" )
//   return notify_fail("九阴赤炼剑法是只有女子才能练的武功。\n");
    if( (int)me->query("max_neili") < 50 )
        return notify_fail("你的内力不够，没有办法练冲灵剑法。\n");
   if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
        return notify_fail("冲灵剑法必须配合紫霞神功才能练。\n");
    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("你必须先找一把剑才能练剑法。\n");

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
        return notify_fail("你的内力或气不够，没有办法练习冲灵剑法。\n")
;
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    //write("你按著所学练了一遍冲灵剑法。\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

/*
void skill_improved(object me)
{
    if( (int)me->query_skill("nine-moon-sword", 1)  % 10 == 0 ) {
   tell_object(me,
      RED "\n你突然觉得一股阴气冲上心头，只觉得想杀人....\n\n"NOR);
   me->add("bellicosity", 2000);
    } else
   me->add("bellicosity", 200);
}
string perform_action_file(string action)
{
    return CLASS_D("ninemoon") + "/ninemoonsword/" + action;
}
*/

string perform_action_file(string action)
{
        return __DIR__"chongling-sword/" + action;
}

