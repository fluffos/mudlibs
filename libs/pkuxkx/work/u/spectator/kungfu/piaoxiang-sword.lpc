// piaoxiang-sword.c
// Created by spectator Jan.2003

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":"$N一招「晚妆初了明肌雪」，剑势灵动轻盈，手中$w点向$n的$l",
        "force" : 150,
        "dodge" : 5,
        "parry" : 5,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "晚妆初了",
        "damage_type":  "刺伤"
]),
([      "action":"$N使出「春殿嫔娥鱼贯列」，剑势飞舞而出，内藏五个后着，划向$n的$l",
        "force" : 180,
        "dodge" : 5,
        "parry" : 5,
        "damage": 25,
        "lvl" : 9,
        "skill_name" : "春殿嫔娥",
        "damage_type":  "割伤"
]),
([      "action":"$N吐气开声一招「笙箫吹断水云间」，$w自上而下划出一个大弧，向$n劈砍下去",
        "force" : 220,
        "dodge" : 8,
        "parry" : 8,
        "damage": 30,
        "lvl" : 18,
        "skill_name" : "笙箫吹断",
        "damage_type":  "割伤"
]),
([      "action":"$N向前跨上一步，运足内劲，手中$w使出「重按霓裳歌遍彻」，急劲无踌地直刺$n",
        "force" : 250,
        "dodge" : 10,
        "parry" : 10,
        "damage": 35,
        "lvl" : 25,
        "skill_name" : "重按霓裳",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中的$w自左而右地一晃，使出「临风谁更飘香屑」带着呼呼风声直削$n的$l",
        "force" : 280,
        "dodge" : 15,
        "parry" : 15,
        "damage": 40,
        "lvl" : 32,
        "skill_name" : "临风飘屑",
        "damage_type":  "割伤"
]),
([      "action":"$N飞身跃起，一式「醉拍栏杆情味切」，卷起漫天剑影，$w向$n电射而去",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 45,
        "lvl" : 40,
        "skill_name" : "醉拍栏杆",
        "damage_type":  "刺伤"
]),
([      "action":"$N凝气守中，$w逼出雪亮剑芒，挥出「归时休放烛花红」，一剑快似一剑底地攻向$n",
        "force" : 350,
        "dodge" : 10,
        "parry" : 10,
        "damage": 55,
        "lvl" : 48,
        "skill_name" : "归时烛花",
        "damage_type":  "刺伤"
]),
([      "action":"$N驱剑中宫直进，剑尖颤动，中途忽然转而向上，「待踏马蹄清夜月」端的是变幻无方",
        "force" : 390,
        "dodge" : 5,
        "parry" : 5,
        "damage": 65,
        "lvl" : 55,
        "skill_name" : "待踏马蹄",
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
    object ob;
    ob=this_player();

    if ((int)me->query("max_neili") < 50)
        return notify_fail("你的内力不够，没有办法练华山剑法。\n");

    if (!(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
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
    if ((int)me->query("qi") < 30
        || (int)me->query("neili") < 5)
        return notify_fail("你的内力或气不够，没有办法练习华山剑法。\n");

    me->receive_damage("qi", 30);
    me->add("neili", -5);
    write("你按著所学练了一遍飘香剑法。\n");

    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
    return __DIR__"piaoxiang-sword/" + action;
}

