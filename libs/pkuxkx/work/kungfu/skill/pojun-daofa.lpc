//pojun-daofa 破军刀法
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N手中$w平推过去，看似平缓实则迅速地向$n的$l撩去",
    "force" : 150,
    "dodge" : 10,
    "damage" : 10,
    "lvl" : 0,
    "damage_type" : "割伤"
]),
([  "action" : "$N右脚一点，身形瞬间向前，$w寒光闪闪，快速割向$n的$l",
    "force" : 170,
    "dodge" : 35,
    "damage" : 20,
    "lvl" : 10,
    "damage_type" : "割伤"
]),
([  "action" : "$N手臂一抡，刀锋一卷，自上而下斩向$n",
    "force" : 190,
    "dodge" : 25,
    "damage" : 25,
    "lvl" : 20,
    "damage_type" : "割伤"
]),
([  "action" : "$N侧身而退，$w却在胸前划出一道圆弧，横劈$n的$l",
    "force" : 210,
    "dodge" : 15,
    "damage" : 35,
    "lvl" : 32,
    "damage_type" : "割伤"
]),
([  "action" : "$N侧身滑步而上，欺至$n身前，$w猛砍$n的$l",
    "force" : 230,
    "dodge" : 20,
    "damage" : 50,
    "lvl" : 45,
    "damage_type" : "割伤"
]),
([  "action" : "$N快速挥舞$w，幻起一片刀花罩向$n的$l",
    "force" : 260,
    "dodge" : 15,
    "damage" : 65,
    "lvl" : 58,
    "damage_type" : "割伤"
]),
([  "action" : "$N舞起重重刀影向$n的全身砍去",
    "force" : 290,
    "dodge" : 20,
    "damage" : 85,
    "lvl" : 71,
    "damage_type" : "割伤"
]),
([  "action" : "$N平平无奇地将刀作剑使，向$n的$l捅去",
    "force" : 320,
    "dodge" : 40,
    "damage" : 105,
    "lvl" : 86,
    "damage_type" : "割伤"
]),
([  "action" : "$N刀光闪烁不定，最后收束在一起，劈向$n的$l",
    "force" : 350,
    "dodge" : 10,
    "damage" : 125,
    "lvl" : 101,
    "damage_type" : "割伤"
]),
([  "action" : "$N挪步小退，手中$w轻描淡写地挥出一刀，随即又“唰唰”连出两刀劈向$n的$l",
    "force" : 400,
    "dodge" : 20,
    "damage" : 150,
    "lvl" : 120,
    "damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="huqian-jianfa"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("bixue-xinfa", 1) < 150)
        return notify_fail("学习破军刀法需要碧血心法 150 级。\n");
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
    level   = (int) me->query_skill("pojun-daofa",1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if (me->query("neili") < 50 || me->query("qi")< 50)
        return notify_fail("你的内力或体力不足以练「破军刀法」。\n");
    me->receive_damage("qi", 40);
    me->add("neili",-15);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"pojun-daofa/" + action;
}
