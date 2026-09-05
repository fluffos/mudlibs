// huashan-sword.c
// Modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":"$N一招「白云出岫」，剑势灵动轻盈，手中$w点向$n的$l",
        "force" : 150,
        "dodge" : 5,
        "parry" : 5,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "白云出岫",
        "damage_type":  "刺伤"
]),
([      "action":"$N使出「有凤来仪」，剑势飞舞而出，内藏五个后着，划向$n的$l",
        "force" : 180,
        "dodge" : 5,
        "parry" : 5,
        "damage": 25,
        "lvl" : 9,
        "skill_name" : "有凤来仪",
        "damage_type":  "割伤"
]),
([      "action":"$N吐气开声一招「天绅倒悬」，$w自上而下划出一个大弧，向$n劈砍下去",
        "force" : 220,
        "dodge" : 8,
        "parry" : 8,
        "damage": 30,
        "lvl" : 18,
        "skill_name" : "天绅倒悬",
        "damage_type":  "割伤"
]),
([      "action":"$N向前跨上一步，运足内劲，手中$w使出「白虹贯日」，急劲无踌地直刺$n",
        "force" : 250,
        "dodge" : 10,
        "parry" : 10,
        "damage": 35,
        "lvl" : 25,
        "skill_name" : "白虹贯日",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中的$w自左而右地一晃，使出「苍松迎客」带着呼呼风声直削$n的$l",
        "force" : 280,
        "dodge" : 15,
        "parry" : 15,
        "damage": 40,
        "lvl" : 32,
        "skill_name" : "苍松迎客",
        "damage_type":  "割伤"
]),
([      "action":"$N飞身跃起，一式「金雁横空」，卷起漫天剑影，$w向$n电射而去",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 45,
        "lvl" : 40,
        "skill_name" : "金雁横空",
        "damage_type":  "刺伤"
]),
([      "action":"$N凝气守中，$w逼出雪亮剑芒，挥出「无边落木」，一剑快似一剑底地攻向$n",
        "force" : 350,
        "dodge" : 10,
        "parry" : 10,
        "damage": 55,
        "lvl" : 48,
        "skill_name" : "无边落木",
        "damage_type":  "刺伤"
]),
([      "action":"$N驱剑中宫直进，剑尖颤动，中途忽然转而向上，「青山隐隐」端的是变幻无方",
        "force" : 390,
        "dodge" : 5,
        "parry" : 5,
        "damage": 65,
        "lvl" : 55,
        "skill_name" : "青山隐隐",
        "damage_type":  "刺伤"
]),
([      "action":"$N侧身斜刺一剑，一招「古柏森森」卷带着森然剑气，将$n包围紧裹",
        "force" : 410,
        "dodge" : 8,
        "parry" : 8,
        "damage": 75,
        "lvl" : 62,
        "skill_name" : "古柏森森",
        "damage_type":  "割伤"
]),
([      "action":"$N双手握起$w，剑芒暴长，一式「无双无对」，驭剑猛烈绝伦地往$n冲刺",
        "force" : 450,
        "dodge" : 10,
        "parry" : 10,
        "damage": 85,
        "lvl" : 70,
        "skill_name" : "无双无对",
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
    object ob;
//   if( (string)me->query("gender") != "女性" )
//   return notify_fail("九阴赤炼剑法是只有女子才能练的武功。\n");
    if( (int)me->query("max_neili") < 50 )
        return notify_fail("你的内力不够，没有办法练华山剑法。\n");
   if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
        return notify_fail("华山剑法必须配合紫霞神功才能练。\n");
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
        return notify_fail("你的内力或气不够，没有办法练习华山剑法。\n")
;
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    write("你按著所学练了一遍华山剑法。\n");
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
        return __DIR__"huashan-sword/" + action;
}
