// sheshen.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string succ_msg,msg;
	int damage,ap,dp,t;

	if( !target ) 
    		target = offensive_target(me);        
	if( !target        
 	 || !target->is_character()        
 	 || target->is_corpse()        
 	 || !me->is_fighting(target) )                
     		return notify_fail("你要对谁施展这一招『舍身喂鹰』？\n"); 
	if( me->query_level()<35 )
		return notify_fail("你的人物等级过低。\n");
	if( !me->query_skill_mapped("spells")
	 || me->query_skill_mapped("spells") != "buddhism" )
        	return notify_fail("『舍身喂鹰』需要『大乘佛法』的配合！\n");
	if((int)me->query("force") < 800 )                  
        	return notify_fail("你体内的内力不足！\n");        
	if((int)me->query_skill("cibeidao",1) < 350)          
        	return notify_fail("你的『慈 悲 刀』等级不够！\n");
	if((int)me->query_skill("lotusforce",1) < 350)          
		return notify_fail("你的『莲花心法』等级不够！\n");
	if( time()<me->query_temp("putuo_sheshen")+5 )
		return notify_fail("你刚刚发过佛唱，还是休息休息。\n");
		
	msg = HIY"$N"HIY"面带悲悯之色，佛唱声中，一式『舍身喂鹰』夹带着一股佛家慈悲之气，直冲$n"HIY"$l！\n"NOR;
	succ_msg = HIC"$n"HIC"被慈悲之气所感，顿觉手中杀戮过多，不由放缓了攻势。\n"NOR;
	me->set_temp("pfm_msg",1);
	me->set_temp("putuo_sheshen",time());
	me->add("force",-100);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	if( damage>0 )
	{
		if( !target->is_busy() )
			target->start_busy(1+random(2));
		if( target->query("bellicosity")>10 )
			target->add("bellicosity",-10);
		else	target->set("bellicosity",0);
		if( !target->is_hunluan() )
		{
			ap = me->query_skill("buddhism",1)/10;
			dp = target->query_skill("spells",1)/10;
			if( random(ap+dp)>=dp/2 )
			{
				t = me->query("spells")/10;
				if( t>30 )
					t = 30;	
				target->start_hunluan(t,HIY"你被"+me->name()+HIY"的慈悲之气所感，觉得自己杀戮过多，顿生悔意。\n"NOR);
			}
		}
	}
	else
	{
		message_combatd(HIC"$N"HIC"哈哈大笑一声：秃驴，这些蛊惑人心旁门之技能耐我何？！\n"NOR,target);
		me->start_busy(1+random(2));
	}
	return 1;
}

int help(object me)
{
string str;
if( !me )      return 0;       
str = @LONG
        外功名称：舍身喂鹰
        外功所属：慈悲刀法
        外功效果：将刀上附加慈悲之气，对敌一击。
        	  如命中，则对方busy 1-2 秒，杀气减10，
        	  否则自身busy 1-2秒
        	  如领悟慈悲刀法真谛，会使对方一定时间内陷入混乱
                  使完冷却 5 秒
        外功条件：
        	  人物等级35级
        	  基本法术激发大乘佛法
                  内力800点，消耗100点
                  慈悲刀法350级
                  莲台心法350级
LONG;
me->start_more(str);
return 1;
}
