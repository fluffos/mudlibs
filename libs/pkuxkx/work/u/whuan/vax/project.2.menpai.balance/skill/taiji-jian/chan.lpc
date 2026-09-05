// chan.c 太极剑法「缠」字诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
    object weapon;
    int bt,busytime;
    bt = me->query("betrayer");

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

          if (!objectp(weapon = me->query_temp("weapon"))
          || (string)weapon->query("skill_type") != "sword")
          if (!objectp(weapon = me->query_temp("secondary_weapon"))
          || (string)weapon->query("skill_type") != "sword")
                 return notify_fail("你没拿剑,还想使剑法的绝招?别作梦了!\n");
		
	if( (int)me->query_skill("taiji-jian", 1) < 40 )
		return notify_fail("你的太剑法极不够娴熟，不会使用「缠」字诀。\n");

	msg = HIG "$N手腕灵动运剑成圈,顷刻只见圆转剑意不绝,$n只觉得处处虚招处处实,根本无从下手，只能眼睁睁看着$N催动剑气直逼过来。心中暗道：来了！来了！这就是那个[缠]字诀吧?\n";

	me->start_busy(1);
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")*(bt*2 + 2)/5 ) {
                msg += RED "$p眼看无数圆圈凌头压近却是毫无办法,但见对方剑芒大盛自己无处不在暴露在敌人的凌厉攻势之下不仅手忙脚乱无法出招!$P\n" NOR;
          busytime = ceil(pow((int)me->query_skill("taiji-jian",1)/5.0, 0.5 )) + 2;
	   //target->start_busy( (int)me->query_skill("taiji-jian") / (8*(bt + 1)) );
	   target->start_busy(busytime);
	} else {
           me->start_busy(2+random(4));
		msg += HIW "$p见对方一服有恃无恐的模样怒气大盛已经忘记了荣辱生死,信手向剑圈中直捣过去,$P完全没料到对方竟能误打误撞找到自己的破绽,只得收回了[缠字诀]\n";
	}
	message_vision(msg, me, target);

	return 1;
}
