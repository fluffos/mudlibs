//white for jhfy.nh hero
//pomo-jianfa
inherit SKILL;
mapping *action = ({
([  "action" : "$N舞动$W，一招「"+HIW+"白虹贯日"+NOR+"」，看似无招,然剑尖已及$n面门",
    "force" : 400,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([  "action" : "$N向前跨上一步，$w使出一式「"+HIG+"春风杨柳"+NOR+"」直刺$n的$l",
    "force" : 370,
    "lvl" : 10,
    "damage_type" : "刺伤"
]),
([  "action" : "$N身形一顿，$w已在身前连划三个圆圈，幻作三个光圈,使出一式「"+WHT+"腾蛟起凤"+NOR+"」刺向$n的$l",
    "force" : 380,
    "lvl" : 15,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+HIM+"玉龙倒悬"+NOR+"」，剑气满室，寒风袭体。缓缓刺向$n的$l",
    "force" : 330,
    "lvl" : 37,
    "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int practice_level(){   return 145;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你必须先找把剑才能学泼墨披麻剑法。\n");

    if ((int)me->query("max_neili") < 5000)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("sword", 1) <=me->query_skill("pomo-jianfa", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("pomo-jianfa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*3;
    a_action["parry"]  = 0-level*3;
    a_action["attack"]  = level*3;
    a_action["damage"] = level*3;
    return a_action;

}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练泼墨披麻剑法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"pomo-jianfa/" + action;
}

