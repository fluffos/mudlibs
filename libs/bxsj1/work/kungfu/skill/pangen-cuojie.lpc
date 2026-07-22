// pangen-cuojie.c 

inherit SKILL;

mapping *action = ({
([      "action" : "$N高举手中$w，一式「盘龙枝」，伏身向前，向$n的$l砍去",
        "force" : 160,
        "dodge" : 5,
        "damage" : 10,
        "lvl" : 0,
        "skill_name" : "盘龙枝",
        "damage_type" : "砍伤"
]),
([      "action" : "$N一式「翻江海」，起身立蹲，肩定斧背，$w缓缓向$n的$l奔去",
        "force" : 200,
        "dodge" : 10,
        "damage" : 20,
        "lvl" : 30,
        "skill_name" : "翻江海",
        "damage_type" : "劈伤"
]),
([      "action" : "$N挥动$w，掀起了漫天斧影，一式「错乱节」，斧风顿时笼罩$n的全身",
        "force" : 240,
        "dodge" : -15,
        "damage" : 40,
        "lvl" : 60,
        "skill_name" : "错乱节",
        "damage_type" : "砍伤"
]),
([      "action" : "$N一式「十八开」，右手$w柄倒翻上来，直劈向$n的小腹",
        "force" : 280,
        "dodge" : -10,
        "damage" : 60,
        "lvl" : 90,
        "skill_name" : "十八开",
        "damage_type" : "劈伤"
]),
([      "action" : "$N右手手腕一转，一式「盘根错节」，双手挥起$w砍向$n的$l",
        "force" : 300,
        "dodge" : -10,
        "damage" : 80,
        "lvl" : 120,
        "skill_name" : "盘根错节",
        "damage_type" : "砍伤"
]),
});


int valid_enable(string usage)
{
    return usage == "axe" || usage == "parry"; 
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 150)
                return notify_fail("你的内力不够。\n");
       if (me->query_str() < 25)
                return notify_fail("你的臂力太低。\n");
        if ((int)me->query_skill("qiantian-yiyang", 1) < 30)
                return notify_fail("你的「乾天一阳功」火候太浅。\n");
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
        level   = (int) me->query_skill("pangen-cuojie",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "axe")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的体力不够练习「盘根错节斧」。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练习「盘根错节斧」。\n");
        me->receive_damage("jingli", 30);        
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pangen-cuojie/" + action;
}
