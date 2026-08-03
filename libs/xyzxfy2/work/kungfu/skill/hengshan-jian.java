// hengshan-jian.c 恒山剑法
// Made by deaner
// Modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N虚步提腰，一招"+HIC"『朴实无华』"NOR+"，剑招看似平淡却暗含
后着，
手中$w点向$n的$l",
    "force" : 120,
    "dodge" : 40,
    "damage" : 30,
    "damage_type" : "刺伤",
    "lvl" : 0,
    "skill_name" : "朴实无华"
]),
([  "action" : "$N使出一式"+HIC"『开门见山』"NOR+"，挥舞$w直刺$n的$l",      
    "force" : 140,
    "dodge" : 35,
    "damage" : 35,
    "damage_type" : "刺伤",
    "lvl" : 12,
    "skill_name" : "开门见山"
]),
([  "action" : "$N祭出一招"+HIC"『弹剑有音』"NOR+"，手里$w剑光暴长，已罩向$n
的$l",
    "force" : 150,
    "dodge" : 20,
    "damage" : 45,
    "damage_type" : "刺伤",
    "lvl" : 19,
    "skill_name" : "弹剑有音"
]),
([  "action" : "$N双手握剑，一招"+WHT"『远离尘埃』"NOR+"，$w看似随意地划向$n
的$l",
    "force" : 175,
    "dodge" : 25,
    "damage" : 55,
    "damage_type" : "割伤",
    "lvl" : 20,
    "skill_name" : "远离尘埃"
]),
([  "action" : "$N施展出"+HIW"『菩提明净』"NOR+"，左手合什微喧佛号，右手$w如游龙般
击向$n的$l",
    "force" : 200,
    "dodge" : 25,
    "damage" : 65,
    "damage_type" : "刺伤",
    "lvl" : 27,
    "skill_name" : "菩提明净"
]),
([  "action" : "$N凝神使出"+HIW"『心净如泓』"NOR+"，$w在胸前飞舞数圈后化为白泓点向
$n的$l",
    "force" : 225,
    "dodge" : 35,
    "damage" : 85,
    "damage_type" : "刺伤",
    "lvl" : 35,
    "skill_name" : "心净如泓"
]),
([  "action" : "$N双足一点，一招"+MAG"『心魔缠身』"NOR+"，鬼魅般欺至$n面前，$w带着
一道飞芒逼向$n的$l",
    "force" : 250,
    "dodge" : 5,
    "damage" : 115,
    "damage_type" : "刺伤",
    "lvl" : 44,
    "skill_name" : "心魔缠身"
]),
([  "action" : "$N原地一转，使出"+HIM"『恶魔附体』"NOR+"，$n却见四面八方皆是$N，无
数把$w闪烁不定刺向自己的$l",
    "force" : 300,
    "dodge" : 55,
    "damage" : 145,
    "damage_type" : "刺伤",
    "lvl" : 53,
    "skill_name" : "恶魔附体"
]),
([  "action" : "$N飞身跃起，祭出"+HIR"『万劫不复』"NOR+"，$w发出一声龙吟从半空中洒向
$n的$l",
    "force" : 350,
    "dodge" : 35,
    "damage" : 175,
    "damage_type" : "刺伤",
    "lvl" : 62,
    "skill_name" : "万劫不复"
]),
([  "action" : "$N右手微微一震，一招"+HIB"『缩地三尺』"NOR+"，快速绝伦地揉身而上，
手中$w飘忽不定地洒向$n的$l",
    "force" : 400,
    "dodge" : 45,
    "damage" : 200,
    "damage_type" : "刺伤",
    "lvl" : 71,
    "skill_name" : "缩地三尺"
]),
([  "action" : "$N神色平和地微微低首，一招"+YEL"『仙风道骨』"NOR+"，$w剑尖游移不
定地刺向$n的$l",
    "force" : 450,
    "dodge" : 20,
    "damage" : 250,
    "damage_type" : "刺伤",
    "lvl" : 80,
    "skill_name" : "仙风道骨"
]),
([  "action" : "$N双手和什，使出一招"+HIY"『仙降于世』"NOR+"，$w平平地飞出刺向$n
的$l",
    "force" : 500,
    "dodge" : 35,
    "damage" : 300,
    "damage_type" : "刺伤",
    "lvl" : 90,
    "skill_name" : "仙降于世"
]),
([  "action" : "$N面露微笑，一招"+HIY"『普渡众生』"NOR+"，$w一闪间舞出无数团剑花
刺向$n的$l",
    "force" : 550,
    "dodge" : 25,
    "damage" : 350,
    "damage_type" : "刺伤",
    "lvl" : 100,
    "skill_name" : "普渡众生"
])
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail(HIC"你的内力不够。\n"NOR);
    if ((int)me->query_skill("lingyuan-xinfa", 1) < 10)
   return notify_fail(HIC"你的灵元心法火候太浅。\n"NOR);
    if ((string)me->query("gender") != "女性" )
   return notify_fail(HIY"这种阴柔的剑法只有女子才适合学。\n"NOR);
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("hengshan-jian",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
   return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("你的体力不够练恒山剑法。\n");
    me->receive_damage("qi", 30);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"hengshan-jian/" + action;
}

