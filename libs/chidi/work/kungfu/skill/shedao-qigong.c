// shedao-qigong  蛇岛奇功
inherit SKILL;
mapping *action = ({
([  "action" : "$N使一招「"+HIC+"仙鹤梳翎"+NOR+"」手中$w一提，插向$n的$l",
    "force": 150,
    "damage_type" : "挫伤",
    "skill_name" : HIC "仙鹤梳翎" NOR,
]),
([  "action": "$N使出「"+HIY+"灵蛇出洞"+NOR+"」，身形微弓,手中$w倏的向$n的$l戳去",
    "force": 250,
    "damage_type": "刺伤",
    "skill_name" : HIY "灵蛇出洞" NOR,
]),
([  "action": "$N身子微曲,左足反踢,乘势转身,使一招「"+HIM+"贵妃回眸"+NOR+"」，右手$w已戳向$n$l",
    "force": 250,
    "damage_type": "刺伤",
    "skill_name" : HIM "贵妃回眸" NOR,
]),
([  "action" : "$N使一式「"+HIY+"飞燕回翔"+NOR+"」，背对着$n, 右足一勾,顺势在$w上一点,$w陡然向自己咽喉疾射.接着$N身子往下一缩,$w掠过其咽喉,急奔$n急射而来",
    "lvl" : 40,
    "damage_type" : "刺伤",
    "skill_name" : HIY "飞燕回翔" NOR,
]),
([  "action": "$N忽的在地上一个筋斗,使一招「"+HIW+"小怜横陈"+NOR+"」,从$n胯下钻过,手中$w直击$n",
    "force": 350,
    "damage_type": "刺伤",
    "skill_name" : HIW "小怜横陈" NOR,
]),
([  "action": "$N大吼一声，使一招「"+HIR+"子胥举鼎"+NOR+"」，反手擒拿$n极泉要穴,欲将$n摔倒在地",
    "force": 400,
    "damage_type": "内伤",
    "skill_name" : HIR "子胥举鼎" NOR,
]),
([  "action": "$N双腿一缩,似欲跪拜,一招「"+HIB+"鲁达拨柳"+NOR+"」左手抓向$n右脚足踝,右手$w直击$n小腹",
    "force": 400,
    "damage_type": "内伤",
    "skill_name" : HIB "鲁达拨柳" NOR,
]),
([  "action": "$N突然一个倒翻筋斗,一招「"+HIC+"狄青降龙"+NOR+"」,双腿一分,跨在肩头,双掌直击$n",
    "force": 400,
    "damage_type": "内伤",
    "skill_name" : HIC "狄青降龙" NOR,
]),
});
int valid_enable(string usage) { return usage=="sword"|| usage=="staff"|| usage=="parry"; }
int practice_level(){   return 100;  }
int valid_learn(object me)
{
    object weapon;
    if (objectp(weapon = me->query_temp("weapon")))
    if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
    if (objectp(weapon = me->query_temp("secondary_weapon")))
    if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if (me->query_skill("sword", 1) <=me->query_skill("shedao-qigong", 1)
        && me->query_skill("staff", 1) <=me->query_skill("shedao-qigong", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("shenlong-xinfa", 1) < 50)
        return notify_fail("你的神龙心法火候不够，无法学蛇岛奇功.\n");
    if ((int)me->query_skill("force", 1) < 50)
        return notify_fail("你的基本内功火候不够，无法学蛇岛奇功。\n");
    if ((int)me->query_skill("shenlong-bashi", 1) < 50)
        return notify_fail("你的神龙八式火候不够，无法学蛇岛奇功。\n");
    if ((int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shedao-qigong",1))
        return notify_fail("你的神龙心法火候不够，无法继续学蛇岛奇功。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int level;
    level   = (int) me->query_skill("shedao-qigong", 1);
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = 0-level*3;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level*2;
    a_action["damage"] = level*3;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (objectp(weapon = me->query_temp("weapon")))
    if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
    if (objectp(weapon = me->query_temp("secondary_weapon")))
    if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 30)
        return notify_fail("你的内力不够练蛇岛奇功。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"shedao-qigong/" + action;
}
