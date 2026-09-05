// flatter.c
#include <ansi.h>
inherit SKILL;

int valid_enable(string usage)
{
    return (usage == "parry"); 
}


int valid_learn(object me)
{
    if ( me->query_int()<20 )
        return notify_fail("你的悟性小于 30，无法领会高深的马屁神功。\n");
    return 1;
}

int practice_skill(object me)
{
    if ((int)me->query("jing") < 40)
        return notify_fail("你的精力不够练马屁神功。\n");
    me->receive_damage("jing", 30);
    return 1;
}
string *parry_msg = ({
        GRN"$n"GRN"说道:“老大您鸟生鱼汤，赛过诸葛之亮。我怎是您的对手呢?”\n$n"GRN"乘$N"GRN"听的出神，溜了开去。\n"NOR,
        GRN"$n"GRN"说道:“高手您仙福永享，寿与天齐。弟子罪该万死，求您老人家放过我吧。”\n$n乘$N出手速度变慢的机会，溜了开去。\n"NOR,
        });
string *unarmed_parry_msg = ({
        GRN"$n"GRN"说道:“老大您鸟生鱼汤，赛过诸葛之亮。我怎是您的对手呢?”\n$n"GRN"乘$N"GRN"听的出神，溜了开去。\n"NOR,
        GRN"$n"GRN"说道:“高手您仙福永享，寿与天齐。弟子罪该万死，求您老人家放过我吧。”\n$n"GRN"乘$N"GRN"出手速度变慢的机会，溜了开去。\n"NOR,
        });

string query_parry_msg(object weapon)
{   
    if( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
    return __DIR__"flatter/" + action;
}

