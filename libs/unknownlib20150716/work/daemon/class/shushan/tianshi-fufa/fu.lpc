// fu by yushu 2000.11
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	int p,damage;
	object seal;
	string msg,succ_msg;
	
	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");      
	if(me->query("family/family_name")!="蜀山派")
        	return notify_fail("你不是蜀山弟子，不能使用这项技能！\n");
        if((int)me->query("mana") < 200 )
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你无法集中精力！\n");
	if((int)me->query_skill("tianshi-fufa", 1) < 150)
		return notify_fail("你的天师符法不够娴熟。\n");
	if( time()<me->query_temp("shushan_fu")+3 )
		return notify_fail("你不能频繁使用天师符。\n");
			
	seal = present("paper seal",me);
	if( !seal || base_name(seal)!="/obj/paper_seal" )
		return notify_fail("你身上没有桃符纸，如何施天师符？\n");		
        if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) ) 
                return notify_fail("你要对谁施天师符法？\n");

        me->add("mana", -100);
        me->receive_damage("sen", 100);
        if( random(me->query_maxmana()) < 50 ) {
                write("你一着急竟然忘了咒语。\n");
                return 1;
        }
        if( seal->query_amount()<1 )
        	destruct(seal);
        else	seal->add_amount(-1);	
        damage = 100;
        damage+= ((int)me->query_skill("tianshi-fufa", 1)-150)/50;
        //符水	符类法术伤害+5%
	if( me->query_skill("fushui",2)>100 )
	{
		p = (me->query_skill("fushui",1)-100)/150+5;
		damage = damage*(100+p)/100;
	}
        msg = HIC "\n$N"HIC"一脸肃杀之气，抬手仍出一张天师符「呼」地一下飞到半空，射向$n"HIC"！\n" NOR;
	succ_msg = HIR "$n"HIR"被光影罩住，波的喷出一口鲜血！\n" NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,damage,"kee");
	me->set_temp("pfm_msg",0);
	me->set_temp("shushan_fu",time());
	if( damage<1 )
		message_combatd(HIR"但是$n"HIR"伸指一弹，红光一暗，结果扑！地一声天师符凭空化去！\n"NOR,me,target);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：天师符
        法术所属：天师符法
        法术效果：带固定伤害的法术伤害
        	  使对方气血减少
                  冷却时间 3 秒
        法术条件：
                  蜀山派弟子
        	  人物等级15级
        	  需要桃符纸
                  法力200点，消耗100点
                  精神100点，消耗100点
                  天师符法150级
STR;
        me->start_more(str);
        return 1;
}
