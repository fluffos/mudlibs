// Wuzhi.c 五指山
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{    
	int damage,succ,t;    
	string msg,succ_msg;        
	if( me->query_level()<50 )
		return notify_fail("你的人物等级不够。\n");
	if((int)me->query("force") < 800 )                     
        	return notify_fail("你的内力不足！\n");        
	if((int)me->query_skill("jienan-zhi", 1) < 500)         
        	return notify_fail("你的劫难指等级还不够!!\n");
	if(me->query("bonze/class")!="bonze" ) 
        	return notify_fail("你是哪儿偷学来的武功！\n");
		
	if( !target )
	        target = offensive_target(me);
	if( !target        
 	 || !target->is_character()        
 	 || target->is_corpse()        
 	 || target==me
 	 || !me->is_fighting(target) )
     		return notify_fail("你要对谁施展这一招「五指山」?\n");        

	msg = HIY"只听$N"HIY"垂眉凝目，双掌之上渐渐泛起金光，金光愈来愈强，映得$N"HIY"宝象庄严，";
	msg+= "$N"HIY"低声诵佛，单手一托，金光闪烁间化作一只金色大佛山，遮天蔽日压向$n"HIY"！\n"NOR;
	
	if( target->is_blind() )
	{
		succ_msg = HIR"但见$n"HIR"哇的一声,被佛掌压住，顿时浑身骨骼发出阵阵碎响，整个人给震得倒飞而出！\n"NOR;
		me->add("force",-200);
		me->set_temp("pfm_msg",1);
		damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,0,"kee");
		me->delete_temp("pfm_msg");
		me->start_busy(1);
	}
	else
	{
		message_vision(msg,me,target);
		me->add("force",-300);
		succ = COMBAT_D->attack_percent(me,target,TYPE_CAST);
		if( succ>0 )
		{
			message_combatd(HIR"“轰隆”一声巨响，$N"HIR"顿时被压在佛掌之下，动弹不得！\n"NOR,target,me);
			t = me->query_skill("unarmed")/100;
			if( t<3 )
				t = 3;
			if( t>10 )
				t = 10;
			target->start_busy(t);
			target->start_blind(t,HIY"你被"+me->name()+HIY"以五指山镇压住了！"NOR"\n");
			me->start_busy(1);
		}				
		else	
		{
			me->start_busy(3);
			message_combatd(HIY"可是$n"HIY"早有警觉，跳了开去，$P拳头落空。\n"NOR, me, target);
    		}
    	}
	return 1;
}

int help(object me)
{
string str;
if( !me )      return 0;
str = @LONG
        外功名称：五指山
        外功所属：劫难指法
        外功效果：对方如处于静默状态下，则造成对方气血损失
                  否则使对方处于静默状态3-10秒
                  失败则自身busy 3 秒
                  否则则自身busy 1 秒
        外功条件：
        	  人物等级50级
        	  佛门弟子
                  内力800点，消耗200-300点
                  劫难指法500级
LONG;
me->start_more(str);
return 1;
}

