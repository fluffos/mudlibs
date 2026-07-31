// feiyan-huixiang.c 飞燕回翔
// modified by Venus Oct.1997
// pyrobat-steps.c
#include <ansi.h>
inherit SKILL;
#include <combat.h>
mapping *action = ({
([      "action" : "$n两臂鹏举，纵上丈余，一式「巨鹏亮翅」顿时避开了$N的凌厉攻势。\n",
        "dodge"  : 10
]),
([      "action" : "$n身随风飘，侧身向后倒纵，轻巧地一式「风送紫霞」，化解了$N的攻势。\n",
        "dodge"  : 20
]),
([      "action" : "$n一式「燕徊朝阳」，长袖飘飘身形晃动，一转眼间便绕到了$N的身后。\n",
        "dodge"  : 30
]),
([      "action" : "$n低头恭身，抱拳一式「却别苍松」，身子向后滑出，将$N的攻势化于无形。\n",
        "dodge"  : 40
]),
([      "action" : "$n使出「旭日初升」，笔直跃起，在半空中化为「金雁横空」，飘落到一旁。\n",
        "dodge"  : 50
]),
([      "action" : "$n一招「晚月朗星」，身形左右急速晃动，幻出数个身影，从容地破解$N的攻势。\n",
        "dodge"  : 60
]),
([      "action" : "$n含笑飘身使出「幻眼云湮」，身形幻成一道白影，轻飘飘地闪到$N的左侧。\n",
        "dodge"  : 70
]),
([      "action" : "$n凝气守中一招「苍龙盘岭」，身化长龙绕着$N急转，使其无从下手，攻势不攻自破。\n",
        "dodge"  : 80
])
});
string *dodge_msg = ({
    "但是$n身形飘忽，轻轻一纵，一招「乳燕投林」，举重若轻的避开这一击。\n",
    "$n身随意转，一式「雪花飞舞」，倏地往一旁飘开数尺，避过了这一招。\n",
    "可是$n侧身一让，使出「柳絮轻飘」，$N这一招扑了个空。\n",
    "却见$n足不点地，一招「腾云驾雾」，身形滴溜溜一转，往旁闪开数尺，躲了开去。\n",
    "$n左脚一点右脚背，身形往上一拔，一招「一鹤冲天」，轻轻巧巧地避开了这一招。\n"
});

int valid_enable(string usage)
{
    return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
    return 1;
}

string query_dodge_msg(string limb)
{
        return action[random(sizeof(action))]["action"];

}


mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("feiyan-huixiang");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 30 )
   return notify_fail("你的体力太差了，不能练飞燕回翔......\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"feiyan-huixiang/" + action;
}