
// shexing-diaoshou.c 蛇形刁手
inherit SKILL;
mapping *action = ({
([  "action" : "$N一式「"+RED+"灵蛇出洞"+NOR+"」，右手虚晃，左手扬起，突然拍向$n的背后二穴",
    "force" : 90,
    "lvl" : 0,
    "skill_name" : RED "灵蛇出洞" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N侧身一晃，一式「"+YEL+"虎头蛇尾"+NOR+"」，左手拿向$n的肩头，右拳打向$n的胸口",
    "force" : 120,
    "lvl" : 24,
    "skill_name" : YEL "虎头蛇尾" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N一式「"+HIG+"画蛇添足"+NOR+"」，右手环拢成爪，一出手就向扣$n的咽喉要害",
    "force" : 130,
    "lvl" : 46,
    "skill_name" : HIG "画蛇添足" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N左手虚招，右掌直立，一式「"+HIY+"杯弓蛇影"+NOR+"」，错步飘出，疾拍$n的面门",
    "force" : 160,
    "lvl" : 68,
    "skill_name" : HIY "杯弓蛇影" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「"+BLK+"蛇行鼠窜"+NOR+"」，左拳上格，右手探底突出，抓向$n的裆部",
    "force" : 200,
    "lvl" : 89,
    "skill_name" : BLK "蛇行鼠窜" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N一式「"+GRN+"蛇磐青竹"+NOR+"」，十指伸缩，虚虚实实地袭向$n的全身要穴",
    "force" : 310,
    "lvl" : 100,
    "skill_name" : GRN "蛇磐青竹" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N双手抱拳，一式「"+YEL+"万蛇汹涌"+NOR+"」，掌影翻飞，同时向$n施出九九八十一招",
    "force" : 380,
    "lvl" : 120,
    "skill_name" : YEL "万蛇汹涌" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N一式「"+WHT+"白蛇吐信"+NOR+"」，拳招若隐若现，若有若无，急急地拍向$n的丹田",
    "force" : 460,
    "lvl" : 140,
    "skill_name" : WHT "白蛇吐信" NOR,
        "damage_type" : "内伤"
]),
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 140;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练蛇形刁手必须空手。\n");
    if ((int)me->query_skill("hamagong", 1) < 20)
        return notify_fail("你的蛤蟆功火候不够，无法学蛇形刁手。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练蛇形刁手。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("shexing-diaoshou", 1))
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
    level   = (int) me->query_skill("shexing-diaoshou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练蛇形刁手必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练蛇形刁手。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
