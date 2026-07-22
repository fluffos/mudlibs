// quanzhen-jianfa 全真剑法

inherit SKILL;

mapping *action = ({
([      "action" : "$N长剑晃动，踏奇门，走偏锋，一式「分花拂柳」，刺向$n的腰胁",
        "force" : 150,
        "dodge" : 20,
        "damage" : 40,
        "parry" : 10,
        "lvl" : 0,
        "skill_name" : "分花拂柳",
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跃上一步，左手剑诀，右手$w使出一式「横行漠北」直刺$n的$l",
        "force" : 170,
        "dodge" : 15,
        "damage" : 50,
        "parry" : 20,
        "lvl" : 10,
        "skill_name" : "横行漠北",
        "damage_type" : "刺伤"
]),
([      "action" : "$N拔步挺腰，一式「排山倒海」，手中$w沉滞无比，缓缓挥剑撞向$n的$l",
        "force" : 190,
        "dodge" : 15,
        "damage" : 60,
        "parry" : 20,
        "lvl" : 25,
        "skill_name" : "排山倒海",
        "damage_type" : "刺伤"
]),
([      "action" : "$N身子微侧，$w自左而右划出一个大弧，一式「顺水推舟」，平平地向$n的$l挥去",
        "force" : 230,
        "dodge" : 10,
        "damage" : 70,
        "parry" : 10,
        "lvl" : 30,
        "skill_name" : "顺水推舟",
        "damage_type" : "刺伤"
]),
([      "action" : "$N回身拧腰，右手虚抱成圆，一式「马蹴落花」，$w中宫直进，刺向$n的胸口",
        "force" : 280,
        "dodge" : 10,
        "damage" : 80,
        "parry" : 15,
        "lvl" : 50,
        "skill_name" : "马蹴落花",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「开天辟地」，$w从上至下猛劈，剑锋直出，挟爆裂之声骤然斩向$n的$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 90,
        "parry" : 20,
        "lvl" : 70,
        "skill_name" : "开天辟地",
        "damage_type" : "刺伤"
]),
([      "action" : "$N运气施出「雷电交加」，$w剑尖逼出一道青芒，闪电般破空射向$n的$l",
        "force" : 330,
        "dodge" : 5,
        "damage" : 100,
        "parry" : 15,
        "lvl" : 90,
        "skill_name" : "雷电交加",
        "damage_type" : "刺伤"
]),
([      "action" : "$N双腿半屈半蹲，一式「人神共愤」，剑尖划出无数圆圈，狂风骤起，笼罩天地",
        "force" : 380,
        "dodge" : -5,
        "damage" : 120,
        "parry" : 25,
        "lvl" : 110,
        "skill_name" : "人神共愤",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage)
{
   return (usage == "sword") || (usage == "parry"); 
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("force", 1) < 40)
                return notify_fail("你的基本内功火侯太浅。\n");
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
            level   = (int) me->query_skill("quanzhen-jianfa",1);
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
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练全真剑法。\n");
          if ((int)me->query("qi") < 40)
                return notify_fail("你的体力不够练全真剑法。\n");
          me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"quanzhen-jianfa/" + action;
}

