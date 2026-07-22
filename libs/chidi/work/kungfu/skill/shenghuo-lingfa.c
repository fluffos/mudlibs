#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N将手中$w横挥，一式「横扫千军」，$w带出一股风声，疾驶向$n的咽喉",
        "skill_name" : "横扫千军",
        "force" : 150,
        "dodge" : 20,
        "parry" : 20,
        "lvl" : 30,
        "damage" : 100,
        "damage_type" : "内伤",
]),
([      "action" : "$N双手持$w举过头顶，猛然挥出「天降神兵」\n只见一股强劲的气浪随$w自空而降，袭向$n",
        "skill_name" : "天降神兵",
        "force" : 180,
        "dodge" : 30,
        "parry" : 30,
        "lvl" : 60,
        "damage" : 150,
        "damage_type" : "内伤",
]),
([      "action" : "$N手撙$w，运起真气，脚下走出怪异步法\n顿时好似有无数个$N将那无数的$w斩向$n的头颅，这着唤做「天阵伏魔」",
        "skill_name" : "天阵伏魔",
        "force" : 220,
        "dodge" : 50,
        "parry" : 30,
        "lvl" : 100,
        "damage" : 200,
        "damage_type" : "劈伤",
]),
/*
([      "action" : HIR"只见$N挥力太猛，$w当空坠落，$N急忙俯身去接\n$n看到如此大好时机，岂肯放过，一步抢入准备施展手段\n$n怎知这正中了圣火令法的绝招「偃旗息鼓」，只见$N突然一个鹞子翻身，$n只感到胸口冰凉，看时已是$w插入了心脏处！"NOR,
        "skill_name" : "偃旗息鼓",
        "force" : 300,
        "dodge" : 100,
        "parry" : 100,
        "lvl" : 120,
        "damage" : 500,
        "damage_type" : "刺伤",
]),
*/
});


int valid_enable(string usage) { return usage == "lingfa"; }

//int valid_combine(string combo) { return combo=="mingwang-jian"; }

int valid_learn(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type") != "lingfa")
                return notify_fail("你必须使用圣火令才可能练就圣火令法。\n");
        if ((int)me->query_skill("lingfa", 1) < 30)
                return notify_fail("你的基本令法太差了，练不了圣火令法。\n");
        if ((int)me->query_skill("shenghuo-xinfa", 1) < 30)
                return notify_fail("你对圣火心法的领悟不够，无法学圣火令法。\n");
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
        if (random(me->query_skill("lingfa")) > 120 &&
            me->query_skill("force") > 120 &&
            me->query("neili") > 1000 &&
            (string)weapon->query("id") == "shenghuo-ling" ) {
                me->add("neili", -200);
                return ([
          "action" : "只见$N挥力太猛，$w当空坠落，$N急忙俯身去接\n$n看到如此大好时机，岂肯放过，一步抢入准备施展手段\n$n怎知这正中了圣火令法的绝招「偃旗息鼓」\n只见$N突然一个鹞子翻身，$w由下而上急速向$n刺去！",
        "skill_name" : "偃旗息鼓",
//        "force" : 300,
//        "dodge" : 100,
//        "parry" : 100,
//       "lvl" : 120,
        "damage" : 500,
        "damage_type" : "刺伤",
                       ]);
        }
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够，练不了圣火令法。\n");
        if ((int)me->query("neili") < 600)
                return notify_fail("你的内力不够练圣火令法。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenghuo-lingfa/" + action;
}
