//huangsha-wanlibian 黄沙万里鞭法，出自神雕尹克西 By Zine 2010 Dec 9，公共技能

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$N展身虚步，一招「砥柱中流」，手中鞭立刻有形有质，如棍棒一般劈向$n",
        "force" : 140,
        "dodge" : -5,
        "damage" : 15,
         "lvl" : 0,
        "skill_name" : "砥柱中流",
        "damage_type" : "劈伤"
]),
([      "action" : "$N一招「河山带砺」，手中$w方中带圆，柔里藏刚，自上而下划出一个大弧，绕向$n",
        "force" : 160,
        "dodge" : 5,
        "damage" : 25,
        "lvl" : 24,
        "skill_name" : "河山带砺",
        "damage_type" : "缠伤"
]),
([      "action" : "$N手中$w一沉，一招「大漠孤烟直」，鞭影连环，击向$n的胸前要穴",
        "force" : 180,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 33,
        "skill_name" : "大漠孤烟直",
        "damage_type" : "刺伤"
]),
([      "action" : "$N挥舞$w，使出一招「长河落日圆」，$w发出淡淡光辉，一圈一圈，最后齐齐罩向$n",
        "force" : 210,
        "dodge" : 15,
        "damage" : 35,
        "lvl" : 42,
        "skill_name" : "长河落日圆",
        "damage_type" : "缠伤"
]),
([      "action" : "$N一招「峰峦如聚」，左脚跃步落地，$w层层叠叠，密不透风地裹向$n",
        "force" : 240,
        "dodge" : 5,
        "damage" : 50,
        "lvl" : 51,
        "skill_name" : "峰峦如聚",
        "damage_type" : "割伤"
]),
([      "action" : "$N佯退，一招「泾渭分明」，一鞭分二，向$n的左右太阳穴击去",
        "force" : 280,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 60,
        "skill_name" : "泾渭分明",
        "damage_type" : "刺伤"
]),
([      "action" : "$N"+RED"默念心法，运转真气，一招「黄河之水天上来」，$n"+RED+"眼前已全是$w"+RED+"的重影，逼无可避，唯有硬拼"+NOR,
        "force" : 280,
        "dodge" : 20,
        "damage" : 300,
        "lvl" : 500,
        "skill_name" : "黄河之水天上来",
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }


int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
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
        level   = (int) me->query_skill("huangsha-wanlibian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练黄沙万里鞭。\n");
        me->receive_damage("qi", 20);
        return 1;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


string perform_action_file(string action)
{
  return __DIR__"huangsha-wanlibian/" + action;
}

