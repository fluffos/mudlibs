// tianmo-dao.c 天魔刀

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w一抖，一招「唯我独尊」，一刀向$n的$l砍去",
        "force" : 120,
        "dodge" : -10,
        "lvl" : 0,
        "skill_name" : "唯我独尊",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「万里独行」，手中$w一晃，一道刀光射向$n的丹田",
        "force" : 130,
        "dodge" : -10,
        "damage" : 5,
        "lvl" : 8,
        "skill_name" : "万里独行",
        "damage_type" : "割伤"
]),
([      "action" : "$N身形急转，一招「索命无常」，手中$w从诡异的角度斩向$n的$l",
        "force" : 140,
        "dodge" : -5,
        "damage" : 15,
        "lvl" : 16,
        "skill_name" : "索命无常",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「血流成河」，$w自上而下，以不可思议速度劈向$n",
        "force" : 160,
        "dodge" : 5,
        "damage" : 25,
        "lvl" : 24,
        "skill_name" : "血流成河",
        "damage_type" : "割伤"
]),
([      "action" : "$N手中$w一挥，一招「君临天下」，拦腰砍向$n",
        "force" : 180,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 33,
        "skill_name" : "君临天下",
        "damage_type" : "割伤"
]),
([      "action" : "$N使出一招「天火燎燃」，$w化作数十道红光自上而下罩向$n",
        "force" : 210,
        "dodge" : 15,
        "damage" : 35,
        "lvl" : 42,
        "skill_name" : "天火燎燃",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「穷途末路」，错步向前，$w顺势挟风声劈向$n的$l",
        "force" : 240,
        "dodge" : 5,
        "damage" : 50,
        "lvl" : 51,
        "skill_name" : "穷途末路",
        "damage_type" : "割伤"
]),
([      "action" : "$N向上纵起丈余，一招「群魔乱舞」，$w在半空幻作千百刀光电射而下，把$n包围在一片刀影之中",
        "force" : 280,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 60,
        "skill_name" : "群魔乱舞",
        "damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if( userp(me) )
        return notify_fail("你的天魔功火候太浅，学不了天魔刀。\n");
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
        level   = (int) me->query_skill("tianmo-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if(userp(me))
                return notify_fail("你无法练天魔刀。\n");
        return 1;
}