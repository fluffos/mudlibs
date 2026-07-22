//风回
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_perform(object me)
{
	if(me->query("family/family_name") != "月宫")
        	return notify_fail("「回风舞柳」是月宫不传之密！\n");
        if( me->query_level()<20 )
        	return notify_fail("你的人物等级不够。\n");
      	if((int)me->query_skill("snowsword", 1) <200)
		return notify_fail("你的回风雪舞剑法火候还不够！\n");
      	if(me->query_skill_mapped("force")!="moonforce")
		return notify_fail("「回风舞柳」必须配合圆月心法才能使用。\n");
     	if(me->query_skill("moonforce",1)<200) 
		return notify_fail("你的圆月心法不够纯熟。\n");
	if(me->query("force")<800)
        	return notify_fail("你内力不继，心有余而力不足。\n");
	return 1;	
}

int perform(object me, object target)
{
	string msg;
        int damage, ap, dp,qixue,eff_qi,max_qi,qi_pcg,qi,eff,need;

	if( !valid_perform(me) )
		return 0;
		
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || target->is_corpse()
         || !me->is_fighting(target) 
         || target==me)
		return notify_fail("你要打谁？\n");
	if(!target->is_killing(me->query("id")))
		return notify_fail("好端端的比武，何必性命相搏？\n");
	if( COMBAT_D->check_level(me,target)==-1 )
		return notify_fail("对方境界高出你甚多，使用此招纯属自杀所为。\n");        	
	if( wizardp(me) )
	{
		qi = 100;
		eff = 60;
		need = 100;
	}        	
	else if( me->query_level()<40 )
	{
		qi = 1;
		eff = 10;
		need = 50;
	}
	else if( me->query_level()<90 )
	{
		qi = 5;
		eff = 15;
		need = 51;
	}
	else if( me->query_level()<130 )
	{
		qi = 6;
		eff = 16;
		need = 52;
	}				
	else
	{
		qi = 10;
		eff = 20;
		need = 55;
	}
	qi+= me->is_knowing("moon_huifeng_qi");
	eff+= me->is_knowing("moon_huifeng_eff");
	need+= me->is_knowing("moon_huifeng_need");
	if( eff>80 ) eff = 80;
	if( need>90 ) need = 90;
	if( qi>me->query("kee") )
		qi = me->query("kee");
       	eff_qi=me->query("eff_kee");
       	max_qi=me->query_maxkee();
       	qi_pcg=eff_qi*100/max_qi;
       	if(qi_pcg>need) 
		return notify_fail("还未到山穷水尽的地步，不要胡乱出手。\n");
	
        me->set("kee",qi);
        me->set("eff_kee",eff_qi*random(eff)/100+1);
        me->set("sen",qi);
        me->set("eff_sen",me->query("eff_sen")*random(eff)/100+1);
        me->set("force",0);
        me->set("mana",0);

        msg = HIW"\n$N"HIW"眼见不敌，银牙一咬，突然高高纵起，凝聚全身功力，人剑合一，化做一道白光，疾风般扑向$n"HIW"！\n" NOR;
        message_vision(msg, me, target);
        ap = me->query_level();
        dp = target->query_level();
        if( random(ap + dp)<dp/3 ) 
		message_combatd(HIW "$n"HIW"一见情势不妙，连忙就地一滚，虽于千钧一发之际躲过雷霆一击，却也狼狈不堪，吓得魂飞魄散，一时间动弹不得。\n"NOR, me, target);
        else 
	{
		msg = HIW "$n"HIW"不料$N"HIW"如此决绝，为此气势所慑，竟然楞在当地，忘了招架。说时迟，那时快，这道白光已在$n"HIW"身上当胸穿过！\n"NOR;
		message_combatd(msg, me, target);
		target->receive_wound("kee",target->query_maxkee()+1,me,TYPE_COMBAT);
		COMBAT_D->report_status(target); 
	}
	me->start_busy(2+random(3));
	if( target && !target->is_busy() )
		target->start_busy(1+random(2));
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：回风舞柳
        外功所属：回风雪舞剑
        外功效果：不死不休的招式，以燃烧自身生命为代价，对敌发出必杀的一击
                  使用后自身busy 2-4 秒，敌方busy 1-2 秒 
                  不可对高出自身境界者使用
        外功条件：
        	  月宫弟子	
        	  人物等级20级
                  内力800点，施展后内力为0
                  风回雪舞剑 200 级
                  圆月心法   200 级
                  气血损失大于49%，随人物等级提高，此限制放宽
                  
STR;
        me->start_more(str);
        return 1;
}
