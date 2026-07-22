// zhenfeng-qiangfa 震风枪法

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w点向$n的$l",
        "damage" : 40,
        "lvl"    : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「乱舞狂风」，$w闪烁不定，刺向$n的$l",
        "damage" : 50,
        "lvl"    : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「天昏地暗」，无数$w上下刺出，直向$n逼去",
        "damage" : 60,
        "lvl"    : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，手中$w使出「金枪锁喉」直刺$n的喉部",
        "damage" : 80,
        "lvl"    : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "只见$N抡起手中的$w，使出「光芒万丈」万点金光直射$n",
        "damage" : 100,
        "lvl"    : 50,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("zhenfeng-xinfa", 1) < 20)
                return notify_fail("你的「震风心法」火候不够，无法学「震风枪法」。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练「震风枪法」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练「震风枪法」。\n");
        if ((int)me->query("neili") < 30)
                return notify_fail("你的内力不够练「震风枪法」。\n");
        me->receive_damage("qi", 30);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhenfeng-qiangfa/" + action;
}
