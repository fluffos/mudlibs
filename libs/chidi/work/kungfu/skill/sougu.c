//sougu.c 搜骨鹰爪功
inherit SKILL;
mapping *action = ({
([  "action" : "$N双臂一拢，左爪直攻$n下盘，右爪却挟风雷之势推向$n腰间，一虚一实，正是一招「"+HIB+"推爪式"+NOR+"」",
    "force" : 170,
    "damage_type" : "抓伤",
    "lvl" : 0,
    "skill_name" : BLU "推爪式" NOR,
]),
([  "action" : "$N身形陡起，如雄鹰击日般“倏”地从$n头顶越过，使一招「"+WHT+"盖爪式"+NOR+"」双爪疾向$n脑后击下",
    "force" : 190,
    "damage_type" : "抓伤",
    "lvl" : 14,
    "skill_name" : WHT "盖爪式" NOR,
]),
([  "action" : "$N就地一滚，突然到了$n身前，使一招「"+RED+"掏爪式"+NOR+"」，右爪直奔$n小腹",
    "force" : 215,
    "damage_type" : "抓伤",
    "lvl" : 35,
    "skill_name" : RED "掏爪式" NOR,
]),
([  "action" : "$N左爪护胸，右爪凝劲后发，一招「"+MAG+"托爪式"+NOR+"」，缓缓托向$n的$l",
    "force" : 245,
    "damage_type" : "抓伤",
    "lvl" : 58,
    "skill_name" : MAG "托爪式" NOR,
]),
([  "action" : "$N身形诡异，疾速前扑，使一招「"+CYN+"撩爪式"+NOR+"」，直撩$n裆部",
    "force" : 280,
    "damage_type" : "抓伤",
    "lvl" : 70,
    "skill_name" : CYN "撩爪式" NOR,
]),
([  "action" : "$N身形飘忽，陡然转到$n身后，一招「"+BLK+"锁爪式"+NOR+"」，双爪直向$n咽喉插下",
    "force" : 320,
    "damage_type" : "抓伤",
    "lvl" : 81,
    "skill_name" : BLK "锁爪式" NOR,
]),
([  "action" : "$N一声厉啸，身形拔起，使出「"+YEL+"千爪式"+NOR+"」，由半空盘旋下击，$n顿觉漫天爪影，罩向全身死穴",
    "force" : 365,
    "damage_type" : "抓伤",
    "lvl" : 94,
    "skill_name" : YEL "千爪式" NOR,
])
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 100;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练搜骨鹰爪功必须空手。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("sougu", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法学搜骨鹰爪功。\n");
    if ((int)me->query("str") < 24)
        return notify_fail("你的臂力太差，无法学搜骨鹰爪功。\n");
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
    mapping a_action;
    int i, level;
    level = (int)me->query_skill("sougu", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level*2;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练搜骨鹰爪功必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练鹰爪功。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"sougu/" + action;
}
