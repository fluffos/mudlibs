// yizhi-chan.c 一指禅
inherit SKILL;
mapping *action = ({
([  "action" : "$N双指并拢，一式「"+YEL+"佛恩济世"+NOR+"」，和身而上，左右手一前一后戳向$n的胸腹间",
    "force" : 60,
    "lvl" : 0,
    "skill_name" : YEL "佛恩济世" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N左掌护胸，一式「"+RED+"佛光普照"+NOR+"」，右手中指前后划了个半弧，猛地一甩，疾点$n的$l",
    "force" : 120,
    "lvl" : 20,
    "skill_name" : RED "佛光普照" NOR,
        "damage_type" : "刺伤"
]),
([  "action" : "$N身形闪动，一式「"+HIC+"佛门广渡"+NOR+"」，双手食指端部各射出一道青气，射向$n的全身要穴",
    "force" : 240,
    "lvl" : 40,
    "skill_name" : HIC "佛门广渡" NOR,
        "damage_type" : "刺伤"
]),
([  "action" : "$N盘膝跌坐，一式「"+HIY+"佛法无边"+NOR+"」，左手握拳托肘，右手拇指直立，遥遥对着$n一捺",
    "force" : 480,
    "lvl" : 60,
    "skill_name" : HIY "佛法无边" NOR,
        "damage_type" : "刺伤"
])
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="banruo-zhang"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练一指禅必须空手。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练一指禅。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("yizhi-chan", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学一指禅。\n");
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
    level   = (int) me->query_skill("yizhi-chan",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level/2;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练一指禅必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练一指禅。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yizhi-chan/" + action;
}
