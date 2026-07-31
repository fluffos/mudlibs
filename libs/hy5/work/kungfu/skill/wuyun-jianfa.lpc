// wuyun-jianfa.c
inherit SKILL;

mapping *action = ({
([      "action" : "$N左小指轻弹，一招「宫韵」悄然划向$n的后心",
        "force" : 120,
        "dodge" : 20,
        "damage" : 160,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N右手无名指若有若无的一划，将琴弦并做一处，[商韵]已将$n笼罩
",
        "force" : 140,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N五指疾挥，一式[角韵]无形的刺向$n的左肋",
        "force" : 270,
        "dodge" : 15,
        "damage" : 280,
        "lvl" : 29,
        "damage_type" : "刺伤"
]),
([      "action" : "$N将手中剑横扫，同时左右手如琵琶似的疾弹，正是一招[支韵]",
        "force" : 390,
        "dodge" : 10,
        "damage" : 390,
        "lvl" : 89,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「羽韵」，将剑提至唇边，如同清音出箫，剑掌齐出，划向$n
的$l",
        "force" : 440,
        "dodge" : 10,
        "damage" : 400,
        "lvl" : 39,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
//        if ((int)me->query_skill("wuzheng-xinfa", 1) < 20)
//                return notify_fail("你的无争心法火候不到。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
            level   = (int) me->query_skill("wuyun-jianfa",1);
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
        if ((int)me->query("jing") < 50)
                return notify_fail("你的体力不够练五韵七弦剑。\n");
        me->receive_damage("jing", 30);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"wuyun-jianfa/" + action;
}

