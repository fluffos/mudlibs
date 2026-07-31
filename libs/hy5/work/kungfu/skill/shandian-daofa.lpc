//  shandian-daofa闪电刀法

inherit SKILL;

mapping *action = ({
([      "action" : "$N身影变双，刀光浮动，转眼已劈出9刀，向$n的$l挥去",
        "force" : 380,
        "dodge" : 10,
        "parry" : 5,
        "damage": 150,
        "lvl" : 0,
        "skill_name" : "闪电刀法",
        "damage_type" : "割伤"
]),
([      "action" : "$N凌空扬刀，绕$n游走，刀法之快，匪夷所思，手中$w已割向$n的周身各处",
        "force" : 430,
        "dodge" : 10,
        "parry" : 10,
        "damage": 200,
        "lvl" : 12,
        "skill_name" : "闪电刀法",
        "damage_type" : "割伤"
]),
 ([      "action" : "$N掌中$w稍作一顿，旋及如流星划空，闪电霹雳，刷地一声自上而下向$n猛劈",
        "force" : 540,
        "dodge" : 5,
        "parry" : 5,
        "damage": 125,
        "lvl" : 18,
        "skill_name" : "闪电刀法",
        "damage_type" : "割伤"
]),
([      "action" : "$N右手反执刀柄，横刀一斩，$w直向$n的颈中划去",
        "force" : 460,
        "dodge" : 5,
        "parry" : 5,
        "damage": 270,
        "lvl" : 24,
        "skill_name" : "闪电刀法",
        "damage_type" : "割伤",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("shandian-daofa",1);
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
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的体力不够练闪电刀法。\n");
        me->receive_damage("jingli", 35);
        return 1;
}

