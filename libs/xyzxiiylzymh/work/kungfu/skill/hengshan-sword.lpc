// hengshan-sword.c
// Modified by Java Sep.1998
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([
        "action":  "$N右手$w慢慢指出，突然间在空中一颤，发出嗡嗡之声，跟着便是
嗡嗡两剑，手中$w剑光暴长，向$n的$l刺去",
        "dodge":    50,
        "damage":  170,
        "damage_type":  "刺伤"
]),
([
        "action":  "$N手中$w如鬼如魅，竟然已绕到了$n背后，$n急忙转身，耳边只听
得嗡嗡两声",
        "dodge":   -70,
        "damage":  120,
        "damage_type":  "刺伤"
]),
([      "name":    "百变千幻",
        "action":  "$N手中$w寒光陡闪，手中的$w，猛地反刺，直指$n胸口。这一下
出招快极，抑且如梦如幻，正是“百变千幻衡山云雾十三式”中的绝招",
        "dodge":   -40,
        "damage":   90,
        "damage_type":  "刺伤"
]),
([      "name":    "泉鸣芙蓉",
        "action":  "$N不理会对方攻势来路，手中$w刷的一剑「泉鸣芙蓉」，向$n小
腹刺去",
        "dodge":   -40,
        "damage":  140,
        "damage_type":  "刺伤"
]),
([      "name":    "鹤翔紫盖",
        "action":  "$N不理会对方攻势来路，手中$w刷的一剑「鹤翔紫盖」，向$n额
头刺去",
        "dodge":   -40,
        "damage":  140,
        "damage_type":  "刺伤"
]),
([      "name":    "石廪书声",
        "action":  "$N手中$w倏地刺出，剑势穿插迂回，如梦如幻，正是一招「石廪书声」，
向$n$l刺去",
        "dodge":   60,
        "damage":  220,
        "damage_type":  "刺伤"
]),
([      "name":    "天柱云气",
        "action":  "$N手中$w倏地刺出，极尽诡奇之能事，动向无定，不可捉摸。正是
一招「天柱云气」，指向$n$l",
        "dodge":   60,
        "damage":  220,
        "damage_type":  "刺伤"
]),
([      "name":    "雁回祝融",
        "action" : "$N飞身跃起，『雁回祝融』！，$w发出一声龙吟从半空中洒向$n的
$l",
        "dodge":   60,
        "damage":  220,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
    object ob;
//   if( (string)me->query("gender") != "女性" )
//   return notify_fail("九阴赤炼剑法是只有女子才能练的武功。\n");
    if( (int)me->query("max_neili") < 50 )
        return notify_fail("你的内力不够，没有办法练衡山剑法。\n");
//   if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
//        return notify_fail("华山剑法必须配合紫霞神功才能练。\n");
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
        return notify_fail("你的内力或气不够，没有办法练习衡山剑法。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    write("你按著所学练了一遍衡山剑法。\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
        return __DIR__"hengshan-sword/" + action;
}
