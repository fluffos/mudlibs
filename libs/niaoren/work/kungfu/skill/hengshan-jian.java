// hengshan-jian.c 恆山劍法
// Made by deaner
// Modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N虛步提腰，一招"+HIC"『朴實無華』"NOR+"，劍招看似平淡卻暗含
后著，
手中$w點向$n的$l",
    "force" : 120,
    "dodge" : 40,
    "damage" : 30,
    "damage_type" : "刺傷",
    "lvl" : 0,
    "skill_name" : "朴實無華"
]),
([  "action" : "$N使出一式"+HIC"『開門見山』"NOR+"，揮舞$w直刺$n的$l",      
    "force" : 140,
    "dodge" : 35,
    "damage" : 35,
    "damage_type" : "刺傷",
    "lvl" : 12,
    "skill_name" : "開門見山"
]),
([  "action" : "$N祭出一招"+HIC"『彈劍有音』"NOR+"，手里$w劍光暴長，已罩向$n
的$l",
    "force" : 150,
    "dodge" : 20,
    "damage" : 45,
    "damage_type" : "刺傷",
    "lvl" : 19,
    "skill_name" : "彈劍有音"
]),
([  "action" : "$N雙手握劍，一招"+WHT"『遠離塵埃』"NOR+"，$w看似隨意地划向$n
的$l",
    "force" : 175,
    "dodge" : 25,
    "damage" : 55,
    "damage_type" : "割傷",
    "lvl" : 20,
    "skill_name" : "遠離塵埃"
]),
([  "action" : "$N施展出"+HIW"『菩提明淨』"NOR+"，左手合什微喧佛號，右手$w如游龍般
擊向$n的$l",
    "force" : 200,
    "dodge" : 25,
    "damage" : 65,
    "damage_type" : "刺傷",
    "lvl" : 27,
    "skill_name" : "菩提明淨"
]),
([  "action" : "$N凝神使出"+HIW"『心淨如泓』"NOR+"，$w在胸前飛舞數圈后化為白泓點向
$n的$l",
    "force" : 225,
    "dodge" : 35,
    "damage" : 85,
    "damage_type" : "刺傷",
    "lvl" : 35,
    "skill_name" : "心淨如泓"
]),
([  "action" : "$N雙足一點，一招"+MAG"『心魔纏身』"NOR+"，鬼魅般欺至$n面前，$w帶著
一道飛芒逼向$n的$l",
    "force" : 250,
    "dodge" : 5,
    "damage" : 115,
    "damage_type" : "刺傷",
    "lvl" : 44,
    "skill_name" : "心魔纏身"
]),
([  "action" : "$N原地一轉，使出"+HIM"『惡魔附體』"NOR+"，$n卻見四面八方皆是$N，無
數把$w閃爍不定刺向自己的$l",
    "force" : 300,
    "dodge" : 55,
    "damage" : 145,
    "damage_type" : "刺傷",
    "lvl" : 53,
    "skill_name" : "惡魔附體"
]),
([  "action" : "$N飛身躍起，祭出"+HIR"『萬劫不復』"NOR+"，$w發出一聲龍吟從半空中洒向
$n的$l",
    "force" : 350,
    "dodge" : 35,
    "damage" : 175,
    "damage_type" : "刺傷",
    "lvl" : 62,
    "skill_name" : "萬劫不復"
]),
([  "action" : "$N右手微微一震，一招"+HIB"『縮地三尺』"NOR+"，快速絕倫地揉身而上，
手中$w飄忽不定地洒向$n的$l",
    "force" : 400,
    "dodge" : 45,
    "damage" : 200,
    "damage_type" : "刺傷",
    "lvl" : 71,
    "skill_name" : "縮地三尺"
]),
([  "action" : "$N神色平和地微微低首，一招"+YEL"『仙風道骨』"NOR+"，$w劍尖游移不
定地刺向$n的$l",
    "force" : 450,
    "dodge" : 20,
    "damage" : 250,
    "damage_type" : "刺傷",
    "lvl" : 80,
    "skill_name" : "仙風道骨"
]),
([  "action" : "$N雙手和什，使出一招"+HIY"『仙降于世』"NOR+"，$w平平地飛出刺向$n
的$l",
    "force" : 500,
    "dodge" : 35,
    "damage" : 300,
    "damage_type" : "刺傷",
    "lvl" : 90,
    "skill_name" : "仙降于世"
]),
([  "action" : "$N面露微笑，一招"+HIY"『普渡眾生』"NOR+"，$w一閃間舞出無數團劍花
刺向$n的$l",
    "force" : 550,
    "dodge" : 25,
    "damage" : 350,
    "damage_type" : "刺傷",
    "lvl" : 100,
    "skill_name" : "普渡眾生"
])
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail(HIC"你的內力不夠。\n"NOR);
    if ((int)me->query_skill("lingyuan-xinfa", 1) < 10)
   return notify_fail(HIC"你的靈元心法火候太淺。\n"NOR);
    if ((string)me->query("gender") != "女性" )
   return notify_fail(HIY"這種陰柔的劍法只有女子才適合學。\n"NOR);
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
   return notify_fail("你使用的武器不對。\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("你的體力不夠練恆山劍法。\n");
    me->receive_damage("qi", 30);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"hengshan-jian/" + action;
}

