// guangming-blade.c 光明刀法
inherit SKILL;
mapping *action = ({
([  "action" : "$N临空越起手中$w脱鞘而出，一招「"+RED+"光霁风月"+NOR+"」，刀锋化作一团银光，向$n的$l撩去",
    "force" : 120,
    "damage_type" : "割伤"
]),
([  "action" : "$N紧握刀柄大喝一声，一招「"+BLU+"光怪离奇"+NOR+"」，$w一提一收，平刃挥向$n的颈部",
    "force" : 130,
    "damage_type" : "割伤"
]),
([  "action" : "$N提刀吸气，一招「"+HIW+"光芒万丈"+NOR+"」，手中$w光芒四射，斩向$n的$l",
    "force" : 140,
    "damage_type" : "割伤"
]),
([  "action" : "$N抽刀转身，一招「"+WHT+"自投罗网"+NOR+"」，脚尖一点，手中$w一晃，自上而下划出一个闪电，直劈向$n的$l",
    "force" : 160,
    "damage_type" : "割伤"
]),
([  "action" : "$N手中$w一沉，一招「"+CYN+"泥澜壮阔"+NOR+"」，手中$w一提，砍向$n的$l",
    "force" : 180,
    "damage_type" : "割伤"
]),
([  "action" : "$N挥舞$w，使出一招「"+MAG+"披星戴月"+NOR+"」，身形如流星一般，手中$w，齐齐劈向$n的$l",
    "force" : 210,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+HIC+"云谲波诡"+NOR+"」，$w夹杂着忽忽风声，劈向$n的$l",
    "force" : 240,
    "damage_type" : "劈伤"
]),
([  "action" : "$N单脚离地，手中$w一招「"+HIB+"沐雨栉风"+NOR+"」，刀光如雨，向$n的全身洒去",
    "force" : 280,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+YEL+"山高水低"+NOR+"」，$w乎上乎下向$n的$l劈去",
    "force" : 320,
    "damage_type" : "砍伤"
]),
([  "action" : "$N一招「"+HIY+"听天由命"+NOR+"」，$w象无任何章法，直劈向$n的$l",
    "force" : 320,
    "damage_type" : "劈伤"
]),
([  "action" : "$N御空而行，一招「"+RED+"纷至杳来"+NOR+"」，手中$w分作数到锋芒，劈向$n的$l",
    "force" : 350,
    "damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }
int practice_level(){   return 140;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("blade", 1) < 20)
        return notify_fail("你的基本刀法火候太浅。\n");
    if (me->query_skill("blade", 1) <=me->query_skill("guangming-blade", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
        mapping a_action;
        int i, level;
        level   = (int) me->query_skill("wuhu-duanmendao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    if ( me->query_temp("perform_duan")) level+=level;
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level;
    a_action["damage"] = level*4;
    return a_action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练光明刀法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
//string perform_action_file(string action)
//{
//    return __DIR__"wuhu-duanmendao/" + action;
//}

