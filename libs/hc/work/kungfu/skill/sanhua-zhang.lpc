// sanhua-zhang.c -散花掌
inherit SKILL;
mapping *action = ({
([  "action" : "$N合掌抱球，一式「"+GRN+"春深芳草尽"+NOR+"」，双掌变幻吞吐，缓缓推向$n的$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : GRN "春深芳草尽" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N五指绽开，一式「"+YEL+"夏闲独兰馨"+NOR+"」，左右掌穿插翻飞，疾向$n的$l拍去",
    "force" : 260,
    "lvl" : 25,
    "skill_name" : YEL "夏闲独兰馨" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「"+BLU+"秋酣菊霜清"+NOR+"」，左掌虚托，右掌乍伸乍合，猛地插往$n的$l",
    "force" : 340,
    "lvl" : 56,
    "skill_name" : BLU "秋酣菊霜清" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N双掌血红，一式「"+HIW+"冬卧听梅吟"+NOR+"」，幻成漫天梅花朵朵，雨点般向$n击去",
    "force" : 420,
    "lvl" :  72,
    "skill_name" : HIW "冬卧听梅吟" NOR,
        "damage_type" : "瘀伤"
])
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 72;  }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练散花掌必须空手。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练散花掌。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("sanhua-zhang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学散花掌。\n");
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
    level   = (int) me->query_skill("sanhua-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/2;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/3;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练散花掌必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练散花掌。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
