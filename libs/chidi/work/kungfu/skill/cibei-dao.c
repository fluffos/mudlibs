// cibei-dao.c 慈悲刀
inherit SKILL;
mapping *action = ({
([  "action" : "$N手中$w斜指，一招「"+YEL+"停车问路"+NOR+"」，反身一顿，一刀向$n的$l撩去",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : YEL "停车问路" NOR, 
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+BLU+"童子挂画"+NOR+"」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
    "force" : 130,
    "lvl" : 8,
    "skill_name" : BLU "童子挂画" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N展身虚步，提腰跃落，一招「"+WHT+"推窗望月"+NOR+"」，刀锋一卷，拦腰斩向$n",
    "force" : 140,
    "lvl" : 16,
    "skill_name" : WHT "推窗望月" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+HIM+"开门见山"+NOR+"」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
    "force" : 160,
    "lvl" : 24,
    "skill_name" : HIM "开门见山" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N手中$w一沉，一招「"+HIY+"临溪观鱼"+NOR+"」，双手持刃拦腰反切，砍向$n的胸口",
    "force" : 180,
    "lvl" : 33,
    "skill_name" : HIY "临溪观鱼" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N挥舞$w，使出一招「"+YEL+"张弓望地"+NOR+"」，上劈下撩，左挡右开，齐齐罩向$n",
    "force" : 210,
    "lvl" : 42,
    "skill_name" : YEL "张弓望的" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+RED+"风送轻舟"+NOR+"」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
    "force" : 240,
    "lvl" : 51,
    "skill_name" : RED "风送轻舟" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N盘身驻地，一招「"+BLU+"川流不息"+NOR+"」，挥出一片流光般的刀影，向$n的全身涌去",
    "force" : 280,
    "lvl" : 60,
    "skill_name" : BLU "停车问路" NOR,
    "damage_type" : "割伤"
]),
});
int practice_level(){   return 60;  }
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_combine(string combo) { return combo=="fumo-jian"; }
int valid_learn(object me)
{
    object weapon;
    if ( !objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if ( !objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你必须先找把刀才能学慈悲刀。\n");

    if ((int)me->query("max_neili") < 150)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学慈悲刀。\n");

    if (me->query_skill("blade", 1) <=me->query_skill("cibei-dao", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    else
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
    level   = (int) me->query_skill("cibei-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                        break;
                   }
    a_action["dodge"]  = 0-me->query_skill("cibei-dao",1)/2;
    a_action["damage"] = me->query_skill("cibei-dao",1);
    a_action["damage"] = me->query_skill("cibei-dao")/3;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if ( !objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if ( !objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练慈悲刀。\n");
    me->receive_damage("qi", 25);
    return 1;
}
