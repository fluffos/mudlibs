// liudu-whip.c
// 留度鞭法

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action":               "$N端坐不动，一招「秋风拂叶」，手中$w带着一股劲风，击向$n的脸颊",
        "dodge":                -10,
        "damage":               20,
        "lvl" : 20,
        "skill_name" :          "秋风拂叶",
        "damage_type":          "擦伤"
]),
([      "action":               "$N单臂一挥，一招「玉带围腰」，手中$w直绕向$n的身后",
        "dodge":                -10,
        "damage":               30,
        "lvl" :                 20,
        "skill_name" :         "玉带围腰",
        "damage_type":          "内伤"
]),
([      "action":               "$N身形一转，一招「流云断川」，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
        "dodge":                -20,
        "damage":               35,
        "lvl" :                 40,
        "skill_name" :          "流云断川",
        "damage_type":          "劈伤"
]),
([      "action":               "$N力贯尘梢，一招「春风化雨」，手中$w舞出满天幻影，排山倒海般扫向$n全身",
        "dodge":                -40,
        "damage":               50,
        "lvl" :                 50,
        "skill_name" :          "春风化雨",
        "damage_type":          "刺伤"
]),
([      "action":               "$N忽的向前一跃，一招「野马分鬃」，手中$w分击$n左右",
        "dodge":                -50,
        "damage":               60,
        "lvl" :                 60,
        "skill_name" :         "野马分鬃",
        "damage_type":         "刺伤"
]),
([      "action":               "$N慢步上前，一招「竹影扫阶」，手中$w缓缓罩向$n前胸",
        "dodge":                -60,
        "damage":               70,
        "lvl" :                 70,
        "skill_name" :          "竹影扫阶",
        "damage_type":          "内伤"
])
});
int valid_enable(string usage) {
    return usage == "whip" || usage == "parry";
}

int valid_learn(object me) {

 if ((int)me->query_skill("molian-spells",1) < 40 )
        return notify_fail("你的魔莲法修为尚浅，没法学留度鞭！\n");
   
    return 1;
}
string query_skill_name(int level) {
    int i;
    for (i=sizeof(action)-1; i>=0; i--)
        if (level >= action[i]["lvl"])
            return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
/*
 int i;
 i=me->query_action("JQB_perform");
if( ! me->query_temp("JQB_perform"))
 {
 return action[random(10)];
}
 else
 {

 return action_kuang[random(sizeof(action_kuang))];
}
*/
 return action[random(sizeof(action))];
}

int practice_skill(object me) {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string)(weapon->query("skill_type")) != "whip")
        return notify_fail("你这才想起手里没鞭子，怎么练留度鞭啊？ :)\n");
    if ((int)(me->query("kee")) < 50)
        return notify_fail("你已经精疲力竭，没法儿练下去啦！\n");
    me->receive_damage("kee", 30);
    return 1;
}
string perform_action_file(string func)
{
        return CLASS_D("mojie") + "/liudu-whip/"+func;
}



