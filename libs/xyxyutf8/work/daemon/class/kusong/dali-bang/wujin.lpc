//妖云无尽 wujin.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	
	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");
        if(me->query("family/family_name")!="火云洞" 
        && me->query("chushi/chushi_kusong")!="yes")
                return notify_fail("你不能使用这项技能！\n");
	if((int)me->query("force") < 300 )
		return notify_fail("你的内力不足！\n");
        if((int)me->query("kee") < 200 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
	if((int)me->query_skill("dali-bang", 1) < 300)
        	return notify_fail("你的大力棒法级别还不够，使用这一招会有困难！\n");
        if((int)me->query_skill("huomoforce",1) < 300)
		return notify_fail("你的火魔心法级别还不够，使用这一招会有困难！\n");
        	
	if( time()<me->query_temp("kusong_wujin")+6 )
		return notify_fail("你刚刚施展过妖云，还是歇歇再说。\n");
		        		
	weapon = me->query_temp("weapon");
	if( !weapon 
	 || ( weapon->query("skill_type")!="stick" && weapon->query("use_apply_skill")!="stick" )
	 || me->query_skill_mapped("stick") != "dali-bang" )
	 	return notify_fail("你的大力棒法还不够娴熟。\n");	
	 	
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
                return notify_fail("你要对谁施展这一招「妖云无尽」？\n");
	
	message_vision(HIY"$N"HIY"大吼一声，犹如晴天霹雳，猛的祭出了大力棒的杀手绝学「妖云无尽」！\n"NOR,me,target);
        me->receive_damage("kee",100);
        me->add("force", -100);
	me->set_temp("kusong_wujin",time());
	
        me->set_temp("WJ_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,10);

        me->set_temp("WJ_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,20);

        me->set_temp("WJ_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,30);

        me->set_temp("WJ_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,40);
	
	me->delete_temp("WJ_perform");

        if( !target->is_killing(me->query("id")) )
        	target->kill_ob(me);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：妖云无尽
        外功所属：大力棒
        外功效果：连续攻击对方四次，造成对方气血后限减少
                  冷却时间6秒
        外功条件：
        	  火云洞(出师)弟子
        	  人物等级30级	
        	  内力300点，消耗100点
        	  气血200点，消耗100点
                  大力棒 300 级
                  火魔心法 300 级
STR;
        me->start_more(str);
        return 1;
}
