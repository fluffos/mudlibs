// wuxing-dun.c 五行遁
// written by hxsd
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "但是$n身形有如流水，轻轻一闪，举重若轻的避开这一击。\n",
    "dodge"  : 10
]),
([  "action" : "$n身随意转，一式五行「木字决」，倏地从木门挪开了三尺，避过了这一招。\n",
    "dodge"  : 20
]),

([  "action" : "可是$n侧身一让，使出五行身法中的「金字决」，$N这一招扑了个空。\n",
    "dodge"  : 30
]),
([  "action" : "却见$n足不点地，幻出五个身影，从火门往旁窜开数尺，躲了开去。\n",
    "dodge"  : 40
]),
([  "action" : "$n身形微晃，使出五行「土字决」，土遁到了$N的身后。\n",
    "dodge"  : 50
]),
([  "action" : "可是$n微微一笑，$N眼前水雾弥漫，$n已使出"+HIC"『水遁』"NOR+"借水而逝。\n",
    "dodge"  : 60
]),
([  "action" : "却见$n抛下手中兵刃，扑向路边的一棵大树，转眼和枝叶混为一体，
$N茫然四顾，不知$n已经靠"+HIG"『木遁』"NOR+"躲开攻击。\n",
    "dodge"  : 70
]),
([  "action" : "$n原地一转，立时钻入土中。$N这一招落到了空处，惊道"+HIY"『土遁』"NOR+"！\n",
    "dodge"  : 80
]),
([  "action" : "$n随手打出一团火球，喝道"+HIR"『火遁』"NOR+"！ 整个人消失在火球中。\n",
    "dodge"  : 90
]),
([  "action" : "$n哈哈一笑，把手中的兵刃交错一击，喝道“看我"+HIY"『金遁』"NOR+"”，突然精光耀眼，$N
眼前一花，这一招不知落到了何处。\n",
    "dodge"  : 100
]),
});

mapping query_action(object me, object weapon)
{
    int zhaoshu, level;

    zhaoshu = sizeof(action);
    level   = (int) me->query_skill("wuxing-dun",1);

/*    if (level < 200 )
       zhaoshu--;
    if (level < 150 )
       zhaoshu--;
    if (level < 100 )
       zhaoshu--;
    if (level < 70 )
       zhaoshu--;*/
    return action[random(zhaoshu)];
}
int valid_enable(string usage)
{
    return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 10)
   return notify_fail("你的杀意心法火候不够。\n");

    return 1;
}
string query_dodge_msg(string limb)
{
    object me, ob;
    mapping action;

    me = this_player();
    action = query_action(me, ob);

    return action["action"];
}
int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("你的杀意心法火候不够。\n");

    if( (int)me->query("qi") < 60 )
   return notify_fail("你的气力不够,不能修炼五行遁.\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"wuxing-dun/" + action;
}

