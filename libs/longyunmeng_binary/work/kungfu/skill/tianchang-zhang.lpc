// tianchang-zhang.c 天长掌法
// modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N一式"+HIC"『潜移默化』"NOR+"，右掌先发，左掌后至，疾拍$n的
$l",
    "force" : 160,
    "dodge" : 30,
    "damage_type" : "内伤",
    "lvl" : 0,
    "skill_name" : "潜移默化"
]),
([      "action" : "$N侧身冲上，一招"+HIB"『披星戴月』"NOR+"，双掌齐出，攻向$n的
$l",
    "force" : 180,
    "dodge" : 25,
    "damage_type" : "内伤",
    "lvl" : 9,
    "skill_name" : "披星戴月"
]),
([      "action" : "$N提气跃起，使出"+BLU"『乌云密布』"NOR+"，荡起漫天掌影，击向
$n的$l",
    "force" : 200,
    "dodge" : 20,
    "damage_type" : "内伤",
    "lvl" : 18,
    "skill_name" : "乌云密布"
]),
([      "action" : "$N抽身退开一步，接着一式"+HIW"『寒风四起』"NOR+"，“呼呼”劈出
两掌，激起两股阴柔的暗劲袭向$n的$l",
    "force" : 230,
    "dodge" : 15,
    "damage_type" : "内伤",
    "lvl" : 27,
    "skill_name" : "寒风四起"
]),
([      "action" : "$N双掌突然一拍又向外推开，一式"+HIW"『冰冻三尺』"NOR+"，逼出阵阵
寒气攻向$n的$l",
    "force" : 260,
    "dodge" : 10,
    "damage_type" : "内伤",
    "lvl" : 36,
    "skill_name" : "冰冻三尺"
]),
([      "action" : "$N斜里穿出，使出"+RED"『骄阳似火』"NOR+"，双掌默运内劲向$n的胸口
平推出一股令人窒息、灼热的劲气",
    "force" : 300,
    "dodge" : 5,
    "damage_type" : "内伤",
    "lvl" : 45,
    "skill_name" : "骄阳似火"
]),
([      "action" : "$N施展出"+HIR"『三味真火』"NOR+"，右掌在胸前微微一摆，再向下一捞，
接着向外猛地一推，竟从手心里喷出一股热流逼向$n的胸口",
    "force" : 350,
    "dodge" : -5,
    "damage_type" : "内伤",
    "lvl" : 54,
    "skill_name" : "三味真火"
]),
([      "action" : "$N使一式"+WHT"『月黑风高』"NOR+"，双掌荡起无数劲气，层层逼向
$n的$l",
    "force" : 400,
    "parry" : 25,
    "dodge" : 20,
    "damage_type" : "内伤",
    "lvl" : 63,
    "skill_name" : "月黑风高"
]),
([      "action" : "$N使出"+HIW"『与天比高』"NOR+"，双掌缓缓推向天空，接着骤然翻掌收回，
向$n猛地推出",
    "force" : 450,
    "parry" : 10,
    "dodge" : 15,
    "damage_type" : "内伤",
    "lvl" : 72,
    "skill_name" : "与天比高"
]),
([      "action" : "$N暗运潜力，施展出"+HIY"『日月同辉』"NOR+"，双掌斜出，左砸右砍，祭出
道道劲力劈向$n的$l",
    "force" : 500,
    "parry" : 20,
    "dodge" : 5,
    "damage_type" : "内伤",
    "lvl" : 81,
    "skill_name" : "日月同辉"
]),
([      "action" : "$N双掌交叉一翻，再向外一抱，使出"+HIY"『日月争辉』"NOR+"，接着右掌上，
左掌下，电光火石般地飞身扑向$n",
    "force" : 580,
    "parry" : 5,
    "dodge" : -5,
    "damage_type" : "内伤",
    "lvl" : 90,
    "skill_name" : "日月争辉"
])
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }  

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail(HIC"练天长掌法必须空手。\n"NOR);
    if ((int)me->query("max_neili") < 80)
   return notify_fail(HIG"你的内力太弱，无法练天长掌法。\n"NOR);
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
    int i, level;
    level = (int)me->query_skill("tianchang-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("你的内力不够练天长掌法。\n");
    me->receive_damage("qi", 25);
    return 1;
}
