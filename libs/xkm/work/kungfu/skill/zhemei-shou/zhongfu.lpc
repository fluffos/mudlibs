//Cracked by Roath
// zhongfu.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int sp, dp, i;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || target == me 
	|| target->query("id") == "mu ren" 
	|| target->query("id") == "shangshan" 
	|| target->query("id") == "mengzhu" 
	|| target->query("id") == "fae" )
		return notify_fail("你要往谁身上种生死符？\n");

//	if( !userp(target) )
//		return notify_fail("你只能在玩家身上种生死符。\n");


//	if ( me->query_skill_mapped("force") != "bahuang-liuhe")
//                return notify_fail("你没有运八荒六和唯我独尊神功！\n");	

//        if ( me->query_skill_mapped("strike") != "liuyang-zhang")
//                return notify_fail("你没有备天山六阳掌！\n"); 

	if( !me->is_fighting() || !target->is_fighting() || !living(target) )
		return notify_fail("你必须在战斗中才能种生死符！\n");

	if( target->query("zf")) 
		return notify_fail("此人已经被种下生死符了！\n");

//	if( (int)me->query_skill("bahuang-liuhe",1) < 100 )
//		return notify_fail("你的八荒六和唯我独尊神功功力不够，不能种生死符！n");

//        if( (int)me->query_skill("liuyang-zhang",1) < 100 )
//                return notify_fail("你的天山六阳掌功力不够，不能种生死符！n");
                
        if( (int)me->query("neili",1) < 200 )
		return notify_fail("你的内力不够，不能种生死符。\n");



	message_vision(
		HIR "$N一阵阴笑，右手指尖蕴出一缕白线，猛地向$n的胸口射了过去！\n\n" NOR,
		me, target );

	if( !target->is_killing(me) ) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
	dp = target->query_skill("force") + target->query_skill("dodge") + me->query_kar();
	sp *= me->query("combat_exp")/1000;
	dp *= target->query("combat_exp")/1000;
	

	if( random(sp) > random(dp) ) 
	{
		tell_object(target, HIR "你只觉胸口一闷，一丝凉意直入肺腑，脑中一片空白茫然不知所措！\n" NOR);
		tell_object(me, HIG "你觉得指间的白线流入" + target->name() + "的胸口，看来已经种下生死符了。\n" NOR);
	
                target->set("zf",me->query("id"));
                target->apply_condition("zf_poison",12);
		target->set("zf_lv",me->query_skill("bahuangh-liuhe",1));
		
		me->add("potential",  target->query_skill("force")/10);
		me->add("combat_exp", target->query("combat_exp")/1000);
		if (me->query("potential") > me->query("max_potential"))
                me->set("potential", me->query("max_potential"));

		me->start_busy(random(10));
		target->add("jingli", -random(50));
		target->start_busy(random(3));
		me->add("neili", -125);
		me->add("jingli", -5);

	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，猛一运力把白线逼了回去。\n" NOR, me, target);
		tell_object(me, HIG "你觉得手指一阵冰凉，暗叫一声不好，赶经运功抵抗！\n" NOR); 
		me->add("jingli", -15);
		me->add("neili", -125);
		me->add("qi", -200);
		me->start_busy(10);

		
		}

	
	


	return 1;
}


