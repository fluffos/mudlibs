//Cracked by Xuanyuan
//lingshe.c 灵蛇手势

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("灵蛇手势只能对战斗中的对手使用。\n");

	if( me->query_temp("baituo/lingshe") )
		return notify_fail("你已经使出灵蛇手势了！\n");

	if( me->query_skill_mapped("cuff") != "lingshe-quan" )
		return notify_fail("你所用的并非灵蛇拳，不能与施展灵蛇手势！\n");

	if( me->query_skill_prepared("cuff") != "lingshe-quan" )
                return notify_fail("你所备的并非灵蛇拳，不能与施展灵蛇手势！\n");

	if( me->query_skill_mapped("force") != "hamagong" )
		return notify_fail("你所用的并非蛤蟆功，无法施展灵蛇手势！\n");

	if( me->query_skill("hamagong", 1) < 100 )
		return notify_fail("你的蛤蟆功火候未到，无法施展灵蛇手势！\n");

	if( (me->query_skill("cuff")) < 150 )
		return notify_fail("你灵蛇拳修为不足，还不会使用灵蛇手势！\n");

	if( me->query("neili") <= 500 )
		return notify_fail("你的内力不够施展灵蛇手势！\n");

	skill = me->query_skill("cuff");

	message_vision(HIG "\n突然$N拳路陡变，手臂转弯，转得古怪至极，便是从毒蛇身上悟出来的高招！\n" NOR, me, target);

	if( me->query_skill_prepared("strike") == "shentuo-zhang" ) {
		me->set_temp("restore", 1);
		me->prepare_skill("strike");
	}
	me->add_temp("apply/damage", skill/5);
	me->add_temp("apply/attack", skill/4);
	me->add_temp("apply/dodge", skill/5);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	if( me->query_temp("restore") ) me->prepare_skill("strike", "shentuo-zhang");

	me->set_temp("baituo/lingshe", 1);
	call_out("checking", 1, me, target);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/4);

	me->add("neili", -200);
	me->add("jingli", -100);

	return 1;
}

void checking(object me, object target)
{
	int skill;
	skill = me->query_skill("cuff");

	if ( me->query_temp("baituo/lingshe")  ) {
		if ( (int)me->query("neili") < 400  ) {
			tell_object(me, "\n你的内力后继不足，难以持续使用灵蛇手势，只好收缓招数来调匀气息。\n\n" NOR);
			me->delete_temp("baituo/lingshe");
			me->add_temp("apply/damage", -skill/5);
			me->add_temp("apply/attack", -skill/4);
			me->add_temp("apply/dodge", -skill/5);
			return;
           }
		else if ( me->query_skill_mapped("cuff") != "lingshe-quan" ) {
			tell_object(me, "\n你拳法骤变，无法再以灵蛇手势攻敌！\n\n" NOR);
			me->delete_temp("baituo/lingshe");
			me->add_temp("apply/damage", -skill/5);
			me->add_temp("apply/attack", -skill/4);
			me->add_temp("apply/dodge", -skill/5);
			return;
           }
		else if (!me->is_fighting()) {
			tell_object(me,  "\n你现在没有和人过招，当下收回了灵蛇手势的攻势。\n\n" NOR);
			me->delete_temp("baituo/lingshe");
			me->add_temp("apply/damage", -skill/5);
			me->add_temp("apply/attack", -skill/4);
			me->add_temp("apply/dodge", -skill/5);
			return;
           }
	   else call_out("checking", 1, me, target);
	}
	   else return;
}  

void remove_effect(object me, int amount)
{
	int skill;
	skill = me->query_skill("cuff");

	if ( me->query_temp("baituo/lingshe") ) {
		message_vision(HIG"\n$N袍袖一挥，已将一套灵蛇手势使完，神情甚是潇洒！\n" NOR, me);
        me->delete_temp("baituo/lingshe");
		me->add_temp("apply/damage", -skill/5);
		me->add_temp("apply/attack", -skill/4);
		me->add_temp("apply/dodge", -skill/5);
        }
}