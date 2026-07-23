
// bx_arrow.c 碧血箭

#include <ansi.h>
// inherit F_CLEAN_UP;

// inherit SSERVER;
inherit F_SSERVER;

int exert(object me, object target)
{
	string msg;
	int success, ap, dp;


	if( !target ) target = offensive_target(me);
       if ( target == me ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("碧血箭只能在战斗中使用。\n");

     if( !target || !target->is_character() || !me->is_fighting(target) )
            return notify_fail("碧血箭只能对战斗中的对手使用。\n");

//	if( !target
//	|| !target->is_character()
//	|| target->is_corpse()
//	|| target==me)
//		return notify_fail("你要对谁施展碧血箭？\n");
	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要对谁施展碧血箭？\n");

	if((int)me->query("max_neili") < 400 )
		return notify_fail("你的内力不够，不能有效施展碧血箭！\n");

	if((int)me->query("max_jing") < 200 )
		return notify_fail("你的精力不够，不能有效施展碧血箭！\n");

	if((int)me->query_skill("force",1) < 50 
         || (int)me->query_skill("wudu-shengong",1) < 50 )
		return notify_fail("你的内功修为不够，不能有效施展碧血箭！\n");

//	if((int)me->query("qi") > (int)me->query("max_qi")*2/3 )
//		return notify_fail("现在还不至于就和别人拼命吧？\n");

	if((int)me->query("combat_exp") < (int)target->query("combat_exp")/10)
		return notify_fail("对方武功强你十倍，不会有用的，还是快跑吧！\n");

	message_vision( HIC
"$N双目血红，披头散发，仰天发出一声悲啸！\n\n$N把心一横，在自己舌尖狠命一咬，将毕生功力化做一道奇毒血箭向$n喷了过去！\n" NOR,me,target);

	success = 1;
	ap = me->query_skill("force",1)+me->query_skill("wudu-shengong",1);
	ap = ap /2 ;
       ap = ap * ap * ap/10;
	ap = ap+(int)me->query("combat_exp");
//	ap = ap * ap;          
	dp = target->query("combat_exp");
//     dp = dp * dp;
	if( random(ap+dp) < random(dp) ) success = 0;

	ap = (int)me->query("max_neili");
	dp = (int)target->query("max_neili");
	if( ap < random(dp) ) success = 0;

	if(success == 1 ){
	        message_vision( HIR "结果$n促不及防被血箭射个正着，顿时发出一声惨叫！\n$N见状哈哈大笑一声，眼前一黑倒在地上。\n" NOR,me,target);

		target->kill_ob(me);
		me->kill_ob(target);
		me->add("max_neili", -50);
		me->add("max_jing", -50);
		me->save();
		
		target->receive_wound("qi", (int)target->query("max_qi")+1, me);
		target->receive_wound("jing", (int)target->query("max_jing")+1, me);
		COMBAT_D->report_status(target);

		me->receive_wound("qi", (int)me->query("max_qi")+1, target);
		me->receive_wound("jing", (int)me->query("max_jing")+1, target);
		COMBAT_D->report_status(me);

	}
	    
	else {
	     message_vision( HIR "但是血箭被$n内力反震，化做一蓬血雾四散飘去！\n$N一声惨笑，长叹一声，眼前一黑倒在地上。\n" NOR,me,target);

//		target->kill_ob(me);
//		me->kill_ob(target);

		me->add("max_neili", -30);
		me->add("max_jing", -30);
		me->save();
		
		me->receive_wound("qi", (int)me->query("max_qi")+1, target);
		me->receive_wound("jing", (int)me->query("max_jing")+1, target);
		COMBAT_D->report_status(me);
	} 

//	return 3+random(5);
       return 1;
}

