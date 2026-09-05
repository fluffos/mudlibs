// sui.c 太极剑法 [随]字决

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me, int a_amount, int d_amount);

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("太极剑法「随」字诀只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你需要装备sword类武器才能使用「随」字诀。\n");

	if( (int)me->query_skill("taiji-jian", 1) < 40 )
		return notify_fail("你的太极剑法不够娴熟，不会使用「随」字诀。\n");

    if( (int)me->query_skill("taiji-shengong", 1) < 40 )
        return notify_fail("你的太剑神功等级不够，不能发挥「随」字诀。\n");

	if( (int)me->query("neili") < 300  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("tjj_sui") ) 
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("taiji-jian");
	msg = HIB "$N使出太极剑法「随」字诀，剑圈逐渐缩小将周身护住。\n"NOR;
	message_combatd(msg, me, target);

	me->add_temp("apply/attack", -skill/4);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("tjj_sui", 1);

    me->set_temp("active_buffer/family","武当派");
    me->set_temp("active_buffer/taiji-jian.sui/name", "随字诀");                          //buff名称
    me->set_temp("active_buffer/taiji-jian.sui/last_time", time() + skill/4 );            //持续时间
    me->set_temp("active_buffer/taiji-jian.sui/effect1", "轻功技能+"+(skill/3)+"级");     //效果描述1
    me->set_temp("active_buffer/taiji-jian.sui/effect2", "攻击命中-"+(skill/4)+"级");     //效果描述2

//	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/4, skill/3 :), skill/4);
	//20080429 by icer: 修改了/feature/action:start_call_out，支持三个参数
	me->start_call_out( __FILE__, "remove_effect", skill/4, me, skill/4, skill/3);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
       if(!objectp(me) || !objectp(me) || !userp(me)) return;
	me->add_temp("apply/attack", a_amount);
	me->add_temp("apply/dodge", - d_amount);
	me->delete_temp("tjj_sui");
  me->delete_temp("active_buffer/taiji-jian.sui");
  if ( sizeof(me->query_temp("active_buffer"))==1 )
    me->delete_temp("active_buffer");
	tell_object(me, HIY "你的随字决运行完毕，将内力收回丹田。\n");
}
