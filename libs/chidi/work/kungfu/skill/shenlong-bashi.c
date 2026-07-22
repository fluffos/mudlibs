// shenlong-bashi 神龙八式
inherit SKILL;
mapping *action = ({
([  "action" : "$N使一招「"+HIW+"疏影横斜"+NOR+"」,左手轻轻一抹，向$n的$l拍去",
    "force": 100,
        "damage_type" : "瘀伤",
    "skill_name" : HIW "疏影横斜" NOR,
]),
([  "action" : "$N鼓气大喝,双掌使一招「"+HIC+"五丁开山"+NOR+"」，推向$n的$l",
    "damage_type" : "瘀伤",
    "skill_name" : HIC "五丁开山" NOR,
]),
([  "action": "$N顺势使一招「"+RED+"风行草偃"+NOR+"」，移肩转身,左掌护面,右掌直击$n",
    "force": 200,
    "damage_type": "瘀伤",
    "skill_name" : RED "风行草偃" NOR,
]),
([  "action": "$N退后几步,突然反手一掌,一招「"+YEL+"神龙摆尾"+NOR+"」，无比怪异地击向$n",
    "force": 250,
    "damage_type": "瘀伤",
    "skill_name" : YEL "神龙摆尾" NOR,
]),
([  "action" : "$N使一式「"+HIC+"风卷残云"+NOR+"」，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
    "damage_type" : "瘀伤",
    "skill_name" : HIC "风卷残云" NOR,
]),
([  "action": "$N忽的使出「"+BLU+"乾坤倒旋"+NOR+"」,以手支地,双腿翻飞踢向$n",
    "force": 250,
    "damage_type": "瘀伤",
    "skill_name" : BLU "乾坤倒旋" NOR,
]),
([  "action": "$N大吼一声，使出「"+GRN+"同归于尽"+NOR+"」，不顾一切般扑向$n",
    "force": 400,
    "damage_type": "内伤",
    "skill_name" : GRN "同归于尽" NOR,
]),
([  "action": "$N深吸一口气,身体涨成球状,猛然流星赶月般直撞向$n",
    "force": 400,
    "damage_type": "内伤",
    "skill_name" : "流星赶月"
]),
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练神龙八式必须空手。\n");
    if ((int)me->query_skill("shenlong-xinfa", 1) < 50)
        return notify_fail("你的神龙心法火候不够，无法学神龙八式.\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("你的基本内功火候不够，无法学神龙八式。\n");
    if ((int)me->query("max_neili") < 350)
        return notify_fail("你的内力太弱，无法练神龙八式。\n");
    if (2*(int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shenlong-bashi",1))
        return notify_fail("你的神龙心法火候不够，无法继续学神龙八式。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("shenlong-bashi", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int level;
    level   = (int) me->query_skill("shenlong-bashi", 1);
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练神龙八式必须空手。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 30)
        return notify_fail("你的内力不够练神龙八式。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
