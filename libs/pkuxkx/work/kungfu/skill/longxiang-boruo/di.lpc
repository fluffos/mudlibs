// 密宗 谛加持力：谛加持力是真实有、自性有。从世间法，即世俗谛来说，这种加持可以让弟子违缘减少、顺缘增上。
// 从出世间法，即胜义谛来说，上师、三宝对弟子身、口、意的加持，可以使弟子们获得真正的解脱与成就。
// 佛陀和像佛陀一样的大成就者对弟子的加持就是谛加持。
// lordstar 20180507

#include <ansi.h>
#include "jiachi.h";

void remove_effect(object me, string jiachi);

int exert(object me, object target)
{
        string msg, jiachi = "「谛加持力」";
		int i, inc, sk, skhxc, pflv, dur;
		string* jc;
		
		if (!objectp(target))
			target = me;
			
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "大轮寺")  pflv=0;
		if (pflv>5) pflv=5;
		
		if (pflv<=0)
			return notify_fail("在得到本门密传之前，你还无力施展任何加持力。\n");
		
		if (target != me && pflv<5)
			return notify_fail("以你现在的密宗修为，还无力为他人加持。\n");
		
		if ((int)me->query_temp("mizong_jiachi_cd")> time())
			return notify_fail("你刚施展过一次密宗加持，还要过一段时间才能再次施展。\n");
		
		if (target->query_temp("mizong_jiachi/"+jiachi))
			return notify_fail((target==me?"你":target->query("name"))+"已经加持了"+jiachi+"。\n");
		
		jc = all_jiachi(target);

		if (target==me)
		{
			if (buff_full(pflv, jc))
				return notify_fail("你已经加持了"+show_buff(jc)+"，无法再加持"+jiachi+"。\n");
		}
		else
		{
			if (sizeof(jc)>0)
				return notify_fail(target->query("name")+"已经加持了"+show_buff(jc)+"，无法再加持"+jiachi+"。\n");
			if (target->query("combat_exp") < me->query("combat_exp")/2)
				return notify_fail(target->query("name")+"实在是太弱小了，承受不起你的强大加持。\n");
			if ((int)target->query_temp("mizong_jiachi_by_other")> time())
				return notify_fail(target->query("name")+"刚刚承受过一次加持，还要过一段时间才能再次施以加持。\n");
		}
		
		if((int)me->query("neili") < 1000 )
			return notify_fail("你的真气不够。\n");
			
		sk = (int)me->query_skill("longxiang-boruo",1);
        if(sk < 500)
			return notify_fail("你的龙象般若功修为太低了，无法加持"+jiachi+"。\n");

		skhxc = (int)me->query_skill("huanxi-chan",1);
        if(skhxc < 500)
			return notify_fail("你的欢喜禅修为太低了，无法加持"+jiachi+"。\n");
	
        me->start_busy(2);
		msg = MAG"只见$N面相庄严，二手内相叉，直竖二头指相并，以二中指缠二头指初节前，各头相拄，\n"
			+ "二大指并申直，结印念诵" YEL "大日如来咒" MAG "密语，为"+(target==me?"自己": WHT"$n"MAG)+"加持了" HIC +jiachi+ NOR + MAG"！\n\n"NOR;
		inc = 0;
		i = 8;
		while (skhxc>0)
		{
			if (skhxc > 400)
				inc += 400/i;
			else
				inc += skhxc/i;
			skhxc -= 400;
			i += 1;
		}

		if (target == me) 
		{
			message_vision(msg, me);
			dur=sk/5;
		}
		else 
		{
			message_vision(msg, me, target);
			dur=sk/10;
			inc/=2;
			target->set_temp("mizong_jiachi_by_other", time() + 600);
		}
		
		target->set_temp("mizong_jiachi/"+jiachi+"/inc", inc);
		target->add_temp("apply/magic", inc);
		target->add_temp("apply/neili_recover", inc);
	    target->set_temp("active_force_buffer/huanxi-chan.di/name", "谛加持力");                       //buff名称
		target->set_temp("active_force_buffer/huanxi-chan.di/last_time", time() + dur );              //持续时间
		target->set_temp("active_force_buffer/huanxi-chan.di/effect1", "内力恢复+"+inc+"点");         //效果描述1   
		target->set_temp("active_force_buffer/huanxi-chan.di/effect2", "幸运值+"+inc+"点");         //效果描述2   
		
        me->add("neili", -200);
		me->set_temp("mizong_jiachi_cd", time() + 30);
		
        call_out("remove_effect", dur, target, jiachi);
        return 1;
}

void remove_effect(object me, string jiachi)
{
	int inc;
	if( !objectp(me) || !me->query_temp("mizong_jiachi/"+jiachi))
		return;
	inc = me->query_temp("mizong_jiachi/"+jiachi+"/inc");
	
	me->add_temp("apply/magic", -inc);
	me->add_temp("apply/neili_recover", -inc);
	
	me->delete_temp("mizong_jiachi/"+jiachi);
	me->delete_temp("active_force_buffer/huanxi-chan.di");
	message_vision(HIY"$N身上凝聚的「谛加持力」逐渐消散了。\n"NOR, me);
}
