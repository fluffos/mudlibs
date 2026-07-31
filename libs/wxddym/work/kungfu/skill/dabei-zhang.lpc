inherit SKILL;
mapping *action = ({
([  "action" : "$N连续上步，一式「"+YEL+"大慈大悲"+NOR+"」，左右手分靠，变拳为掌，击向$n的$l",
    "force" : 380,
    "lvl" : 0,
    "skill_name" : YEL "大慈大悲" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N左脚虚踏，全身右转，一招「"+RED+"悲从心生"+NOR+"」，右掌猛地插向$n的$l",
    "force" : 300,
    "lvl" : 8,
    "skill_name" : RED "悲从心生" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N使一招「"+HIB+"苦海回头"+NOR+"」，上身前探，双手划了个半圈，击向$n的$l",
    "force" : 300,
    "lvl" : 33,
    "skill_name" : HIB "苦海回头" NOR ,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双掌划弧，一记「"+HIY+"回头是岸"+NOR+"」，掌出如电，一下子切到$n的手上",
    "force" : 360,
    "lvl" : 42,
    "skill_name" : GRN "回头是岸" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N施出「"+WHT+"苦海无边"+NOR+"」，双拳拳出如风，同时打向$n头，胸，腹三处要害",
    "force" : 420,
    "lvl" : 50,
    "skill_name" : WHT "苦海无边" NOR,
        "damage_type" : "瘀伤"
]),
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 58;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("学大悲掌必须空手。\n");
    if ((int)me->query("max_neili") < 50)
        return notify_fail("你的内力太弱，无法练大悲掌。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("dabei-zhang", 1))
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
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("dabei-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["damage"] = level+random(level);
    return a_action;

}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练大悲掌必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练大悲掌。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dabei-zhang/" + action;
}
