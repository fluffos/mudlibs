// jiji.c 乩童起乩
// Created by hht 20/10/2009

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIR "乩"HIY"童"HIG"起"HIR"乩" NOR; }

int perform(object me, string skill)
{
        int count;

        if (me->query("qi") < 80)
                return notify_fail("你的体力不支，无法施展乩童起乩。\n");

        message_vision(HIY "$N" HIC "口吐白沫，双眼翻白，"
                       "双手做托天式,嘴里念念有词，居然是绝迹多年的"HIR "乩"HIY"童"HIG"起"HIR"乩！！！。\n" NOR, me);
        count = me->query_int();
        if (me->query_temp("special_skill/jiji", 1))
                return notify_fail(HIM"天上突然飞下来一块板砖正砸你的头上，空中隆隆传来一阵声音：“没事不要打扰老子睡觉！”。\n");

        me->receive_damage("qi", 40 + random(40));
        me->set_temp("special_skill/jiji", 1);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/dodge", count);
        me->add_temp("apply/damage", me->query_str());
        me->add_temp("apply/unarmed_damage", me->query_str()*2);
   	me->start_call_out((: call_other, __FILE__, "remove_effect", me,
			      count :), 200 + random(130));

        return 1;
}

void remove_effect(object me, int count)
{
        me->delete_temp("special_skill/jiji",1);
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/dodge", -count);
        me->add_temp("apply/damage", -me->query_str());
        me->add_temp("apply/unarmed_damage", -me->query_str()/2);
        tell_object(me, "你施展完"HIR "乩"HIY"童"HIG"起"HIR"乩" NOR"，吐出一口浊气。\n");
}
