// rouyun-steps.c  柔云步法
// modified by Venus Oct.1997
// Made by deaner
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" :    "$n使一式『云中鹤影』，身形纵离地面数尺，躲过了$N这一招。\n",
    "dodge"  : 20
]),
([      "action" :    "$n身形飘飘，使出一式『云彩飘忽』，避过了$N的攻击。\n",
    "dodge"  : 30
]),
([      "action" :    "$n使出一式『云雾缭绕』，$N眼前已没了$n的踪影。\n",
    "dodge"  : 40
]),
([      "action" :    "$n施展出一式『云雨不定』，身影急幌，在千钧一发间躲过了$N的攻势。\n",
    "dodge"  : 50
]),
([      "action" :    "$n衣袂飘飘，一式『云蒸霞蔚』，轻灵地避了开去。\n",
    "dodge"  : 60
]),
([      "action" :    "$n立即使出一式『云海浮沉』，沉肩滑步，微晃身影，避开了$N的攻击。\n",
    "dodge"  : 75
]),
([      "action" :    "$n立刻使一式『云影万千』，身形忽进忽退，忽左忽右，$N的攻击已然无效。\n",
    "dodge"  : 90
])
});

mapping query_action(object me, object weapon)
{
    int zhaoshu, level;

    zhaoshu = sizeof(action);
    level   = (int) me->query_skill("rouyun-steps",1);

    if (level < 60 )
   zhaoshu--;

    if (level < 50 )
   zhaoshu--;

    if (level < 40 )
   zhaoshu--;
    return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
    return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me)
{
    if ((int)me->query_skill("lingyuan-xinfa", 1) < 10)
   return notify_fail(HIC"你的灵元心法火候太浅。\n"NOR);
    if ((string)me->query("gender") == "男性" )
   return notify_fail(HIY"这种轻灵的步法老爷们学来干嘛？\n"NOR);
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
    if( (int)me->query("qi") < 35 )
   return notify_fail(HIC"你的体力太差了，不能练柔云步法。\n"NOR);
    if (me->query_skill("rouyun-steps", 1) < 20)
   me->receive_damage("qi", 10);
    else if (me->query_skill("rouyun-steps", 1) < 60)
   me->receive_damage("qi", 20);
    else
   me->receive_damage("qi", 30);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"rouyun-steps/" + action;
}
