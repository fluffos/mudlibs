// ruying.c 如影随形
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「如影随形」"
int perform(object me, object target)
{
	string msg;
	int count;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("使用「如影随形」时双手必须空着！\n");
	fskill = "zhanzhuang-gong";
	bskill = "leg";
	
		fskill = me->query_skill_mapped("force");

		sskill = "ruying-leg";
		fskill = "zhanzhuang-gong";


	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query_dex() < 27 )
		return notify_fail("你的身法不够强，不能使用"PNAME"。\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你现在内力太弱，不能使用"PNAME"。\n");

	msg = HIY"$N"HIY"忽然身随掌起，双腿连环，霎时之间连踢八腿，一腿既出，第二腿如影随形，紧跟而至。\n" NOR;
	message_combatd(msg, me, target);
	for (count=0;count<8;count++)
	{
		if (flag ==1 ) target = offensive_target(me);
		if (!objectp(target)) break;
		if (random(3)==0) target->start_busy(2);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
	}
	me->add("neili", -400);
	me->start_busy(2);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		可以连续踢出八腿，使敌人无喘息之机，威力强大。
	出手要求：
		站桩功50级
		如影随形腿200级
		后天身法27
		内力1000
HELP
	);
	return 1;
}

