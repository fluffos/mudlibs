// wuliang-jianfa.c 无量剑法

inherit SKILL;

mapping *action = ({
([     "action" : "$N未等招数未老，陡然收势，剑尖在半空中微微一抖，一个剑花，变招斜刺$n$l",
       "force" : 240,
       "damage" : 30,
       "lvl" : 0,
       "damage_type" : "刺伤"
]),
([     "action" : "$N长剑上撩，使招「万卉争艳」，剑光乱颤，牢牢将上盘封住",
       "force" : 270,
        "dodge" : 5,
       "damage" : 35,
       "lvl" : 15,
       "damage_type" : "刺伤"
]),
([     "action" : "$N一招「顺水推舟」，剑锋乘势向$n的$l推去",
       "force" : 290,
        "dodge" : 5,
       "damage" : 40,
       "lvl" : 20,
       "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 100)
               return notify_fail("你的内力不够。\n");
       if ((int)me->query_skill("wuliang-shengong", 1) < 20)
               return notify_fail("你的无量神功火候太浅。\n");
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
       level   = (int) me->query_skill("wuliang-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "sword")
               return notify_fail("你使用的武器不对。\n");
       if ((int)me->query("jingli") < 50)
               return notify_fail("你的体力不够练无量剑法。\n");
       me->receive_damage("jingli", 35);
       return 1;
}
