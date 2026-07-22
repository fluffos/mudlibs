inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「破竹势」，抡起手中的$w向$n的$l砸去  ",
        "skill_name" : "破竹势",
        "dodge" : -10,
        "parry" : 10,
        "damage" : 50,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「隐山谷势」，双肩一沉，舞动手中$w向$n的$l横扫  ",
        "skill_name" : "隐山谷势",
        "dodge" : -20,
        "parry" : -20,
        "damage" : 55,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「隐微势」，就地一滚，手中自下而上撩向$n的$l  ",
        "skill_name" : "隐微势",
        "dodge" : -20,
        "parry" : 10,
        "damage" : 60,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「擒纵势」，身形起伏之际$w扫向$n的$l  ",
        "skill_name" : "擒纵势",
        "dodge" : 5,
        "parry" : 15,
        "damage" : 65,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「圆满势」，$w如离弦之箭般直捣$n的$l  ",
        "skill_name" : "圆满势",
        "dodge" : -10,
        "parry" : 10,
        "damage" : 75,
        "damage_type" : "挫伤",
]),
([      "action" : "$N提一口真气，使出「显吉祥」，$w扫向$n的头部  ",
        "skill_name" : "显吉祥",
        "dodge" : -10,
        "parry" : 10,
        "damage" : 80,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「捉月势」，斜举手中$w击向$n的$l  ",
        "skill_name" : "捉月势",
        "dodge" : -15,
        "parry" : 15,
        "damage" : 90,
        "damage_type" : "挫伤",
]),
([      "action" : "$N跃入半空，使一招「月重辉势」，高举$w敲向$n的$l  ",
        "skill_name" : "月重辉势",
        "dodge" : 10,
        "parry" : 10,
        "damage" : 100,
        "damage_type" : "挫伤",
]),
});


int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练日月轮。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("你的武器不对。\n");

        return 1;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习日月轮。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍日月轮。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
