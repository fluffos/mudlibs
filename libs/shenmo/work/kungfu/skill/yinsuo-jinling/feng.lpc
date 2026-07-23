// feng.c 银索金铃 封穴
// By Kayin @ CuteRabbit Studio 1999/3/21 new

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	object ob;
	string msg;
	ob=me->query_temp("weapon");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("封穴只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
			return notify_fail("你使用的武器不对。\n");

	if((int)me->query_skill("yunv-xinfa",1) < 100)
		return notify_fail("你玉女心经的功力不够不能封住敌人穴道!\n");

	if((int)me->query_skill("yinsuo-jinling",1) < 150)
		return notify_fail("你的银索金铃修为不够,目前还不能封住敌人穴道!\n");

	if((int)me->query("neili") < 800)
		return notify_fail("你内力现在不够, 不能封穴! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "的穴道已经被你封住了，你还怕什么\n");

	msg = HIC "$N使出"HIY"银索金铃"HIC"的上乘点穴功夫，手中"+ ob->name() +""HIC"罩住了$n的全身要穴, 使$n动弹不得。\n";

	if(random(me->query("combat_exp")) >= target->query("combat_exp")/2)
	 {
		msg += "结果$p的檀中大穴被点，不能动弹！\n" NOR;
		target->start_busy( (int)me->query_skill("yinsuo-jinling",1) / 40 + 4);
		me->add("neili", -150);
	} else {
		msg += HIG "可是$p几经艰难终于躲过了$P的攻击。\n" NOR;
		me->start_busy(1);
	}
	message_vision(msg, me, target);

	return 1;
}
