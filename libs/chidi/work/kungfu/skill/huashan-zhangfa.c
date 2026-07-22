// huashan-zhangfa.c 华山掌法
inherit SKILL;
mapping *action = ({
([  "action" : "$N一式「"+RED+"白云出岫"+NOR+"」，双掌间升起一团淡淡的白雾，缓缓推向$n的$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : RED "白云出岫" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N并指如剑，一式「"+HIW+"白虹贯日"+NOR+"」，疾向$n的$l戳去",
    "force" : 220,
    "lvl" : 10,
    "skill_name" : HIW "白虹贯日" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「"+HIW+"云断秦岭"+NOR+"」，左掌微拂，右掌乍伸乍合，猛地插往$n的$l",
    "force" : 260,
    "lvl" : 20,
    "skill_name" : HIW "云断秦岭" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N双掌隐隐泛出青气，一式「"+GRN+"青松翠翠"+NOR+"」，幻成漫天碧绿的松针，雨点般向$n击去",
    "force" : 300,
    "lvl" : 30,
    "skill_name" : GRN "青松翠翠" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N身形往上一纵，使出一式「"+BLU+"天坤倒悬"+NOR+"」，双掌并拢，笔直地向$n的$l插去",
    "force" : 340,
    "lvl" : 40,
    "skill_name" : BLU "天坤倒悬" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N身形一变，使一式「"+RED+"无边落木"+NOR+"」，双掌带着萧刹的劲气，猛地击往$n的$l",
    "force" : 380,
    "lvl" : 50,
    "skill_name" : RED "无边落木" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「"+GRN+"高山流水"+NOR+"」，左掌凝重，右掌轻盈，同时向$n的$l击去",
    "force" : 420,
    "lvl" : 60,
    "skill_name" : GRN "高山流水" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N突地一招「"+CYN+"金玉满堂"+NOR+"」，双掌挟着一阵风雷之势，猛地劈往$n的$l",
    "force" : 460,
    "lvl" : 70,
    "skill_name" : CYN "金玉满堂" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N一式「"+HIW+"风伴流云"+NOR+"」，双掌缦妙地一阵挥舞，不觉已击到$n的$l上",
    "force" : 500,
    "lvl" : 80,
    "skill_name" : HIW "风伴流云" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N一式「"+YEL+"烟雨飘渺"+NOR+"」，身形凝立不动，双掌一高一低，看似简单，却令$n无法躲闪",
    "force" : 540,
    "lvl" : 90,
    "skill_name" : YEL "烟雨飘渺" NOR,
        "damage_type" : "瘀伤"
])
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 90;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练华山掌法必须空手。\n");
    if ((int)me->query_skill("zixia-shengong", 1) < 20)
        return notify_fail("你的紫霞神功火候不够，无法学华山掌法。\n");
    if ((int)me->query("max_neili") < 120)
        return notify_fail("你的内力太弱，无法练华山掌法。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("huashan-zhangfa", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
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
    mapping a_action;
    level   = (int) me->query_skill("huashan-zhangfa",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练华山掌法必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 40)
        return notify_fail("你的内力不够练华山掌法。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"huashan-zhangfa/" + action;
}
