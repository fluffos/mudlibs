// qiufeng-chenfa.c 秋风拂尘
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([  "action":       "$N端坐不动，一招「"+YEL+"秋风拂叶"+NOR+"」，手中$w带着一股劲风，击向$n的脸颊",
    "lvl" : 0,
    "skill_name" : YEL "秋风拂叶" NOR,
    "damage_type":  "刮伤"
]),
([  "action":       "$N单臂一挥，一招「"+RED+"玉带围腰"+NOR+"」，手中$w直绕向$n的身后",
    "lvl" : 14,
    "skill_name" : RED "玉带围腰" NOR,
    "damage_type":  "内伤"
]),
([  "action":       "$N身形一转，一招「"+BLK+"流云断川"+NOR+"」，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
    "lvl" : 38,
    "skill_name" : BLK "流云断川" NOR,
    "damage_type":  "劈伤"
]),
([  "action":       "$N力贯尘梢，一招「"+MAG+"春风化雨"+NOR+"」，手中$w舞出满天幻影，排山倒海般扫向$n全身",
    "lvl" : 60,
    "skill_name" : MAG "春风化雨" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N忽的向前一跃，一招「"+GRN+"野马分鬃"+NOR+"」，手中$w分击$n左右",
    "lvl" : 82,
    "skill_name" : GRN "野马分鬃" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N慢步上前，一招「"+HIR+"竹影扫阶"+NOR+"」，手中$w缓缓罩向$n前胸",
    "lvl" : 114,
    "skill_name" : HIR "竹影扫阶" NOR,
    "damage_type":  "内伤"
])
});
int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int practice_level(){   return 120;  }
int valid_learn(object me)
{
    object weapon;
    if( (int)me->query("max_neili") < 300 )
        return notify_fail("你的内力不足，没有办法练秋风尘法, 多练些内力再来吧。\n");
    if ((int)me->query_skill("force", 1) < 50)
        return notify_fail("你的基本气功火候太浅。\n");
    if ( !objectp(weapon = me->query_temp("weapon"))
    || ( string)weapon->query("skill_type") != "whip" )
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "whip")
        return notify_fail("你必须先找一条拂尘才能练尘法。\n");
    if (me->query_skill("whip", 1) <=me->query_skill("qiufeng-chenfa", 1))
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
    level   = (int) me->query_skill("qiufeng-chenfa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*2;
    a_action["attack"]  = level;
    a_action["damage"] = level/2;
    return a_action;

}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "whip")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "whip")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练秋风尘法。\n");
    me->receive_damage("qi", 35);
    return 1;
}
string perform_action_file(string action)
{
    if ( this_player()->query_skill("qiufeng-chenfa", 1) >= 40 )
        return __DIR__"qiufeng-chenfa/" + action;
}
