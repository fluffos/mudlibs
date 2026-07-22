// weituo-gun.c -韦陀棍
inherit SKILL;
mapping *action = ({
([  "action":"$N一招「"+YEL+"黄石纳履"+NOR+"」，手中$w如蜻蜓点水般，招招向$n的下盘要害点去",
    "force" : 160,
    "lvl" : 0,
    "skill_name" : YEL "黄石纳履" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N把$w平提胸口，一拧身，一招「"+WHT+"勒马停锋"+NOR+"」，$w猛地撩向$n的颈部",
    "force" : 180,
    "lvl" : 8,
    "skill_name" : WHT "勒马停锋" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N一招「"+HIM+"平地龙飞"+NOR+"」，全身滴溜溜地在地上打个大转，举棍向$n的胸腹间戳去",
    "force" : 210,
    "lvl" : 16,
    "skill_name" : HIM "平地龙飞" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N伏地一个滚翻，一招「"+HIM+"伏虎听风"+NOR+"」，$w挟呼呼风声迅猛扫向$n的足胫",
    "force" : 250,
    "lvl" : 25,
    "skill_name" : HIM "伏虎听风" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N一招「"+HIW+"流星赶月"+NOR+"」，身棍合一，棍端逼成一条直线，流星般向顶向$n的$l",
    "force" : 300,
    "lvl" : 35,
    "skill_name" : HIW "流星赶月" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N双手持棍划了个天地大圈，一招「"+RED+"红霞贯"+HIW+"日"+NOR+"」，一棍从圆心正中击出，撞向$n的胸口",
    "force" : 350,
    "lvl" : 44,
    "skill_name" : RED "红霞贯日" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N一招「"+MAG+"投鞭断流"+NOR+"」，$w高举，以雷霆万钧之势对准$n的天灵当头劈下",
    "force" : 410,
    "lvl" : 52,
    "skill_name" : MAG "投鞭断流" NOR,
    "damage_type":"挫伤"
]),
([  "action":"$N潜运真力，一招「"+HIC+"苍龙归海"+NOR+"」，$w顿时长了数丈，矫龙般直射$n的胸口",
    "force" : 470,
    "lvl" : 60,
    "skill_name" : HIC "苍龙归海" NOR,
    "damage_type":"挫伤"
]),
});
int valid_enable(string usage) { return  (usage == "club") || (usage == "parry"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("club", 1) <=me->query_skill("weituo-gun", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学韦陀棍。\n");
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
        level   = (int) me->query_skill("weituo-gun",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level;
    a_action["damage"] = level/2;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "club")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练韦陀棍。\n");
    me->receive_damage("qi", 25);
    return 1;
}
