//    落英神剑掌 luoying-zhang.c by Jpei

inherit SKILL;

mapping *action = ({
([      "action" : "$N纵身向前，掌势一发即收，双掌连晃，已抢到$n的面前，使出「落英缤纷」，虚虚实实，若有若无地袭向$n",
        "force" : 100,
        "dodge" : 30,
        "parry" : -2,
        "lvl" : 0,
        "skill_name" : "落英缤纷",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左足一点，跃起丈余，在半空连转两个圈子，凌空挥掌，掌做剑形，一招「江城飞花」，向$n当头击下",
        "force" : 150,
        "dodge" : -1,
        "parry" : 5,
        "lvl" : 7,
        "skill_name" : "江城飞花",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左足在前，右足在后，单臂画了个弧线，正是「雨打桃花」，劈头盖脸地向$n按去",
        "force" : 200,
        "dodge" : 5,
        "parry" : 2,
        "lvl" : 15,
        "skill_name" : "雨打桃花",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形一转，已经欺到$n近前，立掌如剑，单手横劈，飕飕风响，一招「雨急风狂」划向$n的$l",
        "force" : 250,
        "dodge" : -5,
        "parry" : 6,
        "lvl" : 28,
        "skill_name" : "雨急风狂",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形连晃，倏忽间已围着$n转了几个圈子，掌影飘飘，正是一招「无边落木」，从四面八方向$n袭去",
        "force" : 300,
        "dodge" : 8,
        "parry" : 5,
        "lvl" : 45,
        "skill_name" : "无边落木",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N长笑一声，踏上一步，双掌连击，虚招多而实招少，霎时化作「满天花雨」，将$n的全身都笼罩在掌影之中",
        "force" : 350,
        "dodge" : -2,
        "parry" : 10,
        "damage" : 35,
        "lvl" : 60,
        "skill_name" : "满天花雨",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N暗暗运劲，力贯双臂，身子如剑般扑向$n，两掌一前一后，使出一招「断艳残红」，狠狠地按向$n的前胸",
        "force" : 400,
        "dodge" : -8,
        "parry" : 8,
        "lvl" : 80,
        "skill_name" : "断艳残红",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("学落英神剑掌必须空手。\n");
//      if (me->query_skill_mapped("force") != "bihai-shengong")
//              return notify_fail("修习落英神剑掌必须有碧海神功配合。\n");
        if((int)me->query_skill("bihai-shengong", 1) < 100 )
                return notify_fail("你的碧海神功火候不够，不能学习落英神剑掌。\n");            
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

        level   = (int) me->query_skill("luoying-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练落英神剑掌。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -20);
        return 1;
}

string perform_action_file(string action)
{
      return __DIR__"luoying-zhang/" + action;
}

