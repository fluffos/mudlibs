// kungfu/skill/taixuan-gong/taixuan
//海洋II（云起云落）
//星星lywin 2000/6/10

// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        if( target != me ) return
            notify_fail("你只能对自己用["+HIR+"葵花无敌功"+NOR+"]\n"NOR,);
	if ((int)me->query_skill("kuihua-dafa", 1) < 200)
		return notify_fail("你的葵花大法太差了。\n");
        if( (int)me->query("neili") < 500 ) return
            notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) return
            notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");

        me->add("neili", -500);
        me->receive_damage("qi",20);

        message_combatd(
HIW"$N突然大声 哈!哈!哈!哈!阴笑起来,向变了了人一样[全身如鬼如魅，飘忽来去，直似轻烟]。\n" NOR, me);
        me->add_temp("apply/attack", skill/4);
        tell_object(me,HIR"你的攻击力提高了!\n"NOR);
        me->add_temp("apply/dodge", skill/4);
        tell_object(me,HIR"你的防御力提高了!\n"NOR);
        me->set_temp("powerup", 1);
        me->add_temp("apply/strength",skill/25);
        tell_object(me,HIG"你的力量提高了!\n"NOR);
        me->add_temp("apply/dexerity",skill/25);
        tell_object(me,HIG"你的速度提高了!\n"NOR);
        me->add_temp("apply/constitution",skill/25);
        tell_object(me,HIG"你的根骨提高了!\n"NOR);
        me->add_temp("apply/intelligence",skill/25);
        tell_object(me,HIG"你的悟性提高了!\n"NOR);
        me->set_temp("powerup",1);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/5:),skill);
        if( me->is_fighting() ) me->start_busy(4);
        return 1;
}

void remove_effect(object me, int amount)
{
        int skill;
        skill = me->query_skill("force");
        me->add_temp("apply/attack", - skill/4);
        me->add_temp("apply/dodge", - skill/4);
        me->delete_temp("apply/attack");
        me->delete_temp("apply/dodge");
        me->delete_temp("powerup");
        me->add_temp("apply/strength",- skill/25);
        me->add_temp("apply/intelligence",- skill/25);
        me->add_temp("apply/constitution",- skill/25);
        me->add_temp("apply/dexerity" , - skill/25);
        me->delete_temp("apply/strength");
        me->delete_temp("apply/intelligence");
        me->delete_temp("apply/constitution");
        me->delete_temp("apply/dexerity");
        me->delete_temp("powerup");

        tell_object(me, "你的["+HIR+"葵花无敌功"+NOR+"]运行完毕，将内力收回丹田。\n");
}

