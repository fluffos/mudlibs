#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg,succ_msg;
        int damage,p;

	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="盘丝洞")
        	return notify_fail("只有盘丝洞门人才可以用这项技能！\n");
	if((int)me->query_skill("chixin-jian", 1) <150)
        	return notify_fail("你的痴心情长剑火候还不够！\n");
	if((int)me->query_skill("pansi-dafa", 1) <120)
        	return notify_fail("你的盘丝大法修为太低！\n");
	if(me->query_skill_mapped("spells")!="pansi-dafa")
		return notify_fail("你不用盘丝大法怎么化蝶?\n");
	if( me->query_skill("jiuyin-xinjing",1)<120 )  
		return notify_fail("你的九阴心经不够纯熟。\n");
	if( (string) me->query_skill_mapped("sword") != "chixin-jian")
		return notify_fail("只有靠痴心情长剑剑意才能化蝶。\n");	
	if( time()<me->query_temp("psd_huadie")+5 )
		return notify_fail("是谁伤了你的心，让你如此心灰意冷？\n");
	if( me->query("force")<500 )			
		return notify_fail("你内力无以为继。\n");
		
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你有敌人吗？\n");
	
	msg = "\n                      "HBCYN HIM"╭ "HIY"一切恩爱会，无常难得久"HIM" ╮"NOR"\n";
	msg+= "                      "HBYEL HIM"│ "HIY"生世多畏惧，命危于晨露"HIM" │"NOR"\n";
	msg+= "                      "HBGRN HIM"│ "HIY"由爱故生忧，由爱故生怖"HIM" │"NOR"\n";
	msg+= "                      "HBBLU HIM"╰ "HIY"若离于爱者，无忧亦无怖"HIM" ╯"NOR"\n";
	message_combatd(msg,me,target);
	me->add("force",-200);
	me->set_temp("psd_huadie",time());
		
	msg = HIR"$N"HIR"叹道:“是耶？非耶？化作蝴蝶......”忽然招式一变，$w"HIR"舞起一片剑花,似彩蝶翻飞般罩向$n"HIR"！\n"NOR;
	succ_msg = HIM"$n"HIM"躲闪不及,剑花中但见两只彩蝶穿身而过！\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,0,me->query_skill("sword")/2);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		message_combatd(HIW "$n"HIW"一见情势不妙，一个鱼跃,跳出圈外。\n"NOR, me, target);
		return 1;
	}
	if( random(me->query_per())>target->query("per") )
	{
		target->receive_wound("kee",damage/2+1,me,TYPE_PERFORM);
		COMBAT_D->report_status(target,1);
	}	
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：化蝶
        外功所属：痴心情长剑
        外功效果：对敌进行一次物理攻击
                  有一定几率追加打击对方气血后限
                  冷却时间 5 秒
        外功条件：
                  盘丝洞弟子
        	  人物等级15级
                  内力500点，消耗200点
                  痴心情长剑150级并激发
                  盘丝大法120级并激发
                  九阴心经120级并激发
STR;
        me->start_more(str);
        return 1;
}
