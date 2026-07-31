// 夺命七剑 Duoming.c
// Cracked by Roath
// Last updated By 凌惊雪 12.15.2002
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,i,damage;
	object weapon;
	
	if( me->query_level()<60 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query("family/family_name")!="陷空山无底洞" 
         && me->query("chushi/chushi_wdd")!="yes" )
		return notify_fail("你不能使用这项技能！\n");
	
	extra = me->query_skill("qixiu-jian",1);
	if( extra <600 
	 || me->query_skill_mapped("sword")!="qixiu-jian" )
    		return notify_fail("你的「七修剑」还不够纯熟！\n");
	extra = me->query_skill("huntian-qigong",1);
	if( extra < 600) 
        	return notify_fail("你的「混天气功」还不够纯熟，无法发挥七修剑的威力！\n");
	if( !target ) target = offensive_target(me);
	if( !target || target->is_ghost() 
	 || !target->is_character() || me==target
	 || !me->is_fighting(target) )
     		return notify_fail("「夺命七剑」只能对战斗中的对手使用。\n");
	if( !objectp(weapon = me->query_temp("weapon"))
	 || weapon->query("skill_type")!="sword" )
		return notify_fail("「夺命七剑」是剑法精要。\n");
	if( time()<me->query_temp("wdd_duoming")+8 )
		return notify_fail("你不能频繁使用此招。\n");
	
		
	msg = HIR"\n$N"HIR"狂性大发，手中的"+ weapon->name()+  HIR"舞动如风，狂风暴雨般地向$n"HIR"袭来！\n" NOR;
	message_vision(msg,me,target);
	me->set_temp("wdd_duoming",time());
	
	extra = me->query_skill("sword")/200;
	extra+= random(me->query_cor()/10);
	
	me->add_temp("apply/attack",extra);
	i = 0;
	msg = HIR"$N"HIR"面带煞气，手中$w"HIR"疯狂攻向$n"HIR"的$l！\n"NOR;
	me->set_temp("pfm_color","HIR");
	me->set_temp("pfm_msg",1);
	
	damage = me->query_skill("qixiu-jian",1)/2;
	damage = COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK,msg,0,0,0,damage);
	if( damage>0 )
		i++;
	
	damage = me->query_skill("qixiu-jian",1);	
	damage = COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK,msg,0,0,0,damage);
	if( damage>0 )
		i++;
	
	damage = me->query_skill("qixiu-jian",1)*3/2;
	damage = COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK,msg,0,0,0,damage);
	if( damage>0 )
		i++;
	
	damage = me->query_skill("qixiu-jian",1)*4/3;
	damage = COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK,msg,0,0,0,damage);
	if( damage>0 )
		i++;
	
	damage = me->query_skill("qixiu-jian",1)*5/4;
	damage = COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,0,damage);
	if( damage>0 )
		i++;

	damage = me->query_skill("qixiu-jian",1)*8/7;
	damage = COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,0,damage);
	if( damage>0 )
		i++;
	
	damage = me->query_skill("qixiu-jian",1)*10/9;
	damage = COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,0,damage);
	if( damage>0 )
		i++;
	
	me->delete_temp("pfm_color");
	me->delete_temp("pfm_msg");
	
	if( i>5 && me && target )
		message_vision(HIR"\n$N"HIR"身中"+chinese_number(i)+"剑，顿时全身好似被刺成了筛子般，血如泉涌！\n\n"NOR,target);
	
	return 1;
}

int help(object me)
{
string str;
if( !me )      return 0;
str = @LONG
              外功名称：夺命七剑
              外功所属：七修剑法 
              外功效果：对敌连续攻击七次，固定伤害递增
              	        冷却时间 8 秒
              外功条件：
              		无底洞(出师)弟子
              		人物等级60级
              		七修剑法600级并激发
              		混天气功600级
LONG;
me->start_more(str);
return 1;
}
