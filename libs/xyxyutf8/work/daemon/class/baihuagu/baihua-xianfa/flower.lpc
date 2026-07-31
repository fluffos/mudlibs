#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{        
	string msg,succ_msg;	
	int success_adj, damage;
	success_adj = 20;      
	
	if( me->query_level()<50 )
        	return notify_fail("你的人物等级不够。\n");
	if((int)me->query("mana")<500 )               
        	return notify_fail("你的法力不够！\n"); 
	if((int)me->query("sen") < 300 )         
        	return notify_fail("你无法集中精力！\n");   
        if(me->query("family/family_name")!="百花谷")
        	return notify_fail("你召不了百花。\n");	
        if( me->query_skill("baihua-xianfa",1)<400 )
        	return notify_fail("你的百花仙法还不够纯熟。\n");
	if( time()<me->query_temp("bhg_flower")+5 )
		return notify_fail("绝招用多就不灵了。\n");
		        		   
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) ) 
        	return notify_fail("你要对谁施展百花飞舞？\n"); 

	me->add("mana", -300);
	me->receive_damage("sen",100,me);  
	if( random(me->query_maxmana())<150 ) 
        {              
        	write("好象没成功，再来一次吧！！\n");          
        	return 1;       
        }       
	damage = me->query_skill("spells")+me->query("mana_factor")/10;
	msg = HIM "$N"HIM"口中念了几句咒文，半空中无数"HIY"五"HIC"彩"HIG"鲜"HIW"花"HIM"迎风飞舞。花瓣片片飘落，如疾风骤雨箭般向$n"HIM"激射而下！\n"NOR;
	succ_msg = HIR "结果无数花瓣从$n"HIR"身上透体嵌入，顿时血花飞溅！\n"NOR;
	me->add_temp("apply/attack",success_adj);
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,damage);
	me->set_temp("pfm_msg",0);
	me->add_temp("apply/attack",-success_adj);
	if( damage<1 )
		message_combatd(HIM "但是$n"HIM"在千钧一发之际躲了开来。\n" NOR,me,target);
	me->set_temp("bhg_flower",time());		
	return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        法术名称：百花飞舞
        法术所属：百花仙法
        法术效果：召唤五彩鲜花对敌人进行精神的法术攻击
                  冷却 5 秒
        法术条件：
                  百花谷弟子
                  人物等级50级
                  法力500，消耗300点
                  精神300点，消耗100点
                  百花仙法400级
LONG;
me->start_more(str);
return 1;
}       
