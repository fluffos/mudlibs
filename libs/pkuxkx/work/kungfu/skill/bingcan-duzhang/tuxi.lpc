
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HIW"寒冰突袭"NOR; }

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
	object weapon;
	string msg;
    mapping prepare_skill_map;
	
	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) 
	|| !living(target))
		return notify_fail("「寒冰突袭」只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("bingcan-duzhang", 1) < 100 )
		return notify_fail("你的冰蚕毒掌功力太浅，使不出「寒冰突袭」。\n");

	if( (int)me->query_skill("strike", 1) < 100 )
		return notify_fail("你的基本掌法还要多加练习才是！\n");
	
	if( (int)me->query_skill("force", 1) < 300 )
		return notify_fail("你的基本内功功力太浅，使不出「寒冰突袭」。\n");
		
	if( (int)me->query("max_neili") < 4000 )
		return notify_fail("你的内力修为太浅，使不出「寒冰突袭」。\n");
	
	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的真气不够，使不出「寒冰突袭」。\n");

	if (objectp(weapon = me->query_temp("weapon")) || objectp(weapon = me->query_temp("secondary_weapon")))
		return notify_fail("你拿着武器使不出「寒冰突袭」。\n");

    prepare_skill_map = me->query_skill_prepare();
    if( me->query_skill_mapped("strike") != "bingcan-duzhang" || !prepare_skill_map || member_array("bingcan-duzhang",values(prepare_skill_map)) == -1)
		return notify_fail("「寒冰突袭」只能用于冰蚕毒掌的攻击，你需要激发(enable)并指定使用(prepare)冰蚕毒掌。\n");

	if( me->query_temp("bingcan-duzhang/tuxi") )
		return notify_fail("你已经在使用「寒冰突袭」了！\n");
	
	me->set_temp("bingcan-duzhang/tuxi",1);
	me->set_temp("bingcan-duzhang/att_speed", 1);
	me->add("neili", -me->query_skill("bingcan-duzhang",1)/5);
	
	me->set_temp("active_buffer/bingcan-duzhang/name", "寒冰突袭");                  //buff名称
	me->set_temp("active_buffer/bingcan-duzhang/effect1", "攻击速度+"+1+"%");        //效果描述1
	msg = HIC"\n$N内息在数处经脉中急速游走，迈步而前，左右双掌连环拍出，后发齐到，越攻越快！\n\n"NOR;
	message_vision(msg,me,target);
	
	call_out("refresh_effect", 1 , me);
	return 1;
}

void refresh_effect(object me)
{
	object weapon;
    mapping prepare_skill_map;
	string msg;
	int sk, n=1;
	if (!me) return;
	if (!me->query_temp("bingcan-duzhang/tuxi")) 
	{	
		me->delete_temp("bingcan-duzhang");
		me->delete_temp("active_buffer/bingcan-duzhang");
		return;
	}
	if (!me->is_fighting()){
		message_vision(HIY"\n$N吐出一口浊气，缓缓收招，运行全身的内息收归丹田。\n\n"NOR,me);
		me->delete_temp("bingcan-duzhang");
		me->delete_temp("active_buffer/bingcan-duzhang");
		return;
	}
	if (objectp(weapon = me->query_temp("weapon")) || objectp(weapon = me->query_temp("secondary_weapon")))
	{
		message_vision(HIY"\n$N变换了招数，运行全身的内息缓缓收归丹田。\n\n"NOR,me);
		me->delete_temp("bingcan-duzhang");
		me->delete_temp("active_buffer/bingcan-duzhang");
		return;
	}
    prepare_skill_map = me->query_skill_prepare();
    if( me->query_skill_mapped("strike") != "bingcan-duzhang" || !prepare_skill_map || member_array("bingcan-duzhang",values(prepare_skill_map)) == -1)
	{
		message_vision(HIY"\n$N变换了招数，运行全身的内息缓缓收归丹田。\n\n"NOR,me);
		me->delete_temp("bingcan-duzhang");
		me->delete_temp("active_buffer/bingcan-duzhang");
		return;
	}
	sk = (int)me->query_skill("bingcan-duzhang", 1);
	if (me->query("neili")<100 || sk<100)
	{
		message_vision(HIY"\n$N内息运行不济，一口真气提不起来，手上的攻势随之缓了下来。\n\n"NOR,me);
		me->delete_temp("bingcan-duzhang");
		me->delete_temp("active_buffer/bingcan-duzhang");
		return;
	}
	if (!me->query_temp("bingcan-duzhang/do_attack") || (int)me->query_temp("bingcan-duzhang/att_speed")>=50)
	{
		me->add("neili", -10);
		call_out("refresh_effect", 1 , me);
		return;
	}
	n=1+(sk-100)/100;
	if (n>10) n=10;
	me->add("neili", -n*10);
	n += (int)me->query_temp("bingcan-duzhang/att_speed");
	if (n>50) n=50;
	me->set_temp("bingcan-duzhang/att_speed", n);
	me->set_temp("bingcan-duzhang/do_attack", 0);
	me->set_temp("active_buffer/bingcan-duzhang/effect1", "攻击速度+"+n+"%");        //效果描述1
	message_vision(HIC"$N双掌连环拍出，一招紧接着一招，越攻越快！\n" NOR,me);
	call_out("refresh_effect", 1 , me);
	return;
}

int help(object me)
{
        write(HIW"\n冰蚕毒掌「寒冰突袭」\n\n"NOR);
        write(@HELP
	利用冰蚕毒掌的冰雾，双掌连环攻击，「寒冰突袭」可以在与敌作战时，
	提高自己的攻击速度。
	
        要求：  内力 1000 以上；      
                最大内力 4000 以上；  
                基本内功等级 300 以上；
                基本掌法等级 100 以上；
                冰蚕毒掌等级 100 以上。
HELP
        );
        return 1;
}
