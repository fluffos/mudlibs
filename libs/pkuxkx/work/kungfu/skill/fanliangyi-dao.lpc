// fanlianyi-dao.c 反两仪刀
// by binlang
inherit SKILL;
mapping *action = ({
([      "action" : "$N反挥$w一招「混沌一破」，刀锋向$n的$l划去",
        "force" : 220,
        "dodge" : -10,
        "parry" : 5,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "混沌一破",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「太乙生荫」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
        "force" : 240,
        "dodge" : -5,
        "parry" : 5,
        "damage": 30,
        "lvl" : 29,
        "skill_name" : "太乙生荫",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「两仪合德」，手中的$w划弧劈向$n的$l",
        "force" : 260,
        "dodge" : 5,
        "parry" : 5,
        "damage": 60,
        "lvl" : 49,
        "skill_name" : "两仪合德",
        "damage_type" : "割伤"
]),
([      "action" : "$N右手反执刀柄，挥出一片流光般的刀影一招「日月晦明」向$n的全身涌去",
        "force" : 280,
        "dodge" : 5,
        "parry" : 5,
        "damage": 80,
        "lvl" : 69,
        "skill_name" : "日月晦明",
        "damage_type" : "割伤",
]),
([      "action" : "$N一招「无色无相」，左脚跃步落地，$w反式而来，挟风声劈向$n的
$l",
        "force" : 330,
        "dodge" : -5,
        "parry" : 5,
        "damage": 100,
        "lvl" : 89,
        "skill_name" : "无色无相",
        "damage_type" : "割伤"
]),
([      "action" : "$N双手合执$w，一招「万劫不复」，双手持刃拦腰反切，砍向$n的胸口",
        "force" : 400,
        "dodge" : 5,
        "parry" : 15,
        "damage": 120,
        "lvl" : 129,
        "skill_name" : "万劫不复",
        "damage_type" : "割伤"
]),
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
// int valid_combine(string combo) { return combo=="huashan-jianfa"; }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
  if ((int)me->query_skill("huashan-neigong", 1) < 20 && (int)me->query_skill("zixia-shengong", 1)< 20)
                return notify_fail("你的内功等级不够。\n");
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
        level   = (int) me->query_skill("fanliangyi-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
 || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练反两仪刀法。\n");
        me->receive_damage("qi", 35);
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
        return __DIR__"fanliangyi-dao/" + action;
}

