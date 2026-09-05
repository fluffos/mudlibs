//Modified by iszt@pkuxkx, 2007-02-28

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":HIB"$N身形一晃，一招「赵客缦胡缨 吴钩霜雪明」，刀法之中当隐含吴钩之势，圆转如意"NOR,
        "force" : 120,
        "dodge" : 10,
        "damage": 200,
        "lvl" : 0,
        "weapon" : "左手手掌",
        "damage_type":  "割伤"
]),
([      "action":HIR"$N口中吟道：「十步杀一人 千里不留行」，$w向$n咽喉点去"NOR,
        "force" : 140,
        "dodge" : 0,
        "damage": 250,
        "lvl" : 40,
        "weapon" : "右手",
        "damage_type":  "割伤"
]),
([      "action":HIG"$w在$N胸前划过一道弧线，一招「闲过信陵饮 脱剑膝前横」，向$n重重砍去"NOR,
        "force" : 160,
        "dodge" : 5,
        "damage": 300,
        "lvl" : 80,
        "weapon" : "右手手掌",
        "damage_type":  "割伤"
]),
([      "action":HIW"突然间$N身形左右摇摆，似是站立不稳，一招「三杯吐然诺 五岳倒为轻」，$w由上而下急射向$n"NOR,
        "force" : 400,
        "dodge" : -10,
        "damage": 320,
        "lvl" : 100,
        "weapon" : "右手",
        "damage_type":  "割伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "blade" || usage == "parry"; 
}  

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        return 1;
}

int valid_combine(string combo) { return combo=="xiake-jianfa"; }

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
        level   = (int) me->query_skill("xiake-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
        return __DIR__"xiake-daofa/" + action;
}

string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后脚下一滑，身体向右一侧，避过了攻击。\n",
});

int practice_skill(object me)
{
        return notify_fail("侠客刀法只能用学(learn)的来增加熟练度。\n");
}

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
