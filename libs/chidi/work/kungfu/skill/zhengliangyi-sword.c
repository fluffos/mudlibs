// zhengliangyi-sword 正两仪剑法
inherit SKILL;
mapping *action = ({
([  "action":"\n$N使一式「"+YEL+"百丈飞瀑"+NOR+"」，手中$w剑峰从半空直泻下来刺向$n的$l",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : YEL "百丈飞瀑" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"\n$N错步上前，使出「"+MAG+"雨打飞花"+NOR+"」，走的全是斜势，使你极难捉摸，$w淡淡地向$n的$l挥去",
    "force" : 140,
    "lvl" : 8,
    "skill_name" : MAG "雨打飞花" NOR,
    "damage_type":  "割伤"
]),
([  "action":"\n$N一式「"+WHT+"木叶萧萧"+NOR+"」，手腕一抖，剑光暴涨，手中$w遥摇指向$n的$l",
    "force" : 160,
    "lvl" : 15,
    "skill_name" : WHT "木叶萧萧" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N纵身轻轻跃起，一式「"+HIR+"大漠平沙"+NOR+"」，身形一欺，手中$w狭雷霆之威，罩身攻向$n全身",
    "force" : 180,
    "lvl" : 20,
    "skill_name" : HIR "大漠平沙" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N手中$w中宫直进，一式「"+BLU+"寒梅剑阵"+NOR+"」，$w斗然弯弯弹出，剑尖以不可思议的速度直刺向$n的$l",
    "force" : 220,
    "lvl" : 30,
    "skill_name" : BLU "寒梅剑阵" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N手中$w一沉，一式「"+HIB+"同气连枝"+NOR+"」，剑光如幻，劲风撕空，滑向$n的$l",
    "force" : 250,
    "lvl" : 40,
    "skill_name" : HIB "同气连枝" NOR,
    "damage_type":  "割伤"
]),
([  "action":"\n$N，一式「"+WHT+"无声无色"+NOR+"」，银光万道，如江河倒泻，剑芒绵绵无尽向$n的$l击出",
    "force" : 280,
    "lvl" : 50,
    "skill_name" : WHT "无声无色" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「"+RED+"万里一点红"+NOR+"」刺向$n的$l",
    "force" : 320,
    "lvl" : 60,
    "skill_name" : RED "万里一点红" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N，一式「"+HIM+"崤壁断云"+NOR+"」，凌空跃起空中回身反剑,$w射向$n的$l",
    "force" : 380,
    "lvl" : 70,
    "skill_name" : HIM "崤壁断云" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"\n$N呼的一声拔地而起，一式「"+HIG+"普天甘露"+NOR+"」，剑出如风，剑影如山罩向$n",
    "force" : 420,
    "lvl" : 110,
    "skill_name" : HIG "日月与同辉" NOR,
    "damage_type":  "内伤"
]),
([  "action":"$N随风轻轻飘落，一式「"+GRN+"玉碎昆冈"+NOR+"」，势如骇电奔雷，招里藏招，式里藏式，使$n手忙脚乱",
    "force" : 450,
    "lvl" : 150,
    "skill_name" : GRN "玉碎昆冈" NOR,
    "damage_type":  "内伤"
]),
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 150;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你必须先找把剑才能学剑法。\n");

    if (me->query_skill("sword", 1) <=me->query_skill("zhengliangyi-sword", 1))
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
    level   = (int) me->query_skill("zhengliangyi-sword",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level*2;
    a_action["attack"]  = level/2;
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
        return notify_fail("你的体力不够练正两仪剑法。\n");
    me->receive_damage("qi", 25);
    return 1;
}
