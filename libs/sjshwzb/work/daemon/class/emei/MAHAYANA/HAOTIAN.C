// mihun.c 迷魂术
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
	string msg;
	int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;

	if( !target ) target = offensive_target(me);

        if((int)me->query_skill("spells") < 100 || (int)me->query_skill("mahayana",1) < 60)
                return notify_fail("你法术根基太差，无法使出浩天镜。\n");

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
                return notify_fail("你想对谁施展浩天镜？\n");  

	if(target->query_temp("no_move"))
        return notify_fail(target->query("name")+"已经被浩天镜罩住，动弹不得了！\n");  

	if((int)me->query("mana") < 200 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你无法集中精力！\n");

me->add("mana", -20);
	me->receive_damage("sen", 10);

        msg = HIW
"\n$N大喝一声：看我浩天镜！\n\n" 
NOR;

	success = 1;
	ap = me->query_skill("spells");
	ap = ap * ap * ap /12 ;
	ap += (int)me->query("daoxing");
	dp = target->query("daoxing");
//	if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

	ap2 = (int)me->query_per();
	dp2 = (int)target->query_per();
//	if( random(4*ap) < ((int)target->query_cps()+dp)) success = 0;
//here we compare per and guy's ding li.


	ap3 = (int)me->query("mana");
	dp3 = (int)target->query("mana");
	if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;

//here we compare current mana. this is important. you need recover to try again.

	if(success == 1 ){
                msg +=  HIW "$n被浩天镜照住身形无法动弹，全身功夫半招也发挥不出来了。\n" NOR;
		target->set_temp("no_move", 1);
	
		howlong = random((me->query_skill("spells") -100))+1;
		if(howlong>60) howlong=60;
		call_out("free", howlong, target);
	}	    
	else {
                msg +=  HIR "$n看出$N要施展浩天镜，在千均一发之际躲开了！\n" NOR;   
me->start_busy(1+random(9));   
        	if( living(target) ) target->kill_ob(me);
	} 

	message_vision(msg, me, target);

	return 1;
}

void free(object target)
{
	if (target)
	target->delete_temp("no_move");      
	return;
}

