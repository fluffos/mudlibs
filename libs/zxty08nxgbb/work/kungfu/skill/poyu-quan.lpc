// poyu-quan.c 劈石破玉拳
inherit SKILL;
mapping *action = ({
([  "action" : "$N右脚立定、左脚虚点，一式「"+HIW+"起手式"+NOR+"」，左右手一高一低，击向$n的$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : HIW "起手式" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左脚虚踏，全身右转，一招「"+WHT+"石破"+BLU+"天惊"+NOR+"」，右拳猛地击向$n的$l",
    "force" : 200,
    "lvl" : 60,
    "skill_name" : WHT "石破天惊" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双手大开大阖，宽打高举，使一招「"+HIC"+铁闩横门"+NOR+"」，双拳向$n的$l打去",
    "force" : 220,
    "lvl" : 40,
    "skill_name" : HIC "铁闩横门" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左掌圈花扬起，屈肘当胸，右手虎口朝上，一招「"+MAG+"千斤坠地"+NOR+"」打向$n的$l",
    "force" : 260,
    "lvl" : 20,
    "skill_name" : MAG "千斤坠地" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N使一招「"+RED+"傍花拂柳"+NOR+"」，上身前探，双拳划了个半圈，击向$n的$l",
    "force" : 300,
    "lvl" : 10,
    "skill_name" : RED "傍花拂柳" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双拳划弧，一记「"+YEL+"金刚挚尾"+NOR+"」，掌出如电，一下子切到$n的手上",
    "force" : 360,
    "lvl" : 20,
    "skill_name" : YEL "金刚挚尾" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N施出「"+HIM+"封闭手"+NOR+"」，双拳拳出如风，同时打向$n头，胸，腹三处要害",
    "force" : 420,
    "lvl" : 80,
    "skill_name" : HIM "封闭手" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左脚内扣，右腿曲坐，一式「"+BLK+"粉石碎"+CYN+"玉"+NOR+"」，双拳齐齐捶向$n的胸口",
    "force" : 540,
    "lvl" : 90,
    "skill_name" : CYN "粉石碎玉" NOR,
    "damage_type" : "瘀伤"
])
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 90;  }
int valid_combine(string combo) { return combo=="hunyuan-zhang"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练「劈石破玉拳」必须空手。\n");
    if ((int)me->query_skill("zixia-shengong", 1) < 10)
        return notify_fail("你的「"+MAG+"紫霞神功"+NOR+"」火候不够，无法学「劈石破玉拳」。\n");
    if ((int)me->query("max_neili") < 50)
        return notify_fail("你的内力太弱，无法练「"+YEL+"劈石破玉拳"+NOR+"」。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("poyu-quan", 1))
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
    level   = (int) me->query_skill("poyu-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/3;
    return a_action;

}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练「劈石破玉拳」必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练「"+YEL+"劈石破玉拳"+NOR+"」。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"poyu-quan/" + action;
}
