// fumo-jian.c -伏魔剑
inherit SKILL;
mapping *action = ({
([  "action" : "$N一式「"+HIW+"穿云势"+NOR+"」，剑锋平指，剑势如风，一气呵成横扫$n的腰间",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : HIW "穿云势" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N向前跃上一步，左手剑诀，右手$w使出一式「"+MAG+"破雾势"+NOR+"」直刺$n的$l",
    "force" : 140,
    "lvl" : 10,
    "skill_name" : MAG "破雾势" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N拔步挺腰，一式「"+YEL+"推山势"+NOR+"」，手中$w沉滞无比，缓缓挥剑撞向$n的$l",
    "force" : 170,
    "lvl" : 20,
    "skill_name" : YEL "推山势" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一式「"+BLU+"搅海势"+NOR+"」，$w自左而右划出一个大弧，平平地向$n的$l挥去",
    "force" : 190,
    "lvl" : 30,
    "skill_name" : BLU "搅海势" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱成圆，一式「"+BLU+"开天势"+NOR+"」，$w中宫直进，刺向$n的胸口",
    "force" : 240,
    "lvl" : 40,
    "skill_name" : BLU "开天势" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一式「"+YEL+"劈地势"+NOR+"」，$w从上至下猛劈，剑锋直出，挟爆裂之声骤然斩向$n的$l",
    "force" : 280,
    "lvl" : 49,
    "skill_name" : YEL "劈地势" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N运气施出「"+RED+"雷针势"+NOR+"」，$w剑尖逼出一道青芒，闪电般破空射向$n的$l",
    "force" : 350,
    "lvl" : 57,
    "skill_name" : RED "雷针势" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N双腿半屈半蹲，一式「"+BLK+"龙吞势"+NOR+"」，剑尖划出无数圆圈，狂风骤起，笼罩天地",
    "force" : 400,
    "lvl" : 64,
    "skill_name" : BLK "龙吞势" NOR,
    "damage_type" : "刺伤"
]),
});
int practice_level(){   return 64;  }
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_combine(string combo) { return combo=="cibei-dao"; }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你必须先找把剑来才能学伏魔剑。\n");

    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学伏魔剑。\n");

    if (me->query_skill("sword", 1) <=me->query_skill("fumo-jian", 1))
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
    level   = (int) me->query_skill("fumo-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练伏魔剑。\n");
    me->receive_damage("qi", 35);
    return 1;
}

