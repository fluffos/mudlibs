// mihun.c 迷魂术
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
	string msg;
	int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;

	if( !target ) target = offensive_target(me);

        if((int)me->query_skill("spells") < 100 || (int)me->query_skill("chanzong",1) < 100)
                return notify_fail("你的禅宗佛法还不够纯熟，无法随心禅法。\n");

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
                return notify_fail("你要对谁施展「随心禅法」？\n");  

	if(target->query_temp("no_move"))
        return notify_fail(target->query("name")+"已经入境禅法，无法集中了！\n");  

        if((int)me->query("mana") < 500 )
                return notify_fail("你的法力不够！无法施展「随心禅法」！\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("你无法集中精力！无法施展「随心禅法」！\n");

        me->add("mana", -300);
        me->receive_damage("sen", 100);

        msg = HIW
"$N双手合十，深吸一口气，目露慈光，面带微笑，内力运转，竟使全身上下宝光流动。\n
面对着$n不管对方听得懂听不懂，竟随心所欲的传授起禅法，顿时佛声漫天．．．n"
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
                msg +=  HIY "$n越听越入神，放弃了和$N的战斗，盘膝而坐倾听禅法之中的奥秘所在。\n" NOR;
		target->set_temp("no_move", 1);
	
		howlong = random((me->query_skill("spells") -100))+1;
		if(howlong>60) howlong=60;
		call_out("free", howlong, target);
	}	    
	else {
                msg +=  HIY "$n对了$N淡淡一笑，似乎听不懂对方叨叨了些什么！\n" NOR;   
		me->start_busy(1+random(2));        
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

