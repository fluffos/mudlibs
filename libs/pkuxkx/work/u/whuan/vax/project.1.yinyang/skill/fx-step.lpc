// Made by ysg
// Data: 1997.10.17

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        GRN"$n一招「大江东去」轻轻巧巧地避了开去。\n"NOR,
        GRN"只见$n身影一晃，一式「浪淘尽，千古风流人物」早已避在七尺之外。\n"NOR,
        GRN"$n使出「故垒西边」，轻轻松松地闪过。\n"NOR,
        GRN"$n左足一点，一招「人道是，三国周郎赤壁」腾空而起，避了开去。\n"NOR,
        GRN"可是$n使一招「乱石穿空，惊涛拍岸」，身子轻轻飘了开去。\n"NOR,
        GRN"$n身影微动，已经藉一招「卷起千堆雪」轻轻闪过。\n"NOR,
        GRN"但是$n一招「遥想公谨当年,小乔初嫁了」使出，早已绕到$N身後！\n"NOR,
        GRN"但是$n身形飘忽，轻轻一纵，一招「羽扇纶巾」，避开这一击。\n"NOR,
        GRN"$n身形往上一拔，一招「谈笑间，樯橹灰飞烟灭」，一个转折落在数尺之外。\n"NOR,

});
int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}
int valid_learn(object me)
{
        if( (int)me->query("max_neili") < 40 )
                return notify_fail("你的内力不够，没有办法练飞仙步法。\n");
        return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 0 )
                return notify_fail("你的气或内力不够，不能练飞仙步法。\n");
        me->receive_damage("qi", 30);
//        me->add("force", -3);
        return 1;
}
int effective_level() { return 10;}
int learn_bonus()
{
        return 10;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 40;
}

string query_yinyang()
{
	return "太阳";
}