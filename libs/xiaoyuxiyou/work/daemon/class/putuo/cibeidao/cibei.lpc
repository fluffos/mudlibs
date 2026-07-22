// cibei.c
// Modify by Jingxue for XYCQ 9.29.2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg ,spskill;
	int skill,extra,ap,dp;

	if( !target ) 
    		target = offensive_target(me);        
	if( !target        
 	 || !target->is_character()        
 	 || target->is_corpse()        
 	 || !me->is_fighting(target) )                
     		return notify_fail("你要对谁施展这一招『慈悲双刀』？\n"); 
	if( me->query_level()<10 )
		return notify_fail("你的人物等级过低。\n");
		
	skill = (int)me->query_skill("cibeidao",1)+(int)me->query_skill("buddhism",1)+(int)me->query_skill("lotusforce",1);
	extra = skill/15;
	spskill = (string) me->query_skill_mapped("spells");
	if( !spskill || spskill != "buddhism")
        	return notify_fail("『慈悲双刀』需要『大乘佛法』的配合！\n");
	if((int)me->query_maxforce() < 800)                
        	return notify_fail("你的内力修为火候不够！\n");           
	if((int)me->query("force") < 400 )                  
        	return notify_fail("你体内的内力不足！\n");        
	if((int)me->query_skill("cibeidao",1) < 80)          
        	return notify_fail("你的『慈 悲 刀』等级不够！\n");
	if((int)me->query_skill("lotusforce",1) < 80)          
		return notify_fail("你的『莲花心法』等级不够！\n");
	if( time()<(me->query_temp("putuo_cibei")+5) )
    		return notify_fail("绝招用多就不灵了。\n");
    		
	me->add_temp("apply/attack",extra);
	me->add("force", -50);
	weapon = me->query_temp("weapon");
	message_vision(HIG"\n$N"HIG"高宣“我佛慈悲！渡世渡人！”，使出"HIY"『--慈--悲--字--诀--』"HIG"，内力返照空明，功力精纯。手中"+weapon->name()+HIG"一扬，带动无数风沙，呼啸而出。\n"NOR, me, target);
	me->set_temp("putuo_cibei",time());
	
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,HIC"慈\n"NOR,0,0,150);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,HIW"悲\n"NOR,0,0,150);
	
	if( me->query_skill("cibeidao",1)>=160 && me->query("force")>100 )
	{
		me->add("force", -50);	
    		msg = HIG"\n$N"HIG"口中高宣佛号，手中$w"HIG"滚动飞舞，宛若念珠乱颤，自上而下劈向$n"HIG"，接着手腕一抖，便如如来降魔似，急升而上，又往$n"HIG"$l扑到。\n"NOR;
        	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,160);
	}       

	if( me->query_skill("cibeidao",1)>=240 && me->query("force")>100 )
	{       
		me->add("force", -50);
    		msg = HIR"\n$N"HIR"高宣“阿弥陀佛！”，手中$w"HIR"一扬，向$n"HIR"的$l点去，刀头未到，刀上所挟劲风犹如红日当空，令对方一阵气窒，只听见「喀喀」几声巨响，刀头昂起，便如一条假死的毒蛇忽地反噬挥动，带动无数风沙，呼啸而出。\n"NOR;
        	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,170);
	}

	if( me->query_skill("cibeidao",1)>=320 && me->query("force")>100 )          
	{                       
		me->add("force", -50);
    		msg = HIW"\n$N"HIW"又宣“我佛慈悲！”，内力返照空明，不露棱角，手中$w"HIW"舞动时瞧不见半点影子无声无息，似缓实急，却又大开大阔，如天神，说不尽的莫测高深。\n"NOR;
        	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,180);
	}
	me->add_temp("apply/attack",-extra);
	return 1;
}

int help(object me)
{
string str;
if( !me )      return 0;       
str = @LONG
        外功名称：慈悲双刀
        外功所属：慈悲刀法
        外功效果：短时间内提升自身的命中率，并对敌进行连续两次带固定伤害的攻击
                  慈悲刀法每80级增加一击，固定伤害递增，共5连击
                  每追加一击，内力消耗增加50点
                  冷却时间 5 秒
        外功条件：
        	  人物等级10级	
                  内力修为八年
                  内力400点，消耗50点
                  慈悲刀法80级
                  莲台心法80级
LONG;
me->start_more(str);
return 1;
}
