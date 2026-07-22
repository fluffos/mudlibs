// fu by yushu 2000.11
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	object seal;
	string msg,succ_msg;
	int t,succ;
	
	if( me->query_level()<40 )
		return notify_fail("你的人物等级不够。\n");      
	if(me->query("family/family_name")!="蜀山派")
        	return notify_fail("你不是蜀山弟子，不能使用这项技能！\n");
        if((int)me->query("mana") < 800 )
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 200 )
                return notify_fail("你无法集中精力！\n");
	if((int)me->query_skill("tianshi-fufa", 1) <400)
		return notify_fail("你的天师符法不够娴熟。\n");
			
	seal = present("paper seal",me);
	if( !seal || base_name(seal)!="/obj/paper_seal" )
		return notify_fail("你身上没有桃符纸，如何施「禁咒封」？\n");		
        if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) ) 
                return notify_fail("你要对谁施「禁咒封」？\n");
	if( target->is_blind() )
		return notify_fail("对方已经被封印住了。\n");
	if( time()<target->query_temp("shushan_feng")+5 )
		return notify_fail("你不能对其频繁使用「禁咒封」。\n");

		
        me->add("mana", -300);
        me->receive_damage("sen", 100);
        if( random(me->query_maxmana()) < 50 ) {
                write("你一着急竟然忘了咒语。\n");
                return 1;
        }
        if( seal->query_amount()<1 )
        	destruct(seal);
        else	seal->add_amount(-1);	
        
        t = me->query_skill("spells")/100+1;
	//符水	符类法术伤害+5%
	if( me->query_skill("fushui",2)>100 )
		t+= (me->query_skill("fushui",1)-100)/200+1;
        succ = COMBAT_D->attack_percent(me,target,TYPE_CAST);
        
        msg = HIC "\n$N"HIC"一脸肃杀之气，抬手仍出一张天师符「呼」地一下飞到半空，射向$n"HIC"！\n" NOR;
	succ_msg = HIR "一道纵横交错，古朴繁杂的符文顿时凌空而现，$n"HIR"被符文笼罩正中，顿时六神无主，浑浑噩噩！\n"NOR;
	message_vision(msg,me,target);
	me->receive_damage("sen",100,me);
	if( succ>0 )
	{
		message_combatd(succ_msg,me,target);
		target->start_blind(t,HIR"\n你被"+me->name()+HIR"以蜀山符法封印住了。"NOR"\n你现在六神无主。\n");
		target->set_temp("shushan_feng",time()+t);
		me->start_busy(1);
	}	
	else
	{
		message_combatd(HIC"但是$n"HIC"伸指一弹，红光一暗，结果扑！地一声天师符凭空化去！\n"NOR,me,target);
		me->start_busy(2);
	}
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：禁咒封
        法术所属：天师符法
        法术效果：祭天师符使对方陷入静默状态
                  自身busy 1 秒，若失败则自身busy 2 秒
                  不可对静默状态下的对象使用
        法术条件：
        	  人物等级40级
        	  需要桃符纸
                  法力800点，消耗300点
                  精神200点，消耗100点
                  天师符法400级
STR;
        me->start_more(str);
        return 1;
}
