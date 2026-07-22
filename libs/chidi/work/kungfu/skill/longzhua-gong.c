// longzhua-gong.c -龙爪功
inherit SKILL;
mapping *action = ({
([  "action" : "在呼呼风声中，$N使一招「"+YEL+"捕风式"+NOR+"」，双手如钩如戢，插向$n的$l",
    "force" : 100,
    "lvl"   : 0,
    "skill_name" : YEL "捕风式" NOR ,       
    "damage_type" : "内伤"
]),
([  "action" : "$N猛地向前跃出，一招「"+RED+"捉影式"+NOR+"」，两腿踢出，双手抓向$n的面门",
    "force" : 110,
    "lvl"   : 6,
    "skill_name" : RED "捉影式" NOR ,       
    "damage_type" : "内伤"
]),
([  "action" : "$N双手平伸，十指微微上下抖动，一招「"+MAG+"抚琴式"+NOR+"」打向$n的$l",
    "force" : 120,
    "lvl"   : 12,
    "skill_name" : MAG "抚琴式" NOR ,       
    "damage_type" : "内伤"
]),
([  "action" : "$N左手上拦，右手内挥，一招「"+WHT+"击鼓式"+NOR+"」击向$n胸口",
    "force" : 140,
    "lvl"   : 18,
    "skill_name" : WHT "击鼓式" NOR ,       
    "damage_type" : "内伤"
]),
([  "action" : "$N右手虚握，左手掌立如山，一招「批亢式」，猛地击向$n的$l",
    "force" : 160,
    "lvl"   : 24,
    "skill_name" : "批亢式" ,       
    "damage_type" : "内伤"
]),
([  "action" : "$N腾步上前，左手护胸，右手探出，一招「掏虚式」击向$n的裆部",
    "force" : 190,
    "lvl"   : 30,
    "skill_name" : "掏虚式" ,       
    "damage_type" : "内伤"
]),
([  "action" : "$N双手平提胸前，左手护住面门，一招「抱残式」右手推向$n的$l",
    "force" : 220,
    "lvl"   : 35,
    "skill_name" : "抱残式" ,       
    "damage_type" : "内伤"
]),
([  "action" : "$N两手胸前环抱，腋下含空，五指如钩，一招「"+RED+"守缺式"+NOR+"」插向$n的顶门",
    "force" : 260,
    "lvl"   : 40,
    "skill_name" : RED "守缺式" NOR ,       
    "damage_type" : "内伤"
]),
([  "action" : "$N右腿斜插$n二腿之间，一招「"+YEL+"抢珠式"+NOR+"」，上手取目，下手反勾$n的裆部",
    "force" : 300,
    "lvl"   : 45,
    "skill_name" : YEL "抢珠式" NOR ,       
    "damage_type" : "内伤"
]),
([  "action" : "$N一手虚指$n的剑诀，一招「"+HIC+"夺剑式"+NOR+"」，一手劈空抓向$n",
    "force" : 350,
    "lvl"   : 50,
    "skill_name" : HIC "夺剑式" NOR ,       
    "damage_type" : "内伤"
]),
([  "action" : "$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招「"+HIW+"拿云式"+NOR+"」使$n进退两难",
    "force" : 400,
    "lvl"   : 55,
    "skill_name" : HIW "拿云式" NOR ,       
    "damage_type" : "内伤"
]),
([  "action" : "$N前脚着地，一手顶天成爪，一手指地，一招「"+RED+"追"+HIW+"日"+RED+"式"+NOR+"」劲气笼罩$n的全身",
    "force" : 460,
    "lvl"   : 60,
    "skill_name" : RED "追日式" NOR ,       
    "damage_type" : "内伤"
])
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="qianye-shou"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练龙爪功必须空手。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练龙爪功。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("longzhua-gong", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");

    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学龙爪功。\n");

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
    level   = (int) me->query_skill("longzhua-gong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["damage"] = level;
    return a_action;

}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练龙爪功必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练龙爪功。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
