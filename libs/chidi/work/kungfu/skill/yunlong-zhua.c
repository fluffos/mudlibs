// yunlong-zhua.c -云龙爪
inherit SKILL;
mapping *action = ({
([  "action" : "$N全身拔地而起，半空中一个筋斗，一式「"+YEL+"凶鹰袭兔"+NOR+"」，迅猛地抓向$n的$l",
    "force" : 150,
    "lvl" : 0,
    "skills_name" : YEL "凶鹰袭兔" NOR,
    "damage_type" : "抓伤"
]),
([  "action" : "$N单腿直立，双臂平伸，一式「"+RED+"雄鹰展翅"+NOR+"」，双爪一前一后拢向$n的$l",
    "force" : 220,
    "lvl" : 10,
    "skills_name" : RED "雄鹰展翅" NOR,
        "damage_type" : "抓伤"
]),
([  "action" : "$N一式「"+MAG+"拔翅鹰飞"+NOR+"」，全身向斜里平飞，右腿一绷，双爪搭向$n的肩头",
    "force" : 250,
    "lvl" : 20,
    "skills_name" : MAG "拔翅鹰飞" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N双爪交错上举，使一式「"+WHT+"迎风振翼"+NOR+"」，一拔身，分别袭向$n左右腋空门",
    "force" : 290,
    "lvl" : 30,
    "skills_name" : WHT "迎风振翼" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N全身滚动上前，一式「"+CYN+"飞龙献爪"+NOR+"」，右爪突出，鬼魅般抓向$n的胸口",
    "force" : 350,
    "lvl" : 40,
    "skills_name" : CYN "飞龙献爪" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N伏地滑行，一式「"+HIB+"顶天立地"+NOR+"」，上手袭向膻中大穴，下手反抓$n的裆部",
    "force" : 350,
    "lvl" : 50,
    "skills_name" : HIB "顶天立地" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N左右手掌爪互逆，一式「"+GRN+"搏击长空"+NOR+"」，无数道劲气破空而出，迅疾无比地击向$n",
    "force" : 380,
    "lvl" : 60,
    "skills_name" : GRN "搏击长空" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N腾空高飞三丈，一式「"+HIB+"鹰扬万里"+NOR+"」，天空中顿时显出一个巨灵爪影，缓缓罩向$n",
    "force" : 430,
    "lvl" : 60,
    "skills_name" : HIB "鹰扬万里" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N忽的拨地而起，使一式「"+MAG+"苍龙出水"+NOR+"」，身形化作一道闪电射向$n",
    "force" : 470,
    "lvl" : 70,
    "skills_name" : MAG "苍龙出水" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N微微一笑，使一式「"+YEL+"万佛朝宗"+NOR+"」，双手幻出万道金光,直射向$n的$l",
    "force" : 470,
    "lvl" : 80,
    "skills_name" : YEL "万佛朝宗" NOR,
        "damage_type" : "内伤"
])
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 80;  }
int valid_combine(string combo) { return combo=="yunlong-shou"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练云龙爪必须空手。\n");
    if ((int)me->query_skill("yunlong-shengong", 1) < 50)
        return notify_fail("你的云龙神功火候不够，无法学云龙爪。\n");
    if ((int)me->query_skill("force", 1) < 50)
        return notify_fail("你的基本内功火候不够，无法学云龙爪。\n");
    if ((int)me->query("max_neili") < 350)
        return notify_fail("你的内力太弱，无法练云龙爪。\n");
    if ((int)me->query_skill("unarmed",1) <40)
        return notify_fail("你的基本爪法火候不够，无法学云龙爪。\n");
    if (2*(int)me->query_skill("yunlong-xinfa",1) <(int)me->query_skill("yunlong-zhua",1))
        return notify_fail("你的云龙爪法火候不够，无法继续学云龙爪。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("yunlong-zhua", 1))
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
    level   = (int) me->query_skill("yunlong-zhua",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练云龙爪必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练云龙爪。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if(me->query_skill("yunlong-shengong") > 70 ) {
        if( random(me->query_skill("yunlong-zhua")) > 30 ) {
            victim->apply_condition("zhua_poison", random(me->query_skill("ningxue-shenzhua")/10) + 1 +
            victim->query_condition("zhua_poison"));
    }
    }
}
string perform_action_file(string action)
{
    return __DIR__"yunlong-zhua/" + action;
}
