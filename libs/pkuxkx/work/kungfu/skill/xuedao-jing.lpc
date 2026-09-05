// xuedao-jing.c 血刀经
// write by iceland

inherit SKILL;

mapping *action = ({
([      "action" : "$N略略侧身，一招「斩头式」反手从背后横劈出一刀，直奔$n的项颈。\n  ",
        "skill_name" : "斩头式",
        "force" : 100,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "割伤",
]),
([      "action" : "$N突然横卧于地，$n目瞪口呆之际，一招「破膛刀」，手中$w由下而上直劈$n的小腹。  ",
        "skill_name" : "破膛刀",
        "force" : 140,
        "dodge" : 5,
        "parry" : -5,
        "lvl" : 8,
        "damage" : 50,
        "damage_type" : "割伤",
]),
([      "action" : "$N足尖一点，一个倒翻头顶着地，一招「去魂电」，$w一闪，自左而右，由右到左连出十刀。  ",
        "skill_name" : "去魂电",
        "force" : 180,
        "dodge" : 10,
        "parry" : -5,
        "lvl" : 16,
        "damage" : 65,
        "damage_type" : "割伤",
]),
([      "action" : "$N怪叫一声，飞腾空中，一招「流星经天」，手中$w脱手而出，疾射$n的$l  ",
        "skill_name" : "流星经天",
        "force" : 220,
        "dodge" : 0,
        "parry" : 5,
        "lvl" : 23,
        "damage" : 70,
        "damage_type" : "割伤",
]),
([      "action" : "$N脸色诡异，喉中“呵呵”低吼，一招「蛇行」，$w灵动异常的在$n的$l游走过去  ",
        "skill_name" : "蛇行",
        "force" : 250,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 30,
        "damage" : 80,
        "damage_type" : "割伤",
]),
([      "action" : "$N一招「三界咒」，手中$w微微一抖，“嗤嗤嗤”三声轻响，向$n头、胸、腹连劈三刀。  ",
        "skill_name" : "三界咒",
        "force" : 320,
        "dodge" : 10,
        "parry" : -5,
        "lvl" : 40,
        "damage" : 110,
        "damage_type" : "割伤",
]),
([      "action" : "$N炸雷般大喝一声，一式「魔分身」$w照$n搂肩带背斜劈下来，力道凶猛，势不可挡。  ",
        "skill_name" : "魔分身",
        "force" : 300,
        "dodge" : -15,
        "parry" : 10,
        "lvl" : 60,
        "damage" : 130,
        "damage_type" : "割伤",
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }


int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 150)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("longxiang-boruo", 1) < 20)
                return notify_fail("你的龙象般若功火候太浅。\n");
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
        level   = (int) me->query_skill("xuedao-jing",1);
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
                return notify_fail("你的体力不够，练不了血刀经。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuedao-jing/" + action;
}


