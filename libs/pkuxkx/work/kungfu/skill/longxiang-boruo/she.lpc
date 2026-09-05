// 密宗 舍加持力：从世俗谛来说，上师、三宝通过这种加持让弟子生起舍心、布施的心。
// 首先从对自己最微不足道的东西开始舍，到最后舍弃自己的生命去布施；
// 从胜义谛来说，是能坏对立法，如悭吝、疑惑等、能证法无我智慧。
// lordstar 20180507

#include <ansi.h>
#include "jiachi.h";

void remove_effect(object me, string jiachi);

int exert(object me, object target)
{
        string msg, jiachi = "「舍加持力」";
		int inc, qi, effqi, maxqi, sk, skhxc, pflv, dur;
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

		if (pflv<4)
			return notify_fail("以你现在的密宗修为，还无力施展"+jiachi+"。\n");
		
		if (target != me)
			return notify_fail("你只能为自己加持"+jiachi+"。\n");
		
		if ((int)me->query_temp("mizong_jiachi_cd")> time())
			return notify_fail("你刚施展过一次密宗加持，还要过一段时间才能再次施展。\n");
		
		if (me->query_temp("mizong_jiachi/"+jiachi))
			return notify_fail("你已经加持了"+jiachi+"。\n");
		
		jc = all_jiachi(me);

		if (buff_full(pflv, jc))
			return notify_fail("你已经加持了"+show_buff(jc)+"，无法再加持"+jiachi+"。\n");
		
		if((int)me->query("neili") < 1000 )
			return notify_fail("你的真气不够。\n");
			
		sk = (int)me->query_skill("longxiang-boruo",1);
        if(sk < 800)
			return notify_fail("你的龙象般若功修为太低了，无法加持"+jiachi+"。\n");

		skhxc = (int)me->query_skill("huanxi-chan",1);
        if(skhxc < 500)
			return notify_fail("你的欢喜禅修为太低了，无法加持"+jiachi+"。\n");
	
        me->start_busy(random(2));
		msg = MAG"只见$N面相庄严，二手内相叉，直竖二头指相并，以二中指缠二头指初节前，各头相拄，\n"
			+ "二大指并申直，结印念诵" YEL "大日如来咒" MAG "密语，为自己加持了" HIC +jiachi+ NOR + MAG"！\n\n"NOR;

		if (skhxc>=3000) inc=75;
		else inc = (75-10)*(skhxc-500)/(3000-500)+10; // inc最低10，最高75（3000级欢喜禅）
		
		message_vision(msg, me);
		dur=sk/50;
		maxqi = me->query("max_qi") * inc / 100;
		effqi = me->query("eff_qi") - (me->query("max_qi") - maxqi);
		if (effqi<0) effqi=0;
		qi = me->query("qi") - (me->query("eff_qi") - effqi);
		if (qi<0) qi=0;
		
		me->add("qi", -qi);
		me->add("eff_qi", -effqi);
		me->add("max_qi", -maxqi);
		me->add_temp("apply/max_qi", -maxqi);
	    me->set_temp("active_debuff/huanxi-chan.she/name", "舍加持力");                 //buff名称
		me->set_temp("active_debuff/huanxi-chan.she/last_time", time() + dur );        //持续时间
		me->set_temp("active_debuff/huanxi-chan.she/effect1", "最大生命值-"+maxqi);  //效果描述1   
		
		inc = inc*2;
		me->set_temp("mizong_jiachi/"+jiachi+"/inc", inc);
		me->set_temp("mizong_jiachi/"+jiachi+"/maxqi", maxqi);
		me->set_temp("mizong_jiachi/"+jiachi+"/effqi", effqi);
		me->set_temp("mizong_jiachi/"+jiachi+"/qi", qi);
		
		me->add_temp("apply/kf_wound", inc);
		me->add_temp("apply/deep_injure", inc);
		me->add_temp("apply/kf_hit_rate", 1); // 提高化学命中1个小级，约等于5%
		me->add_temp("apply/attack_factor", 5); // 提高物理命中 5%
	    me->set_temp("active_force_buffer/huanxi-chan.she/name", "舍加持力");                 //buff名称
		me->set_temp("active_force_buffer/huanxi-chan.she/last_time", time() + dur );        //持续时间
		me->set_temp("active_force_buffer/huanxi-chan.she/effect1", "物理伤害+"+inc+"%");  //效果描述1   
		me->set_temp("active_force_buffer/huanxi-chan.she/effect2", "化学伤害+"+inc+"%");   //效果描述2   
		me->set_temp("active_force_buffer/huanxi-chan.she/effect3", "命中率+5%");         //效果描述2   

        call_out("remove_effect", dur, me, jiachi);
        me->add("neili", -200);
		me->set_temp("mizong_jiachi_cd", time() + 30);
        return 1;
}

void remove_effect(object me, string jiachi)
{
	int inc, qi, maxqi, effqi;
	if( !objectp(me) || !me->query_temp("mizong_jiachi/"+jiachi))
		return;
	inc = me->query_temp("mizong_jiachi/"+jiachi+"/inc");
	maxqi = me->query_temp("mizong_jiachi/"+jiachi+"/maxqi");
	effqi = me->query_temp("mizong_jiachi/"+jiachi+"/effqi");
	qi = me->query_temp("mizong_jiachi/"+jiachi+"/qi");
	
	me->add_temp("apply/kf_wound", -inc);
	me->add_temp("apply/deep_injure", -inc);
	me->add_temp("apply/kf_hit_rate", -1);
	me->add_temp("apply/attack_factor", -5);
	
	me->add_temp("apply/max_qi", maxqi);
	me->add("max_qi", maxqi);
	me->add("eff_qi", effqi);
	me->add("qi", qi);
	
	me->delete_temp("mizong_jiachi/"+jiachi);
	me->delete_temp("active_force_buffer/huanxi-chan.she");
	me->delete_temp("active_debuff/huanxi-chan.she");
	message_vision(HIY"$N身上凝聚的「舍加持力」逐渐消散了。\n"NOR, me);
}
