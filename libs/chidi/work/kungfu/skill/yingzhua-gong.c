// yingzhua-gong.c -鹰爪功
inherit SKILL;
mapping *action = ({
([  "action" : "$N全身拔地而起，半空中一个筋斗，一式「"+YEL+"凶鹰袭兔"+NOR+"」，迅猛地抓向$n的$l",
    "force" : 100,
    "lvl" : 0,
    "skills_name" : YEL "凶鹰袭兔" NOR,
    "damage_type" : "内伤"
]),
([  "action" : "$N单腿直立，双臂平伸，一式「"+HIY+"雄鹰展翅"+NOR+"」，双爪一前一后拢向$n的$l",
    "force" : 120,
    "lvl" : 10,
    "skills_name" : HIY "雄鹰展翅" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N一式「"+HIB+"拔翅横飞"+NOR+"」，全身向斜里平飞，右腿一绷，双爪搭向$n的肩头",
    "force" : 150,
    "lvl" : 20,
    "skills_name" : HIB "拔翅横飞" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N双爪交错上举，使一式「"+MAG+"迎风振翼"+NOR+"」，一拔身，分别袭向$n左右腋空门",
    "force" : 190,
    "lvl" : 30,
    "skills_name" : MAG "迎风振翼" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N全身滚动上前，一式「"+YEL+"飞龙献爪"+NOR+"」，右爪突出，鬼魅般抓向$n的胸口",
    "force" : 250,
    "lvl" : 40,
    "skills_name" : YEL "飞龙献爪" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N伏地滑行，一式「"+HIW+"拨云瞻日"+NOR+"」，上手袭向膻中大穴，下手反抓$n的裆部",
    "force" : 310,
    "lvl" : 50,
    "skills_name" : HIW "拨云瞻日" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N左右手掌爪互逆，一式「"+YEL+"搏击长空"+NOR+"」，无数道劲气破空而出，迅疾无比地击向$n",
    "force" : 380,
    "lvl" : 55,
    "skills_name" : YEL "凶鹰袭兔" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N腾空高飞三丈，一式「"+HIG+"鹰扬万里"+NOR+"」，天空中顿时显出一个巨灵爪影，缓缓罩向$n",
    "force" : 470,
    "lvl" : 60,
    "skills_name" : HIG "凶鹰袭兔" NOR,
        "damage_type" : "内伤"
])
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="fengyun-shou"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练鹰爪功必须空手。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练鹰爪功。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("yingzhua-gong", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学鹰爪功。\n");
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
        level   = (int) me->query_skill("yingzhua-gong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level*2;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练鹰爪功必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练鹰爪功。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
