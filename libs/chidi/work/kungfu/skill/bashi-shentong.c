// bashi-shentong.c 八识神通
// Modified by Venus Oct.1997

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="magic"; }

int valid_learn(object me)
{
    if( (int)me->query_skill("buddhism",1) < 10
    ||(int)me->query_skill("buddhism",1) <= (int)me->query_skill("bashi-shentong",1) )
    return notify_fail("你的佛法修为还不够高深，无法学习八识神通。\n");
    return 1;
}

string conjure_magic_file(string spell)
{
    return __DIR__ + "bashi-shentong/" + spell;
}

int practice_skill(object me)
{
    object bug;

    if( (int)me->query("jingli") < 10)
    return notify_fail("你的精力不够。\n");

    if( (int)me->query("jing") < 35 )
   return notify_fail("你的精神无法集中。\n");

    me->add("jingli", -5);
    me->receive_damage("jing", 30);

    message_vision(HIY"$N闭目凝神，神游太虚，开始研习八识神通……\n"NOR,me);
    if( random((int)me->query("jing")) < 10)
    {
    tell_object(me,HIC"突然！一阵狂风刮来，将你的元神吹落云头！哇～哇≈哇！\n"NOR);
    tell_room(environment(me),HIY"天空中忽然“嗖”地落下来一团物事，又好象什
么都没有，却见"+me->query("name")+"开始口吐白沫了。 \n"NOR,me);
    me->unconcious();
    return 0;
    }
    else return 1;
}

