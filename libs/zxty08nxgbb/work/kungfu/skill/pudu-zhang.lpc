// pudu-zhang.c 普渡杖法
inherit SKILL;
mapping *action = ({
([  "action":"$N使一招「"+YEL+"黄牛转角"+NOR+"」，手中$w自下而上，沉猛无比地向$n的小腹挑去。",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : YEL "黄牛转角" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N快步跨出，一招「"+RED+"野马追风"+NOR+"」，左手平托$w，右掌猛推杖端，顶向$n的胸口。",
    "force" : 200,
    "lvl" : 12,
    "skill_name" : RED "野马追风" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N高举$w，一招「"+BLK+"猛虎跳涧"+NOR+"」，全身跃起，手中$w搂头盖顶地向$n击去。",
    "force" : 230,
    "lvl" : 23,
    "skill_name" : BLK "猛虎跳涧" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N一招「"+HIY+"狮子摇头"+NOR+"」，双手持杖如橹，对准$n猛地一搅，如同平地刮起一阵旋风。",
    "force" : 270,
    "lvl" : 36,
    "skill_name" : HIY "狮子摇头" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N横持$w，一招「"+WHT+"苍龙摆尾"+NOR+"」，杖端化出无数个圆圈，凝滞沉重，把$n缠在其中。",
    "force" : 320,
    "lvl" : 48,
    "skill_name" : WHT "苍龙摆尾" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N全身滚倒，$w盘地横飞，突出一招「"+HIC+"大蟒翻身"+NOR+"」，杖影把$n裹了起来",
    "force" : 380,
    "lvl" : 60,
    "skill_name" : HIC "大蟒翻身" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N双手和十，躬身一招「"+GRN+"胡僧托钵"+NOR+"」，$w自肘弯飞出，拦腰向$n撞去。",
    "force" : 450,
    "lvl" : 72,
    "skill_name" : GRN "胡僧托钵" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N一招「"+RED+"慈"+YEL+"航"+MAG+"普"+BLU+"渡"+NOR+"」，$w如飞龙般自掌中跃出，直向$n的胸口穿入。",
    "force" : 530,
    "lvl" : 80,
    "skill_name" : MAG "慈航普渡" NOR,
    "damage_type":"挫伤"
]),
});
int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
int practice_level(){   return 90;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("staff", 1) <=me->query_skill("pudu-zhang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学普渡杖法。\n");
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
    level   = (int) me->query_skill("pudu-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level/3;
    return a_action;

}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练普渡杖法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
