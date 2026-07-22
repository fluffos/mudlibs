// sanyang-unarmed.c -三阴掌
inherit SKILL;
mapping *action = ({
([  "action" : "$N一式「"+GRN+"天山雪飘"+NOR+"」，掌影飞舞，霎时之间将$n周身大穴都裹住了",
    "force" : 200,
    "lvl" : 0,
    "skill_name" : GRN "天山雪飘" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "在呼呼风声中，$N使一招「"+RED+"双龙出海"+NOR+"」，宛如潜龙出水，翻江倒海，砭肤生寒，插向$n的$l",
    "force" : 250,
    "lvl"   : 40,
    "skill_name" : RED "双龙出海" NOR ,     
    "damage_type" : "内伤"
]),
([  "action" : "$N双拳挥舞，一式「"+HIY+"九转玄风"+NOR+"」，右掌极其玄奇地一连数圈，毫无声色，轻飘飘地打向$n",
    "force" : 250,
    "lvl" : 50,
    "skill_name" : HIY "九转玄风" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N一招「"+HIG+"摧心罡煞"+NOR+"」手掌一扬，一道阴风向$n飒然飘去打向$n的$l",
    "force" : 300,
    "lvl"   : 60,
    "skill_name" : HIG "摧心罡煞" NOR ,     
    "damage_type" : "内伤"
]),
([  "action" : "$N一招「"+HIW+"兴风作浪"+NOR+"」划空的啸风，激荡的掌力，势道惊人，插向$n的顶门",
    "force" : 260,
    "lvl"   : 80,
    "skill_name" : HIW "兴风作浪" NOR ,     
    "damage_type" : "内伤"
]),
([  "action" : "$N无声无色的，一招「"+HIB+"六王招魂"+NOR+"」，却宛如带有死亡气息般的罩落",
    "force" : 300,
    "lvl"   : 150,
    "skill_name" : HIB "六王招魂" NOR ,     
    "damage_type" : "内伤"
]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 150;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练三阴掌必须空手。\n");
    if ((int)me->query("max_neili") < 250)
        return notify_fail("你的内力太弱，无法练三阴掌。\n");
    if ((int)me->query_skill("unarmed",1) <30)
        return notify_fail("你的基本拳脚火候不够，无法学三阴掌。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("yunlong-shou", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action); i > 0; i--)
        if(level >= action[i-1]["lvl"])
            return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("sanyin-unarmed",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level*2;
    a_action["damage"] = level*2;
    return a_action;

}


int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练三阴掌必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练三阴掌。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yunlong-shou/" + action;
}
