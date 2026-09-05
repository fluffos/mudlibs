// qiurao.c
// 修改马屁神功的判断几率。by seagate@pkuxkx 2011/02/05 

#include <ansi.h>
inherit F_SSERVER;

string* valid_weapon() 
{
    return ({ "all" });
}

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
	string msg;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || target->query("id") == "mu ren" )
        return notify_fail("你向谁求饶？\n");

	if( !target->is_fighting(me) ) 
		return notify_fail("又没人要打你，求什么饶呀？\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，根本没机会杀你！\n");

	msg = CYN "$N使出马屁神功，求饶拍马之语如滔滔江水，连绵不绝地说出。\n";
	me->start_busy(random(2));
//命中率D+	
	if( F_KUNGFU->hit_rate((int)me->query_skill("flatter",1)/10+(int)me->query("int"), (int)target->query("int")*2, 10, me, target) ) 
	{
		msg += "结果$p看见$P可怜的样子，心肠一软，停止了攻击。\n" NOR;
		me->add("shen",-1000);
		target->remove_enemy(me);
		if ( !target->is_busy() )
		  target->start_busy(1+random(2));
	}
	else 
	{
		msg += "可是$p听了$P的话，气上加气，攻击得更猛了。\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);

	return 1;
}
