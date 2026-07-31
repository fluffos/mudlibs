
// tie-steps.c
//written by kouga

inherit SKILL;

string *dodge_msg = ({
        "但是$n身形飘忽，一招「穿云势」拔地而起，举重若轻的避开这一击。\n",
        "$n身随意转，一式「破雾势」，全身化作无数虚影掠出丈外。\n",
        "$n身形往上一拔，一招「开天势」，腾空而起，避了开去。\n",
        "$n气聚丹田，一招「劈地势」，身形急缩，躲开$N那致命一击。\n",
        "$n身形往上一拔，一招「推山势」落在数尺之外。\n",
        "$n身形晃动，一招「搅海势」，全身化作无数虚影掠出丈外。\n",
        "$n真气荡漾，如雷霆般大喝一声，一招「雷针势」，身形极速后退。\n",
        "$n使出「电箭势」，身形如电般地躲开了$N这一招。\n",
        "$n身影微动，已经藉一招「龙腾势」轻轻闪过。\n",
        "$n腾空一跃，双脚向前一踢，一招「虎扑势」，躲开数尺。\n",
        "只见$n身影一晃，一式「豹跃势」早已避在七尺之外。\n",
        "可是$n使一招「鹰飞势」，身子轻轻飘了开去，早已绕到$N身後！\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="dodge");
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("你的体力太差了，不能练铁血十二势。\n");
        me->receive_damage("qi", 30);
        return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 20;
} 
string perform_action_file(string action)
{
        return __DIR__"tie-steps/" + action;
}