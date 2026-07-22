//jin.c 神魔金身
// Created by Lonely@yxcs 21/2/2002

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIY "神魔金身" NOR; }

int perform(object me, string skill)
{
        int count;

        if (me->query("qi") < 80)
                return notify_fail("你的体力不支，无法运行神魔金身。\n");
        if (me->query_temp("jin_power", 1))
                return notify_fail("你已经在运行中了。\n");

        message_vision(HIY "$N" HIY "双手平举过顶，运起神魔金身，"
                       "全身笼罩在劲气之中！\n" NOR, me);
        count = 10*(int)me->query_str();


        me->receive_damage("qi", 40 + random(40));
        me->set_temp("jin_power", 1);
        me->add_temp("apply/armor", count);
        me->start_call_out((: call_other, __FILE__, "remove_effect", me,
                              count :), 180 + random(30));

        return 1;
}

void remove_effect(object me, int count)
{
        me->delete_temp("jin_power", 1);
       me->add_temp("apply/armor", -count);
        tell_object(me, "你施展完神魔金身，松了一口气。\n");
}